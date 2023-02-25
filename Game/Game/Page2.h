#pragma once
#include<iostream>
#include "Troops.h"
#include "Headquarter.h"
#include "Technology.h"
#include "Resources.h"
#include "Page1.h"
#include "IPage.h"
#include "Page3.h"
#include "Page4.h"
#include "Page5.h"
#include"Landship.h"
using namespace std;

void PrintPage2()//Info of troops
{
	cout << "                    Welcome to the troops introduction page                     " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";
	//Infantry info
	cout << "Level of Infantry: " << Infantrylevel[InfLevel - 1].level << endl;
	cout << "HP: " << Infantrylevel[InfLevel - 1].HP << endl;
	cout << "ATKPower: " << Infantrylevel[InfLevel - 1].attackpower << endl;
	cout << "Place: " << Infantrylevel[InfLevel - 1].placetake << endl;
	cout << "CoinsToImprove: " << Infantrylevel[InfLevel - 1].coinstoimprove << endl;
	cout << "CoinsNeeded: " << Infantrylevel[InfLevel - 1].goldcoinneeded << endl;
	//HWG info
	if (Hlevel >= 3) {
		cout << "\n";
		cout << "Level of HeavyWeaponGuy:" << Heavyweaponsguylevel[HWGLevel - 1].level << endl;
		cout << "HP:" << Heavyweaponsguylevel[HWGLevel - 1].HP << endl;
		cout << "ATKPower:" << Heavyweaponsguylevel[HWGLevel - 1].attackpower << endl;
		cout << "Place:" << Heavyweaponsguylevel[HWGLevel - 1].placetake << endl;
		cout << "CoinsToImprove:" << Heavyweaponsguylevel[HWGLevel - 1].coinstoimprove << endl;
		cout << "CoinsNeeded:" << Heavyweaponsguylevel[HWGLevel - 1].goldcoinneeded << endl;
	}

	//Tank info
	if (Hlevel >= 4) {
		cout << "\n";
		cout << "Level of Tank:" << Tanklevel[TKLevel - 1].level << endl;
		cout << "HP:" << Tanklevel[TKLevel - 1].HP << endl;
		cout << "ATKPower:" << Tanklevel[TKLevel - 1].attackpower << endl;
		cout << "Place:" << Tanklevel[TKLevel - 1].placetake << endl;
		cout << "CoinsToImprove:" << Tanklevel[TKLevel - 1].coinstoimprove << endl;
		cout << "CoinsNeeded:" << Tanklevel[TKLevel - 1].goldcoinneeded << endl;
	}
	//Helicopter info
	if (Hlevel >= 4) {
		cout << "\n";
		cout << "Level of Helicopter:" << Helicopterlevel[HCLevel - 1].level << endl;
		cout << "HP:" << Helicopterlevel[HCLevel - 1].HP << endl;
		cout << "ATKPower:" << Helicopterlevel[HCLevel - 1].attackpower << endl;
		cout << "Place:" << Helicopterlevel[HCLevel - 1].placetake << endl;
		cout << "CoinsToImprove:" << Helicopterlevel[HCLevel - 1].coinstoimprove << endl;
		cout << "CoinsNeeded:" << Helicopterlevel[HCLevel - 1].goldcoinneeded << endl;
	}
	cout << "________________________________________________________________________________" << endl;
	//


}

void TroopsUpgrade()
{
	char upginput;
	cout << "Please input an alphabat to choose a troop you will upgrade:" << endl;
	cout << "I stands for infantry, W stands for Heavyweaponguy, T stands for Tank, H stands for Helicopter" << endl;
	cin >> upginput;
	if (upginput == 73)//73 stands for H in ASCII code
	{
		if (R1.GoldCoins >= Infantrylevel[InfLevel - 1].coinstoimprove && Hlevel >= Infantrylevel[InfLevel - 1].headquarterlevelneeded && InfLevel < 4)
		{
			cout << "You have upgraded this troop successfully!" << endl;
			R1.GoldCoins = R1.GoldCoins - Infantrylevel[InfLevel - 1].coinstoimprove;
			cout << "Goldcoins remaining : " << R1.GoldCoins << endl;
			InfLevel = InfLevel + 1;
		}
		else if (R1.GoldCoins < Infantrylevel[InfLevel - 1].coinstoimprove)
		{
			cout << "You need more goldcoins to upgrade this troop!" << endl;
		}
		else if (Hlevel < Infantrylevel[InfLevel - 1].headquarterlevelneeded)
		{
			cout << "You have to upgrade your headquarter first!" << endl;
		}
		else if (InfLevel == 4)
		{
			cout << "This troop has reached it's max level!" << endl;
		}
	}
	else if (upginput == 87)//87 = W
	{
		if (R1.GoldCoins >= R1.GoldCoins - Heavyweaponsguylevel[HWGLevel - 1].coinstoimprove && Hlevel >= Heavyweaponsguylevel[HWGLevel - 1].headquarterlevelneeded && HWGLevel < 4)
		{
			cout << "You have upgraded this troop successfully!" << endl;
			R1.GoldCoins = R1.GoldCoins - Heavyweaponsguylevel[HWGLevel - 1].coinstoimprove;
			cout << "Goldcoins remaining : " << R1.GoldCoins << endl;
			HWGLevel = HWGLevel + 1;
		}
		else if (R1.GoldCoins < R1.GoldCoins - Heavyweaponsguylevel[HWGLevel - 1].coinstoimprove)
		{
			cout << "You need more goldcoins to upgrade this troop!" << endl;
		}
		else if (Hlevel < Heavyweaponsguylevel[HWGLevel - 1].headquarterlevelneeded)
		{
			cout << "You have to upgrade your headquarter first!" << endl;
		}
		else if (HWGLevel == 4)
		{
			cout << "This troop has reached it's max level!" << endl;
		}
	}
	else if (upginput == 84)//84 = T
	{
		if (R1.GoldCoins >= R1.GoldCoins - Tanklevel[TKLevel - 1].coinstoimprove && Hlevel >= Tanklevel[TKLevel - 1].headquarterlevelneeded && TKLevel < 3)
		{
			cout << "You have upgraded this troop successfully!" << endl;
			R1.GoldCoins = R1.GoldCoins - Tanklevel[TKLevel - 1].coinstoimprove;
			cout << "Goldcoins remaining : " << R1.GoldCoins << endl;
			TKLevel = TKLevel + 1;
		}
		else if (R1.GoldCoins < R1.GoldCoins - Tanklevel[TKLevel - 1].coinstoimprove)
		{
			cout << "You need more goldcoins to upgrade this troop!" << endl;
		}
		else if (Hlevel < Tanklevel[TKLevel - 1].headquarterlevelneeded)
		{
			cout << "You have to upgrade your headquarter first!" << endl;
		}
		else if (TKLevel == 3)
		{
			cout << "This troop has reached it's max level!" << endl;
		}
	}
	else if (upginput == 72)//72 = H
	{
		if (R1.GoldCoins >= R1.GoldCoins - Helicopterlevel[HCLevel - 1].coinstoimprove && Hlevel >= Helicopterlevel[HCLevel - 1].headquarterlevelneeded && HCLevel < 2)
		{
			cout << "You have upgraded this troop successfully!" << endl;
			R1.GoldCoins = R1.GoldCoins - Helicopterlevel[HCLevel - 1].coinstoimprove;
			cout << "Goldcoins remaining : " << R1.GoldCoins << endl;
			HCLevel = HCLevel + 1;
		}
		else if (R1.GoldCoins < R1.GoldCoins - Helicopterlevel[HCLevel - 1].coinstoimprove)
		{
			cout << "You need more goldcoins to upgrade this troop!" << endl;
		}
		else if (Hlevel < Helicopterlevel[HCLevel - 1].headquarterlevelneeded)
		{
			cout << "You have to upgrade your headquarter first!" << endl;
		}
		else if (HCLevel == 2)
		{
			cout << "This troop has reached it's max level!" << endl;
		}
	}
}
#pragma once
