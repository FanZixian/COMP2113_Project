#pragma once
//headquarters
#include "Troops.h"
#include "Technology.h"
#include<iostream>
using namespace std;

int Hlevel = 1;

struct Headquarter {
	int level;
	int Fuel;
	int coinstoimprove; //The goins needed to improve the level.For the first level, since we just obtain it, we do not need to spend goins

};

Headquarter headquarterlevel[7] = { {1,6,800},{2,9,2000},{3,12,4000},{4,16,8000},{5,20,15000},{6,24,30000}, {7,28,0} };

