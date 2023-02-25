#pragma once
#include<iostream>
#include "Troops.h"
#include "Headquarter.h"
#include "Technology.h"
#include "Resources.h"
#include "IPage.h"
#include "Page2.h"
#include "Page3.h"
#include "Page4.h"
#include "Page5.h"
#include"Landship.h"
using namespace std;

void PrintPage1()//Page 1 contains all the elements that initial page has + the goin required to upgrade headquarter
{
	cout << "                              Welcome to the Main Menu                          " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";
	cout << "The level of headquarter is : " << headquarterlevel[Hlevel - 1].level << endl;//数组的第0项对应1级
	cout << "You have " << R1.GoldCoins << " goldcoins now" << endl;
	cout << "You have " << R1.Steel << " steel now" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";

}
#pragma once
