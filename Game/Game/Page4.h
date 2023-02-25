#pragma once
#include<iostream>
#include "Troops.h"
#include "Headquarter.h"
#include "Technology.h"
#include "Resources.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
#include "IPage.h"
#include "Page5.h"
#include"Landship.h"
using namespace std;

void PrintPage4()// See/Modify troops 
{
	cout << "                         Welcome to the troop modifying page                    " << endl;
	cout << "                           You can train your troop here                        " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";
	cout << "The level of landship is " << LS[LSlevel - 1].level << endl;
	cout << "The space of landship is " << LS[LSlevel - 1].Space << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "\n";






}
