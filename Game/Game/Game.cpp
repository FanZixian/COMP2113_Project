#include<iostream>
#include<string>
#include<vector>
#include "Troops.h"
#include "Headquarter.h"
#include "Technology.h"
#include "Resources.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
#include "Page4.h"
#include "Page5.h"
#include "IPage.h"
#include"Landship.h"
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include <ctype.h>
#include <fstream>
using namespace std;

bool Bossdefeated = false;//Checking when to end the game

bool checkcoin(int coinneeded, int coinhave) {
	if (coinneeded > coinhave) {

		return false;
	}
	else {
		//cout << "You have enough coin to do so" << endl;
		return true;
	}
}
//Check when using the coin(check if the coin is sufficient)

bool checkspace(int troopspacetaken, int spaceleft) {
	if (troopspacetaken > spaceleft) {
		return false;
	}
	else {
		cout << "You have enough space to do so" << endl;
	}
	return true;
}
//check if the space is enough when training troop

void spaceleft(vector<int> troop, int& spaceleft) {

	for (int i = 0; i < troop.size(); i++) {
		spaceleft = spaceleft - troop[i];
	}

}
//check for space left


void askfornewpage() {
	cout << "Please input a number to jump to the corresponding page :" << endl;
	cout << "Page 1 is to upgrade the headquarter and the landship" << endl;
	cout << "Page 2 is the information page of troops" << endl;
	cout << "Page 3 is the information page of technologies" << endl;
	cout << "Page 4 provides landship and you can modify your troop for the next battle" << endl;
	cout << "Page 5 shows the enemy to attack" << endl;
	cout << "________________________________________________________________________________" << endl;
}
//Print information of each page to let the player choose

void checkdefeat()
{
	if (R1.GoldCoins < 50 * (Hlevel * Hlevel - Hlevel + 1) && Bossdefeated == false) {
		cout << endl;
		cout << "Sorry, you lose the whole game!" << endl;
		exit(0);
	}
}
//Check whenever the player spend his goldcoin, if his gc after spent is less than the cost of searching enemy, he will lose



int main() {
	Defensive D1;
	D1.S.HP = 500;
	D1.S.attackpower = 50;


	Defensive D2;
	D2.S.HP = 700;
	D2.S.attackpower = 70;

	Defensive D3;
	D3.S.HP = 1000;
	D3.S.attackpower = 100;
	D3.M.HP = 1200;
	D3.M.attackpower = 20;

	Defensive D4;
	D4.S.HP = 1200;
	D4.S.attackpower = 120;
	D4.M.HP = 1500;
	D4.M.attackpower = 50;

	Defensive D5;
	D5.S.HP = 1500;
	D5.S.attackpower = 200;
	D5.M.HP = 1600;
	D5.M.attackpower = 80;
	D5.R.HP = 1800;
	D5.R.attackpower = 20;

	Defensive D6;
	D6.S.HP = 1600;
	D6.S.attackpower = 250;
	D6.M.HP = 1800;
	D6.M.attackpower = 100;
	D6.R.HP = 2000;
	D6.R.attackpower = 60;

	Defensive Boss;
	Boss.S.HP = 2000;
	Boss.S.attackpower = 300;
	Boss.M.HP = 2000;
	Boss.M.attackpower = 150;
	Boss.R.HP = 2500;
	Boss.R.attackpower = 80;

	cout << "Do you want to open the storage? (Y/N)" << endl;
	string Y;
	cin >> Y;

	ifstream fin;
	if (Y == "Y") {
		fin.open("data.txt");
		if (fin.fail()) {
			cout << "You do not have a storage" << endl;
		}
		else {
			cout << "You have a storage" << endl;
			//Headquarter level
			fin >> Hlevel;

			//Resources
			fin >> R1.GoldCoins;
			fin >> R1.Steel;

			//Landship
			fin >> LSlevel;

			//Troop
			fin >> InfLevel;
			fin >> HWGLevel;
			fin >> TKLevel;
			fin >> HCLevel;

			//Technology
			fin >> MLevel;
			fin >> MMLevel;
			fin.close();
		}

	}
	else if (Y == "N") {
	}

	cout << "Here the game begins (Please count Y)" << endl;
	cin >> Y;
	cout << "\033[2J\033[1;1H";


	PrintInitialPage();
	cout << "Please input a number to jump to the corresponding page :" << endl;
	cout << "Page 1 is to upgrade the headquarter and the landship" << endl;
	cout << "Page 2 is the information page of troops" << endl;
	cout << "Page 3 is the information page of technologies" << endl;
	cout << "Page 4 provides landship and you can modify your troop for the next battle" << endl;
	cout << "Page 5 shows the enemy to attack" << endl;
	cout << "Cout 6 to store your game and leave the game" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "Your input is :" << endl;

	//Initialize the troops array
	//Infantry number will occupy the 0 entry
	//Heavyweaponsguy number will occupy the 1 entry
	//Tank number will occupy the 2 entry
	//Helicopter number will occupy the 3 entry
	vector<int> troop;
	troop.push_back(0);
	// For adding the troop type if we have a storage
	for (int i = 1; i <= 6; i++) {
		if (Hlevel == 3) {
			troop.push_back(0);
		}
		if (Hlevel == 4) {
			troop.push_back(0);
		}
		if (Hlevel == 6) {
			troop.push_back(0);
		}
	}
	int spaceleft = LS[LSlevel - 1].Space;
	srand(time(NULL));


	char input1;
	cin >> input1;
	while (Bossdefeated != true) {
		if (input1 == 49)//49 is the ascii code for number 1, below are the code when the player input 1
		{
			cout << "\033[2J\033[1;1H";//To clear the screen
			PrintPage1();
			string judge;// Judge whether to improve the headquarter or the landship
			cout << "Do you want to upgrade your Headquarter or Landship? (Y/N)" << endl;
			cin >> judge;
			while (judge == "Y")
			{
				cout << "Input H for upgrading headquarter or input L for upgrading landships (H/L)" << endl;
				string judgeHL;
				cin >> judgeHL;
				if (judgeHL == "H")
				{
					if ((checkcoin(headquarterlevel[Hlevel - 1].coinstoimprove, R1.GoldCoins) == true) && (Hlevel < 7)) {
						cout << "Your Heardquarter has improved successfully!" << endl;
						R1.GoldCoins = R1.GoldCoins - headquarterlevel[Hlevel - 1].coinstoimprove;
						if (R1.GoldCoins <= 0) {
							break;
						}
						Hlevel++;
						//Checking whether we can update the troop
						if (Hlevel == 3) {
							troop.push_back(0);
						}
						if (Hlevel == 4) {
							troop.push_back(0);
						}
						if (Hlevel == 6) {
							troop.push_back(0);
						}

					}
					else if (checkcoin(headquarterlevel[Hlevel - 1].coinstoimprove, R1.GoldCoins) == false) {
						cout << "Sorry, you do not have enough coin to do so" << endl;
					}
					else if (Hlevel == 7)
					{
						cout << "The headquarter has reached its max level" << endl;
						cout << "Please enter N" << endl;
						cin >> judge;
						break;
					}
					checkdefeat();
				}
				else if (judgeHL == "L")
				{
					if ((checkcoin(LS[LSlevel - 1].Steelneededtoimprove, R1.Steel) == true) && LSlevel <7) {
						cout << "Your landships have been improved successfully!" << endl;
						R1.Steel = R1.Steel - LS[LSlevel - 1].Steelneededtoimprove;
						if (R1.GoldCoins <= 0) {
							break;
						}
						LSlevel++;
						spaceleft = LS[LSlevel - 1].Space;
					}
					else if (checkcoin(LS[LSlevel - 1].Steelneededtoimprove, R1.Steel) == false) {
						cout << "Sorry, you do not have enough steel to do so" << endl;
					}
					else if (LSlevel == 7)
					{
						cout << "The landship has reached its max level" << endl;
						cout << "Please enter N" << endl;
						cin >> judge;
						break;
					}
					checkdefeat();
				}
				else
				{
					break;
				}
				cout << "Do you want to upgrade your Headquarter or Landship? (Y/N)" << endl;
				cin >> judge;
			}
			cout << "\033[2J\033[1;1H";//To clear the screen
			checkdefeat();
			PrintPage1();
			askfornewpage();
		}

		else if (input1 == 50)//50 stands for 2
		{
			cout << "\033[2J\033[1;1H";//clear the screen
			PrintPage2();
			cout << "Do you want to upgrade your troop? (Y/N)" << endl;
			string judge;
			cin >> judge;
			while (judge == "Y")
			{
				TroopsUpgrade();
				cout << "Do you want to upgrade your troop? (Y/N)" << endl;
				cin >> judge;
			}
			cout << "\033[2J\033[1;1H";//To clear the screen
			checkdefeat();
			PrintPage1();
			askfornewpage();
		}

		else if (input1 == 51)//51 stands for 3
		{
			cout << "\033[2J\033[1;1H";//clear the screen
			PrintPage3();
			cout << "Do you want to upgrade your techonlogy? (Y/N)" << endl;
			string judge;
			cin >> judge;
			while (judge == "Y")
			{
				TechUpgrade();
				cout << "Do you want to upgrade your techonlogy? (Y/N)" << endl;
				cin >> judge;
			}
			cout << "\033[2J\033[1;1H";//To clear the screen
			checkdefeat();
			PrintPage1();
			askfornewpage();
		}

		else if (input1 == 52)//52 stands for 4
		{
			cout << "\033[2J\033[1;1H";//clear the screen
			PrintPage4();
			cout << endl;
			cout << "Do you want to train yout troops: Y/N" << endl;
			string judge;
			cin >> judge;//below are the troop training code
			while (judge == "Y") {
				int Infantrynumber = 0;
				int Heavyweaponsguynumber = 0;
				int Tanknumber = 0;
				int Helicopternumber = 0;
				while (judge != "N") {
					cout << "Please choose which troop you want to train:" << endl;
					int trooptype;


					cout << "Type 1 for Infantry" << endl;
					if (Hlevel >= 3) {
						cout << "Type 2 for Heavyweaponsguynumber" << endl;
					}

					if (Hlevel >= 4) {
						cout << "Type 3 for Tank" << endl;
					}

					if (Hlevel >= 6) {
						cout << "Type 4 for Helicopter" << endl;
					}
					cin >> trooptype;

					//For adding Infantry
					if (trooptype == 1) {
						cout << "Please enter how many infantry you want to make:" << endl;
						int number;
						cin >> number;
						while (checkspace(number * Infantrylevel[InfLevel - 1].placetake, spaceleft) == false) {
							cout << "The spaceleft not enough" << endl;
							cin >> number;
						}
						while (checkcoin(number * Infantrylevel[InfLevel - 1].goldcoinneeded, R1.GoldCoins) == false) {
							cout << "The coin not enough" << endl;
							cin >> number;
						}
						troop[0] = troop[0] + number;
						R1.GoldCoins = R1.GoldCoins - number * Infantrylevel[InfLevel - 1].goldcoinneeded;
						spaceleft = spaceleft - number * Infantrylevel[InfLevel - 1].placetake;
					}
					//For adding Heavyweaponguy
					if (Hlevel >= 3) {
						//For adding Heavyweaponguy
						if (trooptype == 2) {
							cout << "Please enter how many heavyweaponsguy you want to make:" << endl;
							int number;
							cin >> number;
							while (checkspace(number * Heavyweaponsguylevel[HWGLevel - 1].placetake, spaceleft) == false) {
								cout << "The spaceleft not enough" << endl;
								cin >> number;
							}
							while (checkcoin(number * Heavyweaponsguylevel[HWGLevel - 1].goldcoinneeded, R1.GoldCoins) == false) {
								cout << "The coin not enough" << endl;
								cin >> number;
							}
							troop[1] = troop[1] + number;
							R1.GoldCoins = R1.GoldCoins - number * Heavyweaponsguylevel[HWGLevel - 1].goldcoinneeded;
							spaceleft = spaceleft - number * Heavyweaponsguylevel[HWGLevel - 1].placetake;
						}
					}
					//For adding Tank
					if (Hlevel >= 4) {
						if (trooptype == 3) {
							cout << "Please enter how many tank you want to make:" << endl;
							int number;
							cin >> number;
							while (checkspace(number * Tanklevel[TKLevel - 1].placetake, spaceleft) == false) {
								cout << "The spaceleft not enough" << endl;
								cin >> number;
							}
							while (checkcoin(number * Tanklevel[TKLevel - 1].goldcoinneeded, R1.GoldCoins) == false) {
								cout << "The coin not enough" << endl;
								cin >> number;
							}
							troop[2] = troop[2] + number;
							R1.GoldCoins = R1.GoldCoins - number * Tanklevel[TKLevel - 1].goldcoinneeded;
							spaceleft = spaceleft - number * Tanklevel[TKLevel - 1].placetake;
						}
					}
					//For adding helicopter
					if (Hlevel >= 6) {
						if (trooptype == 4) {
							cout << "Please enter how many helicopters you want to make:" << endl;
							int number;
							cin >> number;
							while (checkspace(number * Helicopterlevel[HCLevel - 1].placetake, spaceleft) == false) {
								cout << "The spaceleft not enough" << endl;
								cin >> number;
							}
							while (checkcoin(number * Helicopterlevel[HCLevel - 1].goldcoinneeded, R1.GoldCoins) == false) {
								cout << "The coin not enough" << endl;
								cin >> number;
							}
							troop[3] = troop[3] + number;
							R1.GoldCoins = R1.GoldCoins - number * Helicopterlevel[HCLevel - 1].goldcoinneeded;
							spaceleft = spaceleft - number * Helicopterlevel[HCLevel - 1].placetake;
						}
					}

					cout << "Your space left is: " << spaceleft << endl;
					cout << "Your gold coin left is: " << R1.GoldCoins << endl;
					//If the player want to remove the troop
					cout << "Do you want to remove yout troops: Y/N" << endl;
					string remove;
					cin >> remove;
					if (remove == "Y") {
						for (int i = 0; i < troop.size(); i++) {
							if (i == 0) {
								R1.GoldCoins = R1.GoldCoins + troop[i] * Infantrylevel[InfLevel - 1].goldcoinneeded;
							}
							else if (i == 1) {
								R1.GoldCoins = R1.GoldCoins + troop[i] * Heavyweaponsguylevel[HWGLevel - 1].goldcoinneeded;
							}
							else if (i == 2) {
								R1.GoldCoins = R1.GoldCoins + troop[i] * Tanklevel[TKLevel - 1].goldcoinneeded;
							}
							else if (i == 3) {
								R1.GoldCoins = R1.GoldCoins + troop[i] * Helicopterlevel[HCLevel - 1].goldcoinneeded;
							}
							troop[i] = 0;
						}
						spaceleft = LS[LSlevel - 1].Space;
						cout << "Your space left is: " << spaceleft << endl;
						cout << "Your gold coin left is: " << R1.GoldCoins << endl;
					}



					cout << "Do you want to train yout troops: Y/N" << endl;
					cin >> judge;

				}
			}
			cout << "\033[2J\033[1;1H";
			PrintPage1();
			askfornewpage();
		}

		else if (input1 == 53)//53 stands for 5
		{
			cout << "\033[2J\033[1;1H";//clear the screen
			PrintPage5();

			//Searching cost
			cout << "The cost of search is: " << 50 * Hlevel << endl;
			R1.GoldCoins = R1.GoldCoins - 50 * Hlevel;
			cout << "Your coin now is: " << R1.GoldCoins << endl;
			cout << "\n";

			//Showing the defensive
			if (Hlevel == 1) {
				int x = ((rand() % 2) + 1); //x represents the number of Snipertowers
				cout << "The enemy has " << x << " Snipertowers: HP: " << D1.S.HP << " ; attackpower: " << D1.S.attackpower << endl;

				//Buildings' HP vector
				vector<int> SHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(D1.S.HP);
				}

				vector<int> InfantryHP;
				int a1 = troop[0];//The Infantry number
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;

				while (fuelleft >= (2 + 2 * Misslesusingtime)) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cin >> technologytype;
					while (technologytype != 1) {
						cout << "Type 1 for using Missles" << endl;
						cin >> technologytype;
					}
					cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
					cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers)" << endl;
					string towerchoose;
					cin >> towerchoose;
					while (towerchoose != "S") {
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers)" << endl;
						cin >> towerchoose;
					}
					if (towerchoose == "S") {
						for (int i = 0; i < SHP.size(); i++) {
							if (SHP[i] > 0) {
								SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
								if (SHP[i] < 0) {
									SHP[i] = 0;
								}
								break;
							}

						}
					}
					fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
					Misslesusingtime++;
					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Snipertowersremainingnumber = 0;
				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				while ((Infantryremainingnumber != 0) && (Snipertowersremainingnumber != 0)) {
					//Checking for the enemy side
					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}
					Snipertowersremainingnumber = 0;
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}
					}
					//Checking for our troop
					int defensivedamage = Snipertowersremainingnumber * D1.S.attackpower;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamage) {
								InfantryHP[j] = InfantryHP[j] - defensivedamage;
								break;
							}
							else if (InfantryHP[j] < defensivedamage) {
								defensivedamage = defensivedamage - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}
					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}


				}

				if (Infantryremainingnumber == 0) {
					cout << "Sorry, you lose in this battle" << endl;
				}
				else if (Snipertowersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Here is your bonus: Coin: 500; Steel: 20" << endl;
					R1.GoldCoins = R1.GoldCoins + 500;
					R1.Steel = R1.Steel + 30;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;


			}

			else if (Hlevel == 2) {
				int x = ((rand() % 3) + 1); //x represents the number of Snipertowers
				cout << "The enemy has " << x << " Snipertowers: HP: " << D2.S.HP << " ; attackpower: " << D2.S.attackpower << endl;

				//Buildings' HP vector
				vector<int> SHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(D2.S.HP);
				}

				vector<int> InfantryHP;
				int a1 = troop[0];//The Infantry number
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;

				while (fuelleft >= (2 + 2 * Misslesusingtime)) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cin >> technologytype;
					while (technologytype != 1) {
						cout << "Type 1 for using Missles" << endl;
						cin >> technologytype;
					}
					cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
					cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers)" << endl;
					string towerchoose;
					cin >> towerchoose;
					while (towerchoose != "S") {
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers)" << endl;
						cin >> towerchoose;
					}
					if (towerchoose == "S") {
						for (int i = 0; i < SHP.size(); i++) {
							if (SHP[i] > 0) {
								SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
								if (SHP[i] < 0) {
									SHP[i] = 0;
								}
								break;
							}

						}
					}
					fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
					Misslesusingtime++;
					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Snipertowersremainingnumber = 0;
				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				while ((Infantryremainingnumber != 0) && (Snipertowersremainingnumber != 0)) {
					//Checking for the enemy side
					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}
					Snipertowersremainingnumber = 0;
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}
					}
					//Checking for our troop
					int defensivedamage = Snipertowersremainingnumber * D2.S.attackpower;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamage) {
								InfantryHP[j] = InfantryHP[j] - defensivedamage;
								break;
							}
							else if (InfantryHP[j] < defensivedamage) {
								defensivedamage = defensivedamage - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}
					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}


				}

				if (Infantryremainingnumber == 0) {
					cout << "Sorry, you lose in this battle" << endl;
				}
				else if (Snipertowersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Here is your bonus: Coin: 1000; Steel: 50" << endl;
					R1.GoldCoins = R1.GoldCoins + 1000;
					R1.Steel = R1.Steel + 50;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;

			}

			else if (Hlevel == 3) {
				int x = ((rand() % 3) + 1); //x represents the number of Snipertowers
				int y = ((rand() % 2) + 1); //y represents the number of Mortars
				cout << "The enemy has " << x << " Snipertowers: HP: " << D3.S.HP << " ; attackpower: " << D3.S.attackpower << endl;
				cout << "The enemy has " << y << " Mortars: HP: " << D3.M.HP << " ; attackpower: " << D3.M.attackpower << endl;

				//Heavyweaponguy should be damaged first; Snipertowers should be damaged then

				vector<int> SHP;
				vector<int> MHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(D3.S.HP);
				}
				for (int i = 0; i < y; i++) {
					MHP.push_back(D3.M.HP);
				}

				vector<int> InfantryHP;
				vector<int> HeavyweaponguyHP;
				int a1 = troop[0];//The Infantry number
				int a2 = troop[1];//The Heavyweaponguy number
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				for (int i = 0; i < a2; i++) {
					HeavyweaponguyHP.push_back(Heavyweaponsguylevel[HWGLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;

				while (fuelleft >= (2 + 2 * Misslesusingtime)) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cin >> technologytype;
					while (technologytype != 1) {
						cout << "Type 1 for using Missles" << endl;
						cin >> technologytype;
					}
					cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
					cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortars)" << endl;
					string towerchoose;
					cin >> towerchoose;
					while (towerchoose != "S" && towerchoose != "M") {
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortar)" << endl;
						cin >> towerchoose;
					}
					if (towerchoose == "S") {
						for (int i = 0; i < SHP.size(); i++) {
							if (SHP[i] > 0) {
								SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
								if (SHP[i] < 0) {
									SHP[i] = 0;
								}
								break;
							}

						}
					}
					else if (towerchoose == "M") {
						for (int i = 0; i < MHP.size(); i++) {
							if (MHP[i] > 0) {
								MHP[i] = MHP[i] - Missleslevel[MLevel - 1].damage;
								if (MHP[i] < 0) {
									MHP[i] = 0;
								}
								break;
							}

						}
					}

					fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
					Misslesusingtime++;
					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < y; i++) {
						cout << "Mortars" << i + 1 << ":HP" << MHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Heavyweaponguyremainingnumber = a2;
				int Snipertowersremainingnumber = 0;
				int Mortarsremainingnumber = 0;
				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				for (int i = 0; i < y; i++) {
					if (MHP[i] != 0) {
						Mortarsremainingnumber++;
					}
				}

				while (((Infantryremainingnumber != 0) || (Heavyweaponguyremainingnumber != 0)) && ((Mortarsremainingnumber != 0) || (Snipertowersremainingnumber != 0))) {
					//Checking for the enemy side
					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower + Heavyweaponguyremainingnumber * Heavyweaponsguylevel[HWGLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < y; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (MHP[i] > 0) {
							if (MHP[i] >= attacksidedamage) {
								MHP[i] = MHP[i] - attacksidedamage;
								break;
							}
							else if (MHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - MHP[i];
								MHP[i] = 0;
							}
						}
						else if (MHP[i] == 0) {
							continue;
						}
					}

					Snipertowersremainingnumber = 0;
					//Checking for the remaining Snipertowersnumber
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}
					}
					Mortarsremainingnumber = 0;
					//Checking for the remaining Mortarsnumber
					for (int i = 0; i < x; i++) {
						if (MHP[i] != 0) {
							Mortarsremainingnumber++;
						}
					}

					//Checking for our troop
					int defensivedamageindividual = Snipertowersremainingnumber * D3.S.attackpower;
					int defensivedamagefirsttwo = Mortarsremainingnumber * D3.M.attackpower;//Since now there are only two troops, all of them will get damaged
					//Snipertowers damage
					for (int j = 0; j < a2; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageindividual) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageindividual;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HeavyweaponguyHP[j];
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}


					for (int j = 0; j < a1; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageindividual) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageindividual;
								break;
							}
							else if (InfantryHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					//Mortars damage
					for (int j = 0; j < a2; j++) {
						if (defensivedamagefirsttwo == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamagefirsttwo) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamagefirsttwo;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamagefirsttwo) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamagefirsttwo == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamagefirsttwo) {
								InfantryHP[j] = InfantryHP[j] - defensivedamagefirsttwo;
								break;
							}
							else if (InfantryHP[j] < defensivedamagefirsttwo) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					Heavyweaponguyremainingnumber = 0;
					for (int j = 0; j < a2; j++) {
						if (HeavyweaponguyHP[j] != 0) {
							Heavyweaponguyremainingnumber++;
						}
					}

					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}


				}

				if (Infantryremainingnumber == 0 && Heavyweaponguyremainingnumber == 0) {
					cout << "Sorry, you lose in this battle" << endl;
				}
				else if (Mortarsremainingnumber == 0 && Snipertowersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Here is your bonus: Coin: 1800; Steel: 80" << endl;
					R1.GoldCoins = R1.GoldCoins + 1800;
					R1.Steel = R1.Steel + 80;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;

			}

			else if (Hlevel == 4) {
				int x = ((rand() % 3) + 2); //x represents the number of Snipertowers
				int y = ((rand() % 2) + 2); //y represents the number of Mortars
				cout << "The enemy has " << x << " Snipertowers: HP: " << D4.S.HP << " ; attackpower: " << D4.S.attackpower << endl;
				cout << "The enemy has " << y << " Mortars: HP: " << D4.M.HP << " ; attackpower: " << D4.M.attackpower << endl;

				//Heavyweaponguy should be damaged first; Snipertowers should be damaged then; Tank then

				vector<int> SHP;
				vector<int> MHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(D4.S.HP);
				}
				for (int i = 0; i < y; i++) {
					MHP.push_back(D4.M.HP);
				}

				vector<int> InfantryHP;
				vector<int> HeavyweaponguyHP;
				vector<int> TankHP;
				int a1 = troop[0];//The Infantry number
				int a2 = troop[1];//The Heavyweaponguy number
				int a3 = troop[2];
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				for (int i = 0; i < a2; i++) {
					HeavyweaponguyHP.push_back(Heavyweaponsguylevel[HWGLevel - 1].HP);
				}

				for (int i = 0; i < a3; i++) {
					TankHP.push_back(Tanklevel[TKLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;
				int MMusingtime = 0;

				while ((fuelleft >= (2 + 2 * Misslesusingtime)) || (fuelleft >= (6 + 2 * MMusingtime))) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cout << "Type 2 for using Multiple missles" << endl;
					cin >> technologytype;
					while (technologytype != 1 && technologytype != 2) {
						cout << "Type 1 for using Missles" << endl;
						cout << "Type 2 for using Multiple missles" << endl;
						cin >> technologytype;
					}
					if (technologytype == 1) {
						cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortars)" << endl;
						string towerchoose;
						cin >> towerchoose;
						while (towerchoose != "S" && towerchoose != "M") {
							cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortar)" << endl;
							cin >> towerchoose;
						}
						if (towerchoose == "S") {
							for (int i = 0; i < SHP.size(); i++) {
								if (SHP[i] > 0) {
									SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
									if (SHP[i] < 0) {
										SHP[i] = 0;
									}
								}
								break;
							}
						}
						else if (towerchoose == "M") {
							for (int i = 0; i < MHP.size(); i++) {
								if (MHP[i] > 0) {
									MHP[i] = MHP[i] - Missleslevel[MLevel - 1].damage;
									if (MHP[i] < 0) {
										MHP[i] = 0;
									}
								}
								break;
							}
						}

						fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
						Misslesusingtime++;
					}

					else if (technologytype == 2) {
						cout << "It will cost you " << 6 + 2 * MMusingtime << " fuel" << endl;
						cout << "All the remained building will get damaged" << endl;
						for (int i = 0; i < SHP.size(); i++) {
							SHP[i] = SHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (SHP[i] < 0) {
								SHP[i] = 0;
							}
						}

						for (int i = 0; i < MHP.size(); i++) {
							MHP[i] = MHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (MHP[i] < 0) {
								MHP[i] = 0;
							}
						}

						fuelleft = fuelleft - (6 + 2 * MMusingtime);
						MMusingtime++;
					}
					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < y; i++) {
						cout << "Mortars" << i + 1 << ":HP" << MHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Heavyweaponguyremainingnumber = a2;
				int Tankremainingnumber = a3;

				int Snipertowersremainingnumber = 0;
				int Mortarsremainingnumber = 0;

				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				for (int i = 0; i < y; i++) {
					if (MHP[i] != 0) {
						Mortarsremainingnumber++;
					}
				}

				while (((Infantryremainingnumber != 0) || (Heavyweaponguyremainingnumber != 0 || (Tankremainingnumber != 0))) && ((Mortarsremainingnumber != 0) || (Snipertowersremainingnumber != 0))) {
					//Checking for the enemy side
					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower + Heavyweaponguyremainingnumber * Heavyweaponsguylevel[HWGLevel - 1].attackpower + Tankremainingnumber * Tanklevel[TKLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < y; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (MHP[i] > 0) {
							if (MHP[i] >= attacksidedamage) {
								MHP[i] = MHP[i] - attacksidedamage;
								break;
							}
							else if (MHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - MHP[i];
								MHP[i] = 0;
							}
						}
						else if (MHP[i] == 0) {
							continue;
						}
					}

					Snipertowersremainingnumber = 0;
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}

					}

					Mortarsremainingnumber = 0;
					for (int i = 0; i < y; i++) {
						if (MHP[i] != 0) {
							Mortarsremainingnumber++;
						}
					}

					//Checking for our troop
					int defensivedamageindividual = Snipertowersremainingnumber * D4.S.attackpower;
					int defensivedamageground = Mortarsremainingnumber * D4.M.attackpower;//Since all the troops are on the ground
					//Snipertowers damage
					for (int j = 0; j < a2; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageindividual) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageindividual;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HeavyweaponguyHP[j];
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}


					for (int j = 0; j < a1; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageindividual) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageindividual;
								break;
							}
							else if (InfantryHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageindividual) {
								TankHP[j] = TankHP[j] - defensivedamageindividual;
								break;
							}
							else if (TankHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - TankHP[j];
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					//Mortars damage

					for (int j = 0; j < a2; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageground) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageground;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageground) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageground) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageground;
								break;
							}
							else if (InfantryHP[j] < defensivedamageground) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageground) {
								TankHP[j] = TankHP[j] - defensivedamageground;
								break;
							}
							else if (TankHP[j] < defensivedamageground) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}



					Heavyweaponguyremainingnumber = 0;
					for (int j = 0; j < a2; j++) {
						if (HeavyweaponguyHP[j] != 0) {
							Heavyweaponguyremainingnumber++;
						}
					}

					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}

					Tankremainingnumber = 0;
					for (int j = 0; j < a3; j++) {
						if (TankHP[j] != 0) {
							Tankremainingnumber++;
						}
					}

				}

				if (Infantryremainingnumber == 0 && Heavyweaponguyremainingnumber == 0 && Tankremainingnumber == 0) {
					cout << "Sorry, you lose in this battle" << endl;
				}
				else if (Mortarsremainingnumber == 0 && Snipertowersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Here is your bonus: Coin: 3000; Steel: 150" << endl;
					R1.GoldCoins = R1.GoldCoins + 3000;
					R1.Steel = R1.Steel + 150;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;


			}

			else if (Hlevel == 5) {
				int x = ((rand() % 3) + 2); //x represents the number of Snipertowers
				int y = ((rand() % 3) + 2); //y represents the number of Mortars
				int z = 1; //z represents the number of Rocketlaunchers
				cout << "The enemy has " << x << " Snipertowers: HP: " << D5.S.HP << " ; attackpower: " << D5.S.attackpower << endl;
				cout << "The enemy has " << y << " Mortars: HP: " << D5.M.HP << " ; attackpower: " << D5.M.attackpower << endl;
				cout << "The enemy has " << z << " Rocketlaunchers: HP: " << D5.R.HP << " ; attackpower: " << D5.R.attackpower << endl;

				//Snipertowers should be damaged first, then the Mortars, finally the Rocket launchers
				//Heavyweaponguy should be damaged first; Snipertowers should be damaged then; Tank then

				vector<int> SHP;
				vector<int> MHP;
				vector<int> RHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(D5.S.HP);
				}
				for (int i = 0; i < y; i++) {
					MHP.push_back(D5.M.HP);
				}
				for (int i = 0; i < z; i++) {
					RHP.push_back(D5.R.HP);
				}

				vector<int> InfantryHP;
				vector<int> HeavyweaponguyHP;
				vector<int> TankHP;
				int a1 = troop[0];//The Infantry number
				int a2 = troop[1];//The Heavyweaponguy number
				int a3 = troop[2];
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				for (int i = 0; i < a2; i++) {
					HeavyweaponguyHP.push_back(Heavyweaponsguylevel[HWGLevel - 1].HP);
				}

				for (int i = 0; i < a3; i++) {
					TankHP.push_back(Tanklevel[TKLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;
				int MMusingtime = 0;

				while ((fuelleft >= (2 + 2 * Misslesusingtime)) || (fuelleft >= (6 + 2 * MMusingtime))) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cout << "Type 2 for using Multiple missles" << endl;
					cin >> technologytype;
					while (technologytype != 1 && technologytype != 2) {
						cout << "Type 1 for using Missles" << endl;
						cout << "Type 2 for using Multiple missles" << endl;
						cin >> technologytype;
					}
					if (technologytype == 1) {
						cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortars; R for the first Rocketlaunchers)" << endl;
						string towerchoose;
						cin >> towerchoose;
						while (towerchoose != "S" && towerchoose != "M" && towerchoose != "R") {
							cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortar; R for the first Rocketlaunchers)" << endl;
							cin >> towerchoose;
						}
						if (towerchoose == "S") {
							for (int i = 0; i < SHP.size(); i++) {
								if (SHP[i] > 0) {
									SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
									if (SHP[i] < 0) {
										SHP[i] = 0;
									}
									break;
								}

							}
						}
						else if (towerchoose == "M") {
							for (int i = 0; i < MHP.size(); i++) {
								if (MHP[i] > 0) {
									MHP[i] = MHP[i] - Missleslevel[MLevel - 1].damage;
									if (MHP[i] < 0) {
										MHP[i] = 0;
									}
									break;
								}

							}
						}
						else if (towerchoose == "R") {
							for (int i = 0; i < RHP.size(); i++) {
								if (RHP[i] > 0) {
									RHP[i] = RHP[i] - Missleslevel[MLevel - 1].damage;
									if (RHP[i] < 0) {
										RHP[i] = 0;
									}
									break;
								}

							}
						}

						fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
						Misslesusingtime++;
					}

					else if (technologytype == 2) {
						cout << "It will cost you " << 6 + 2 * MMusingtime << " fuel" << endl;
						cout << "All the remained building will get damaged" << endl;
						for (int i = 0; i < SHP.size(); i++) {
							SHP[i] = SHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (SHP[i] < 0) {
								SHP[i] = 0;
							}
						}

						for (int i = 0; i < MHP.size(); i++) {
							MHP[i] = MHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (MHP[i] < 0) {
								MHP[i] = 0;
							}
						}

						for (int i = 0; i < RHP.size(); i++) {
							RHP[i] = RHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (RHP[i] < 0) {
								RHP[i] = 0;
							}
						}

						fuelleft = fuelleft - (6 + 2 * MMusingtime);
						MMusingtime++;
					}

					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < y; i++) {
						cout << "Mortars" << i + 1 << ":HP" << MHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < z; i++) {
						cout << "Rocketlaunchers" << i + 1 << ":HP" << RHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Heavyweaponguyremainingnumber = a2;
				int Tankremainingnumber = a3;

				int Snipertowersremainingnumber = 0;
				int Mortarsremainingnumber = 0;
				int Rocketlaunchersremainingnumber = 0;

				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				for (int i = 0; i < y; i++) {
					if (MHP[i] != 0) {
						Mortarsremainingnumber++;
					}
				}

				for (int i = 0; i < z; i++) {
					if (RHP[i] != 0) {
						Rocketlaunchersremainingnumber++;
					}
				}

				while (((Infantryremainingnumber != 0) || (Heavyweaponguyremainingnumber != 0 || (Tankremainingnumber != 0))) && ((Mortarsremainingnumber != 0) || (Snipertowersremainingnumber != 0) || (Rocketlaunchersremainingnumber != 0))) {
					//Checking for the enemy side
					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower + Heavyweaponguyremainingnumber * Heavyweaponsguylevel[HWGLevel - 1].attackpower + Tankremainingnumber * Tanklevel[TKLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < y; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (MHP[i] > 0) {
							if (MHP[i] >= attacksidedamage) {
								MHP[i] = MHP[i] - attacksidedamage;
								break;
							}
							else if (MHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - MHP[i];
								MHP[i] = 0;
							}
						}
						else if (MHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < y; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (RHP[i] > 0) {
							if (RHP[i] >= attacksidedamage) {
								RHP[i] = RHP[i] - attacksidedamage;
								break;
							}
							else if (RHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - RHP[i];
								RHP[i] = 0;
							}
						}
						else if (RHP[i] == 0) {
							continue;
						}
					}

					Snipertowersremainingnumber = 0;
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}

					}

					Mortarsremainingnumber = 0;
					for (int i = 0; i < y; i++) {
						if (MHP[i] != 0) {
							Mortarsremainingnumber++;
						}
					}

					Rocketlaunchersremainingnumber = 0;
					for (int i = 0; i < z; i++) {
						if (RHP[i] != 0) {
							Rocketlaunchersremainingnumber++;
						}
					}

					//Checking for our troop
					int defensivedamageindividual = Snipertowersremainingnumber * D5.S.attackpower;
					int defensivedamageground = Mortarsremainingnumber * D5.M.attackpower;//Since all the troops are on the ground
					int defensivedamageoverall = Rocketlaunchersremainingnumber * D5.R.attackpower;
					//Snipertowers damage
					for (int j = 0; j < a2; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageindividual) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageindividual;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HeavyweaponguyHP[j];
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}


					for (int j = 0; j < a1; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageindividual) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageindividual;
								break;
							}
							else if (InfantryHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageindividual) {
								TankHP[j] = TankHP[j] - defensivedamageindividual;
								break;
							}
							else if (TankHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - TankHP[j];
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					//Mortars damage

					for (int j = 0; j < a2; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageground) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageground;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageground) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageground) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageground;
								break;
							}
							else if (InfantryHP[j] < defensivedamageground) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageground) {
								TankHP[j] = TankHP[j] - defensivedamageground;
								break;
							}
							else if (TankHP[j] < defensivedamageground) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					//Rocketlaunchers
					for (int j = 0; j < a2; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageoverall) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageoverall;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageoverall) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageoverall) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageoverall;
								break;
							}
							else if (InfantryHP[j] < defensivedamageoverall) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageoverall) {
								TankHP[j] = TankHP[j] - defensivedamageoverall;
								break;
							}
							else if (TankHP[j] < defensivedamageoverall) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}


					Heavyweaponguyremainingnumber = 0;
					for (int j = 0; j < a2; j++) {
						if (HeavyweaponguyHP[j] != 0) {
							Heavyweaponguyremainingnumber++;
						}
					}

					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}

					Tankremainingnumber = 0;
					for (int j = 0; j < a3; j++) {
						if (TankHP[j] != 0) {
							Tankremainingnumber++;
						}
					}

				}

				if (Infantryremainingnumber == 0 && Heavyweaponguyremainingnumber == 0 && Tankremainingnumber == 0) {
					cout << "Sorry, you lose in this battle" << endl;
				}
				else if (Mortarsremainingnumber == 0 && Snipertowersremainingnumber == 0 && Rocketlaunchersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Here is your bonus: Coin: 5000; Steel: 250" << endl;
					R1.GoldCoins = R1.GoldCoins + 5000;
					R1.Steel = R1.Steel + 250;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;



			}

			else if (Hlevel == 6) {
				int x = ((rand() % 4) + 2); //x represents the number of Snipertowers
				int y = ((rand() % 3) + 2); //y represents the number of Mortars
				int z = ((rand() % 2) + 1); //z represents the number of Rocketlaunchers
				cout << "The enemy has " << x << " Snipertowers: HP: " << D6.S.HP << " ; attackpower: " << D6.S.attackpower << endl;
				cout << "The enemy has " << y << " Mortars: HP: " << D6.M.HP << " ; attackpower: " << D6.M.attackpower << endl;
				cout << "The enemy has " << z << " Rocketlaunchers: HP: " << D6.R.HP << " ; attackpower: " << D6.R.attackpower << endl;

				//Snipertowers should be damaged first, then the Mortars, finally the Rocket launchers
				//Heavyweaponguy should be damaged first; Snipertowers should be damaged then; Tank then

				vector<int> SHP;
				vector<int> MHP;
				vector<int> RHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(D6.S.HP);
				}
				for (int i = 0; i < y; i++) {
					MHP.push_back(D6.M.HP);
				}
				for (int i = 0; i < z; i++) {
					RHP.push_back(D6.R.HP);
				}

				vector<int> InfantryHP;
				vector<int> HeavyweaponguyHP;
				vector<int> TankHP;
				vector<int> HelicopterHP;
				int a1 = troop[0];//The Infantry number
				int a2 = troop[1];//The Heavyweaponguy number
				int a3 = troop[2];//The Tank number
				int a4 = troop[3];//The Helicopter number
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				for (int i = 0; i < a2; i++) {
					HeavyweaponguyHP.push_back(Heavyweaponsguylevel[HWGLevel - 1].HP);
				}

				for (int i = 0; i < a3; i++) {
					TankHP.push_back(Tanklevel[TKLevel - 1].HP);
				}

				for (int i = 0; i < a4; i++) {
					HelicopterHP.push_back(Helicopterlevel[HCLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;
				int MMusingtime = 0;

				while ((fuelleft >= (2 + 2 * Misslesusingtime)) || (fuelleft >= (6 + 2 * MMusingtime))) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cout << "Type 2 for using Multiple missles" << endl;
					cin >> technologytype;
					while (technologytype != 1 && technologytype != 2) {
						cout << "Type 1 for using Missles" << endl;
						cout << "Type 2 for using Multiple missles" << endl;
						cin >> technologytype;
					}
					if (technologytype == 1) {
						cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortars; R for the first Rocketlaunchers)" << endl;
						string towerchoose;
						cin >> towerchoose;
						while (towerchoose != "S" && towerchoose != "M" && towerchoose != "R") {
							cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortar; R for the first Rocketlaunchers)" << endl;
							cin >> towerchoose;
						}
						if (towerchoose == "S") {
							for (int i = 0; i < SHP.size(); i++) {
								if (SHP[i] > 0) {
									SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
									if (SHP[i] < 0) {
										SHP[i] = 0;
									}
									break;
								}

							}
						}
						else if (towerchoose == "M") {
							for (int i = 0; i < MHP.size(); i++) {
								if (MHP[i] > 0) {
									MHP[i] = MHP[i] - Missleslevel[MLevel - 1].damage;
									if (MHP[i] < 0) {
										MHP[i] = 0;
									}
									break;
								}

							}
						}
						else if (towerchoose == "R") {
							for (int i = 0; i < RHP.size(); i++) {
								if (RHP[i] > 0) {
									RHP[i] = RHP[i] - Missleslevel[MLevel - 1].damage;
									if (RHP[i] < 0) {
										RHP[i] = 0;
									}
									break;
								}

							}
						}

						fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
						Misslesusingtime++;
					}

					else if (technologytype == 2) {
						cout << "It will cost you " << 6 + 2 * MMusingtime << " fuel" << endl;
						cout << "All the remained building will get damaged" << endl;
						for (int i = 0; i < SHP.size(); i++) {
							SHP[i] = SHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (SHP[i] < 0) {
								SHP[i] = 0;
							}
						}

						for (int i = 0; i < MHP.size(); i++) {
							MHP[i] = MHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (MHP[i] < 0) {
								MHP[i] = 0;
							}
						}

						for (int i = 0; i < RHP.size(); i++) {
							RHP[i] = RHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (RHP[i] < 0) {
								RHP[i] = 0;
							}
						}

						fuelleft = fuelleft - (6 + 2 * MMusingtime);
						MMusingtime++;
					}

					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < y; i++) {
						cout << "Mortars" << i + 1 << ":HP" << MHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < z; i++) {
						cout << "Rocketlaunchers" << i + 1 << ":HP" << RHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Heavyweaponguyremainingnumber = a2;
				int Tankremainingnumber = a3;
				int Helicopterremainingnumber = a4;

				int Snipertowersremainingnumber = 0;
				int Mortarsremainingnumber = 0;
				int Rocketlaunchersremainingnumber = 0;

				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				for (int i = 0; i < y; i++) {
					if (MHP[i] != 0) {
						Mortarsremainingnumber++;
					}
				}

				for (int i = 0; i < z; i++) {
					if (RHP[i] != 0) {
						Rocketlaunchersremainingnumber++;
					}
				}

				cout << "A" << endl;

				while (((Infantryremainingnumber != 0) || (Heavyweaponguyremainingnumber != 0 || (Tankremainingnumber != 0) || (Helicopterremainingnumber != 0))) && ((Mortarsremainingnumber != 0) || (Snipertowersremainingnumber != 0) || (Rocketlaunchersremainingnumber != 0))) {
					//Checking for the enemy side
					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower + Heavyweaponguyremainingnumber * Heavyweaponsguylevel[HWGLevel - 1].attackpower + Tankremainingnumber * Tanklevel[TKLevel - 1].attackpower + Helicopterremainingnumber * Helicopterlevel[HCLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < y; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (MHP[i] > 0) {
							if (MHP[i] >= attacksidedamage) {
								MHP[i] = MHP[i] - attacksidedamage;
								break;
							}
							else if (MHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - MHP[i];
								MHP[i] = 0;
							}
						}
						else if (MHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < z; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (RHP[i] > 0) {
							if (RHP[i] >= attacksidedamage) {
								RHP[i] = RHP[i] - attacksidedamage;
								break;
							}
							else if (RHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - RHP[i];
								RHP[i] = 0;
							}
						}
						else if (RHP[i] == 0) {
							continue;
						}
					}

					Snipertowersremainingnumber = 0;
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}

					}

					Mortarsremainingnumber = 0;
					for (int i = 0; i < y; i++) {
						if (MHP[i] != 0) {
							Mortarsremainingnumber++;
						}
					}

					Rocketlaunchersremainingnumber = 0;
					for (int i = 0; i < z; i++) {
						if (RHP[i] != 0) {
							Rocketlaunchersremainingnumber++;
						}
					}

					//Checking for our troop
					int defensivedamageindividual = Snipertowersremainingnumber * D6.S.attackpower;
					int defensivedamageground = Mortarsremainingnumber * D6.M.attackpower;//Since all the troops are on the ground
					int defensivedamageoverall = Rocketlaunchersremainingnumber * D6.R.attackpower;
					//Snipertowers damage
					for (int j = 0; j < a2; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageindividual) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageindividual;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HeavyweaponguyHP[j];
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}


					for (int j = 0; j < a1; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageindividual) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageindividual;
								break;
							}
							else if (InfantryHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageindividual) {
								TankHP[j] = TankHP[j] - defensivedamageindividual;
								break;
							}
							else if (TankHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - TankHP[j];
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a4; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HelicopterHP[j] > 0) {
							if (HelicopterHP[j] >= defensivedamageindividual) {
								HelicopterHP[j] = HelicopterHP[j] - defensivedamageindividual;
								break;
							}
							else if (HelicopterHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HelicopterHP[j];
								HelicopterHP[j] = 0;
							}
						}
						else if (HelicopterHP[j] == 0) {
							continue;
						}
					}

					//Mortars damage

					for (int j = 0; j < a2; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageground) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageground;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageground) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageground) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageground;
								break;
							}
							else if (InfantryHP[j] < defensivedamageground) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageground) {
								TankHP[j] = TankHP[j] - defensivedamageground;
								break;
							}
							else if (TankHP[j] < defensivedamageground) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					//Rocketlaunchers
					for (int j = 0; j < a2; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageoverall) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageoverall;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageoverall) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageoverall) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageoverall;
								break;
							}
							else if (InfantryHP[j] < defensivedamageoverall) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageoverall) {
								TankHP[j] = TankHP[j] - defensivedamageoverall;
								break;
							}
							else if (TankHP[j] < defensivedamageoverall) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a4; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (HelicopterHP[j] > 0) {
							if (HelicopterHP[j] >= defensivedamageoverall) {
								HelicopterHP[j] = HelicopterHP[j] - defensivedamageoverall;
								break;
							}
							else if (HelicopterHP[j] < defensivedamageoverall) {
								HelicopterHP[j] = 0;
							}
						}
						else if (HelicopterHP[j] == 0) {
							continue;
						}
					}


					Heavyweaponguyremainingnumber = 0;
					for (int j = 0; j < a2; j++) {
						if (HeavyweaponguyHP[j] != 0) {
							Heavyweaponguyremainingnumber++;
						}
					}

					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}

					Tankremainingnumber = 0;
					for (int j = 0; j < a3; j++) {
						if (TankHP[j] != 0) {
							Tankremainingnumber++;
						}
					}

					Helicopterremainingnumber = 0;
					for (int j = 0; j < a4; j++) {
						if (HelicopterHP[j] != 0) {
							Helicopterremainingnumber++;
						}
					}

				}

				if (Infantryremainingnumber == 0 && Heavyweaponguyremainingnumber == 0 && Tankremainingnumber == 0 && Helicopterremainingnumber == 0) {
					cout << "Sorry, you lose in this battle" << endl;
				}
				else if (Mortarsremainingnumber == 0 && Snipertowersremainingnumber == 0 && Rocketlaunchersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Here is your bonus: Coin: 10000; Steel: 500" << endl;
					R1.GoldCoins = R1.GoldCoins + 10000;
					R1.Steel = R1.Steel + 500;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;
			}

			else if (Hlevel == 7) {
				int x = 7; //x represents the number of Snipertowers
				int y = 5; //y represents the number of Mortars
				int z = 3; //z represents the number of Rocketlaunchers
				cout << "The enemy has " << x << " Snipertowers: HP: " << Boss.S.HP << " ; attackpower: " << Boss.S.attackpower << endl;
				cout << "The enemy has " << y << " Mortars: HP: " << Boss.M.HP << " ; attackpower: " << Boss.M.attackpower << endl;
				cout << "The enemy has " << z << " Rocketlaunchers: HP: " << Boss.R.HP << " ; attackpower: " << Boss.R.attackpower << endl;

				//Snipertowers should be damaged first, then the Mortars, finally the Rocket launchers
				//Heavyweaponguy should be damaged first; Snipertowers should be damaged then; Tank then

				vector<int> SHP;
				vector<int> MHP;
				vector<int> RHP;
				for (int i = 0; i < x; i++) {
					SHP.push_back(Boss.S.HP);
				}
				for (int i = 0; i < y; i++) {
					MHP.push_back(Boss.M.HP);
				}
				for (int i = 0; i < z; i++) {
					RHP.push_back(Boss.R.HP);
				}

				vector<int> InfantryHP;
				vector<int> HeavyweaponguyHP;
				vector<int> TankHP;
				vector<int> HelicopterHP;
				int a1 = troop[0];//The Infantry number
				int a2 = troop[1];//The Heavyweaponguy number
				int a3 = troop[2];//The Tank number
				int a4 = troop[3];//The Helicopter number
				for (int i = 0; i < a1; i++) {
					InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);
				}

				for (int i = 0; i < a2; i++) {
					HeavyweaponguyHP.push_back(Heavyweaponsguylevel[HWGLevel - 1].HP);
				}

				for (int i = 0; i < a3; i++) {
					TankHP.push_back(Tanklevel[TKLevel - 1].HP);
				}

				for (int i = 0; i < a4; i++) {
					HelicopterHP.push_back(Helicopterlevel[HCLevel - 1].HP);
				}

				int fuelleft = headquarterlevel[Hlevel - 1].Fuel;
				int Misslesusingtime = 0;
				int MMusingtime = 0;

				while ((fuelleft >= (2 + 2 * Misslesusingtime)) || (fuelleft >= (6 + 2 * MMusingtime))) {
					cout << "Please use your technology:" << endl;
					cout << "Your fuel left is: " << fuelleft << endl;
					int technologytype;
					cout << "Type 1 for using Missles" << endl;
					cout << "Type 2 for using Multiple missles" << endl;
					cin >> technologytype;
					while (technologytype != 1 && technologytype != 2) {
						cout << "Type 1 for using Missles" << endl;
						cout << "Type 2 for using Multiple missles" << endl;
						cin >> technologytype;
					}
					if (technologytype == 1) {
						cout << "It will cost you " << 2 + 2 * Misslesusingtime << " fuel" << endl;
						cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortars; R for the first Rocketlaunchers)" << endl;
						string towerchoose;
						cin >> towerchoose;
						while (towerchoose != "S" && towerchoose != "M" && towerchoose != "R") {
							cout << "Please indicate which Building you want to damage: (e.g. S for the first left Snipertowers; M for the first left Mortar; R for the first Rocketlaunchers)" << endl;
							cin >> towerchoose;
						}

						if (towerchoose == "S") {
							for (int i = 0; i < SHP.size(); i++) {
								if (SHP[i] > 0) {
									SHP[i] = SHP[i] - Missleslevel[MLevel - 1].damage;
									if (SHP[i] < 0) {
										SHP[i] = 0;
									}
									break;
								}

							}
						}
						else if (towerchoose == "M") {
							for (int i = 0; i < MHP.size(); i++) {
								if (MHP[i] > 0) {
									MHP[i] = MHP[i] - Missleslevel[MLevel - 1].damage;
									if (MHP[i] < 0) {
										MHP[i] = 0;
									}
									break;
								}

							}
						}
						else if (towerchoose == "R") {
							for (int i = 0; i < RHP.size(); i++) {
								if (RHP[i] > 0) {
									RHP[i] = RHP[i] - Missleslevel[MLevel - 1].damage;
									if (RHP[i] < 0) {
										RHP[i] = 0;
									}
									break;
								}

							}
						}

						fuelleft = fuelleft - (2 + 2 * Misslesusingtime);
						Misslesusingtime++;
					}

					else if (technologytype == 2) {
						cout << "It will cost you " << 6 + 2 * MMusingtime << " fuel" << endl;
						cout << "All the remained building will get damaged" << endl;
						for (int i = 0; i < SHP.size(); i++) {
							SHP[i] = SHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (SHP[i] < 0) {
								SHP[i] = 0;
							}
						}

						for (int i = 0; i < MHP.size(); i++) {
							MHP[i] = MHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (MHP[i] < 0) {
								MHP[i] = 0;
							}
						}

						for (int i = 0; i < RHP.size(); i++) {
							RHP[i] = RHP[i] - Multiplemissileslevel[MMLevel - 1].damage;
							if (RHP[i] < 0) {
								RHP[i] = 0;
							}
						}

						fuelleft = fuelleft - (6 + 2 * MMusingtime);
						MMusingtime++;
					}

					for (int i = 0; i < x; i++) {
						cout << "Snipertowers" << i + 1 << ":HP" << SHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < y; i++) {
						cout << "Mortars" << i + 1 << ":HP" << MHP[i] << endl;
					}
					cout << endl;
					for (int i = 0; i < z; i++) {
						cout << "Rocketlaunchers" << i + 1 << ":HP" << RHP[i] << endl;
					}
				}

				cout << endl;
				cout << "Troops go!!!" << endl;

				int Infantryremainingnumber = a1;
				int Heavyweaponguyremainingnumber = a2;
				int Tankremainingnumber = a3;
				int Helicopterremainingnumber = a4;

				int Snipertowersremainingnumber = 0;
				int Mortarsremainingnumber = 0;
				int Rocketlaunchersremainingnumber = 0;

				for (int i = 0; i < x; i++) {
					if (SHP[i] != 0) {
						Snipertowersremainingnumber++;
					}
				}

				

				for (int i = 0; i < y; i++) {
					if (MHP[i] != 0) {
						Mortarsremainingnumber++;
					}
				}


				for (int i = 0; i < z; i++) {
					if (RHP[i] != 0) {
						Rocketlaunchersremainingnumber++;
					}
				}
				

				while (((Infantryremainingnumber != 0) || (Heavyweaponguyremainingnumber != 0 || (Tankremainingnumber != 0) || (Helicopterremainingnumber != 0))) && ((Mortarsremainingnumber != 0) || (Snipertowersremainingnumber != 0) || (Rocketlaunchersremainingnumber != 0))) {
					//Checking for the enemy side


					int attacksidedamage = Infantryremainingnumber * Infantrylevel[InfLevel - 1].attackpower + Heavyweaponguyremainingnumber * Heavyweaponsguylevel[HWGLevel - 1].attackpower + Tankremainingnumber * Tanklevel[TKLevel - 1].attackpower + Helicopterremainingnumber * Helicopterlevel[HCLevel - 1].attackpower;
					for (int i = 0; i < x; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (SHP[i] > 0) {
							if (SHP[i] >= attacksidedamage) {
								SHP[i] = SHP[i] - attacksidedamage;
								break;
							}
							else if (SHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - SHP[i];
								SHP[i] = 0;
							}
						}
						else if (SHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < y; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (MHP[i] > 0) {
							if (MHP[i] >= attacksidedamage) {
								MHP[i] = MHP[i] - attacksidedamage;
								break;
							}
							else if (MHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - MHP[i];
								MHP[i] = 0;
							}
						}
						else if (MHP[i] == 0) {
							continue;
						}
					}

					for (int i = 0; i < z; i++) {
						if (attacksidedamage <= 0) {
							attacksidedamage = 0;
							break;
						}
						if (RHP[i] > 0) {
							if (RHP[i] >= attacksidedamage) {
								RHP[i] = RHP[i] - attacksidedamage;
								break;
							}
							else if (RHP[i] < attacksidedamage) {
								attacksidedamage = attacksidedamage - RHP[i];
								RHP[i] = 0;
							}
						}
						else if (RHP[i] == 0) {
							continue;
						}
					}

					Snipertowersremainingnumber = 0;
					for (int i = 0; i < x; i++) {
						if (SHP[i] != 0) {
							Snipertowersremainingnumber++;
						}

					}

					Mortarsremainingnumber = 0;
					for (int i = 0; i < y; i++) {
						if (MHP[i] != 0) {
							Mortarsremainingnumber++;
						}
					}

					Rocketlaunchersremainingnumber = 0;
					for (int i = 0; i < z; i++) {
						if (RHP[i] != 0) {
							Rocketlaunchersremainingnumber++;
						}
					}




					//Checking for our troop
					int defensivedamageindividual = Snipertowersremainingnumber * Boss.S.attackpower;
					int defensivedamageground = Mortarsremainingnumber * Boss.M.attackpower;//Since all the troops are on the ground
					int defensivedamageoverall = Rocketlaunchersremainingnumber * Boss.R.attackpower;
					//Snipertowers damage
					for (int j = 0; j < a2; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageindividual) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageindividual;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HeavyweaponguyHP[j];
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}


					for (int j = 0; j < a1; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageindividual) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageindividual;
								break;
							}
							else if (InfantryHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - InfantryHP[j];
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageindividual) {
								TankHP[j] = TankHP[j] - defensivedamageindividual;
								break;
							}
							else if (TankHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - TankHP[j];
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a4; j++) {
						if (defensivedamageindividual <= 0) {
							defensivedamageindividual = 0;
							break;
						}
						if (HelicopterHP[j] > 0) {
							if (HelicopterHP[j] >= defensivedamageindividual) {
								HelicopterHP[j] = HelicopterHP[j] - defensivedamageindividual;
								break;
							}
							else if (HelicopterHP[j] < defensivedamageindividual) {
								defensivedamageindividual = defensivedamageindividual - HelicopterHP[j];
								HelicopterHP[j] = 0;
							}
						}
						else if (HelicopterHP[j] == 0) {
							continue;
						}
					}

					//Mortars damage

					for (int j = 0; j < a2; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageground) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageground;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageground) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageground) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageground;
								break;
							}
							else if (InfantryHP[j] < defensivedamageground) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageground == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageground) {
								TankHP[j] = TankHP[j] - defensivedamageground;
								break;
							}
							else if (TankHP[j] < defensivedamageground) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					//Rocketlaunchers
					for (int j = 0; j < a2; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (HeavyweaponguyHP[j] > 0) {
							if (HeavyweaponguyHP[j] >= defensivedamageoverall) {
								HeavyweaponguyHP[j] = HeavyweaponguyHP[j] - defensivedamageoverall;
								break;
							}
							else if (HeavyweaponguyHP[j] < defensivedamageoverall) {
								HeavyweaponguyHP[j] = 0;
							}
						}
						else if (HeavyweaponguyHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a1; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (InfantryHP[j] > 0) {
							if (InfantryHP[j] >= defensivedamageoverall) {
								InfantryHP[j] = InfantryHP[j] - defensivedamageoverall;
								break;
							}
							else if (InfantryHP[j] < defensivedamageoverall) {
								InfantryHP[j] = 0;
							}
						}
						else if (InfantryHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a3; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (TankHP[j] > 0) {
							if (TankHP[j] >= defensivedamageoverall) {
								TankHP[j] = TankHP[j] - defensivedamageoverall;
								break;
							}
							else if (TankHP[j] < defensivedamageoverall) {
								TankHP[j] = 0;
							}
						}
						else if (TankHP[j] == 0) {
							continue;
						}
					}

					for (int j = 0; j < a4; j++) {
						if (defensivedamageoverall == 0) {
							break;
						}
						if (HelicopterHP[j] > 0) {
							if (HelicopterHP[j] >= defensivedamageoverall) {
								HelicopterHP[j] = HelicopterHP[j] - defensivedamageoverall;
								break;
							}
							else if (HelicopterHP[j] < defensivedamageoverall) {
								HelicopterHP[j] = 0;
							}
						}
						else if (HelicopterHP[j] == 0) {
							continue;
						}
					}


					Heavyweaponguyremainingnumber = 0;
					for (int j = 0; j < a2; j++) {
						if (HeavyweaponguyHP[j] != 0) {
							Heavyweaponguyremainingnumber++;
						}
					}

					Infantryremainingnumber = 0;
					for (int j = 0; j < a1; j++) {
						if (InfantryHP[j] != 0) {
							Infantryremainingnumber++;
						}
					}

					Tankremainingnumber = 0;
					for (int j = 0; j < a3; j++) {
						if (TankHP[j] != 0) {
							Tankremainingnumber++;
						}
					}

					Helicopterremainingnumber = 0;
					for (int j = 0; j < a4; j++) {
						if (HelicopterHP[j] != 0) {
							Helicopterremainingnumber++;
						}
					}

				}



				if (Infantryremainingnumber == 0 && Heavyweaponguyremainingnumber == 0 && Tankremainingnumber == 0 && Helicopterremainingnumber == 0) {
					cout << "Sorry, you lose in this battle, try again" << endl;
				}
				else if (Mortarsremainingnumber == 0 && Snipertowersremainingnumber == 0 && Rocketlaunchersremainingnumber == 0) {
					cout << "Congratulate, you win this battle" << endl;
					cout << "Please press Enter" << endl;
					string enter;
					cin >> enter;
					Bossdefeated = true;
				}
				for (int i = 0; i < troop.size(); i++) {
					troop[i] = 0;
				}
				spaceleft = LS[LSlevel - 1].Space;
			}

			cout << endl;
			if (Bossdefeated == false) {
				askfornewpage();
			}
		}

		else if (input1 == 54) {
			ofstream fout;
			fout.open("data.txt");

			if (fout.fail()) {
				cout << "Error in file opening!" << endl;
				exit(1);
			}

			//Headquarter level
			fout << Hlevel << endl;

			//Resources
			fout << R1.GoldCoins << endl;
			fout << R1.Steel << endl;

			//Landship
			fout << LSlevel << endl;

			//Troop
			fout << InfLevel << endl;
			fout << HWGLevel << endl;
			fout << TKLevel << endl;
			fout << HCLevel << endl;

			//Technology
			fout << MLevel << endl;
			fout << MMLevel << endl;
			fout.close();
			exit(0);

		}

		//You will lose the game if your coin is less than the searching cost
		if ((R1.GoldCoins < 50 * Hlevel) && Bossdefeated == false) {
			cout << endl;
			cout << "Sorry, you lose the whole game!" << endl;
			exit(0);
		}
		else if ((R1.GoldCoins >= 50 * Hlevel) && Bossdefeated == false) {
			cout << "Your input is: " << endl;
			cin >> input1;
		}

		else if (Bossdefeated == true) {
			continue;
		}
	}

	cout << "\033[2J\033[1;1H";
	cout << "---------------------------------------" << endl;
	cout << "-------You are the pirate king!--------" << endl;
	cout << "---------------------------------------" << endl;

	return 0;
}
