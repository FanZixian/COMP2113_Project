#pragma once
#include<string>

int LSlevel = 1;

struct Landship {
	int level;
	int Space;
	int Steelneededtoimprove;
};

Landship LS[7] = { {1,10,50},{2,15,150},{3,20,300},{4,25,500},{5,30,800},{6,40,1500},{7,50,0} };

void UpgradeLandship()
{
	if (LSlevel == 7)
	{
		cout << "The Landshiplevel has reached its max level" << endl;
	}
	else
	{
		LSlevel = LSlevel + 1;
	}

}
