#pragma once
#include<iostream>
#include "Troops.h"
#include "Headquarter.h"
#include "Technology.h"
#include "Resources.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
#include "Page4.h"
#include "Page5.h"
#include"Landship.h"

using namespace std;
void PrintInitialPage()//Print the initial page, the player can see gold and other resources he/she has this moment.
{
	cout << "                            Welcome to Island Conquer                           " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";
	cout << "The level of headquarter is : " << headquarterlevel[Hlevel - 1].level << endl;
	cout << "You have " << R1.GoldCoins << " goldcoins now" << endl;
	cout << "You have " << R1.Steel << " steel now" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";
}

