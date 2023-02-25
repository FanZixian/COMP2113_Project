#pragma once
//To give the technology data
//After using each technology once, the fuel cost of them will increase by 2.
//It will be achieved in the main function
int MLevel = 1;
int MMLevel = 1;
//Missles
struct Missles {
	int level;
	int headquarterlevelneeded;
	int Fuelneeded;//The fuel needs to use this technology
	int damage;//The attackpower that can reduce the building's HP
	int coinstoimprove;

};

Missles Missleslevel[4] = { {1,1,2,200,500},{2,2,2,400,2000},{3,4,2,650,5000},{4,0,2,900,0} };

//Multiple missilesa
struct Multiplemissiles {
	int level;
	int headquarterlevelneeded;
	int Fuelneeded;//The fuel needs to use this technology
	int damage;//The attackpower that can reduce the building's HP
	int coinstoimprove;

};

Multiplemissiles Multiplemissileslevel[3] = { {1,5,6,200,8000},{2,6,6,300,30000},{3,0,6,500,0} };
