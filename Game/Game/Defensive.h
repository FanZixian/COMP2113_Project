#pragma once
#include<iostream>
using namespace std;

struct Snipertowers {
	int HP;
	int attackpower;
};

struct  Mortars {
	int HP;
	int attackpower;
};

struct Rocketlaunchers {
	int HP;
	int attackpower;
};


struct Defensive {
	struct Snipertowers S;
	struct Mortars M;
	struct Rocketlaunchers R;

};



