#pragma once
#include<iostream>
#include "Troops.h"
#include "Headquarter.h"
#include "Technology.h"
#include "Resources.h"
#include "Page1.h"
#include "Page2.h"
#include "IPage.h"
#include "Page4.h"
#include "Page5.h"
#include"Landship.h"
using namespace std;

void PrintPage3()//Info of tech
{
	cout << "                        Welcome to the tech introduction page                   " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";
	//Missles info
	cout << "Level of Missles:" << Missleslevel[MLevel - 1].level << endl;
	cout << "FuelNeeded:" << Missleslevel[MLevel - 1].Fuelneeded << endl;
	cout << "DMG:" << Missleslevel[MLevel - 1].damage << endl;
	cout << "CoinsToImprove:" << Missleslevel[MLevel - 1].coinstoimprove << endl;
	cout << endl;

	//Multiplemissiles info
	if (Hlevel >= 4) {
		cout << "Level of Multiplemissiles:" << Multiplemissileslevel[MMLevel - 1].level << endl;
		cout << "FuelNeeded:" << Multiplemissileslevel[MMLevel - 1].Fuelneeded << endl;
		cout << "DMG:" << Multiplemissileslevel[MMLevel - 1].damage << endl;
		cout << "CoinsToImprove:" << Multiplemissileslevel[MMLevel - 1].coinstoimprove << endl;
		cout << endl;
	}
	else
	{
		cout << "Multiplemissiles are currently not available, not enough headquarter level!" << endl;
	}
	cout << "________________________________________________________________________________" << endl;
}

void TechUpgrade()
{
	char tupginput;
	cout << "Please input an alphabat to choose a technology you will upgrade:" << endl;
	cout << "m stands for Missles, M stands for Multiplemissiles" << endl;
	cin >> tupginput;
	if (tupginput == 109)//109 stands for m in ASCII code
	{
		if (R1.GoldCoins >= Missleslevel[MLevel - 1].coinstoimprove && Hlevel >= Missleslevel[MLevel - 1].headquarterlevelneeded && MLevel < 4)
		{
			R1.GoldCoins = R1.GoldCoins - Missleslevel[MLevel - 1].coinstoimprove;
			cout << "You have upgraded this technology successfully!" << endl;
			cout << "Goldcoins remaining : " << R1.GoldCoins << endl;
			MLevel = MLevel + 1;
		}
		else if (R1.GoldCoins < Missleslevel[MLevel - 1].coinstoimprove)
		{
			cout << "You need more goldcoins to upgrade this technology!" << endl;
		}
		else if (Hlevel < Missleslevel[MLevel - 1].headquarterlevelneeded)
		{
			cout << "You have to upgrade your headquarter first!" << endl;
		}
		else if (MLevel == 4)
		{
			cout << "This technology has reached it's max level!" << endl;
		}
	}
	else if (tupginput == 77)//77 = M
	{
		if (R1.GoldCoins >= R1.GoldCoins - Multiplemissileslevel[MMLevel - 1].coinstoimprove && Hlevel >= Multiplemissileslevel[MMLevel - 1].headquarterlevelneeded && MMLevel < 3)
		{
			cout << "You have upgraded this technology successfully!" << endl;
			R1.GoldCoins = R1.GoldCoins - Multiplemissileslevel[MMLevel].coinstoimprove;
			cout << "Goldcoins remaining : " << R1.GoldCoins << endl;
			MMLevel = MMLevel + 1;
		}
		else if (R1.GoldCoins < R1.GoldCoins - Multiplemissileslevel[MMLevel - 1].coinstoimprove)
		{
			cout << "You need more goldcoins to upgrade this technology!" << endl;
		}
		else if (Hlevel < Multiplemissileslevel[MMLevel - 1].headquarterlevelneeded)
		{
			cout << "You have to upgrade your headquarter first!" << endl;
		}
		else if (MMLevel == 3)
		{
			cout << "This technology has reached it's max level!" << endl;
		}
	}
}

