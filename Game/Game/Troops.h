#pragma once
//To give the troop data
int InfLevel = 1;
int HWGLevel = 1;
int TKLevel = 1;
int HCLevel = 1;

//Infantry
struct Infantry {
	int HP;
	int attackpower;
	int level;
	int headquarterlevelneeded;//The headquarter level need to be greater or equal to than this number to improve infantry's level
	int placetake;//1 all the way
	int coinstoimprove;//The goins needed to improve to the next level.
	int goldcoinneeded;//The goins needed to make 1 unit infantry
};

Infantry Infantrylevel[4] = { {50,30,1,1,1,100,20},{100,50,2,2,1,500,20},{150,80,3,4,1,3000,20},{200,120,4,0,1,0,20} };

// Heavy weapons guy
struct Heavyweaponsguy {
	int HP;
	int attackpower;
	int level;
	int headquarterlevelneeded;//The headquarter level need to be greater or equal to than this number to improve Heavy weapons guy's level
	int placetake;// 3 all the way
	int coinstoimprove;//The goins needed to improve the level. For the first level, since we just obtain it, we do not need to spend goins
	int goldcoinneeded;//The goins needed to make 1 unit heavyweaponsguy
};

Heavyweaponsguy Heavyweaponsguylevel[4] = { {500,20,1,3,3,400,100},{800,30,2,5,3,1200,100},{1400,60,3,6,3,5000,100},{2200,90,4,0,3,0,100} };


//Tank
struct Tank {
	int HP;
	int attackpower;
	int level;
	int headquarterlevelneeded;//The headquarter level need to be greater or equal to than this number to improve Tank's level
	int placetake;// 5 all the way
	int coinstoimprove;//The goins needed to improve the level. For the first level, since we just obtain it, we do not need to spend goins
	int goldcoinneeded;//The goins needed to make 1 unit tank
};

Tank Tanklevel[3] = { {800,200,1,5,5,8000,400},{1500,400,2,6,5,20000,400},{2500,700,3,0,5,0,400} };


//Helicopter
struct Helicopter {
	int HP;
	int attackpower;
	int level;
	int headquarterlevelneeded;//The headquarter level need to be greater or equal to than this number to improve Helicopter's level
	int placetake;// 8 all the way
	int coinstoimprove;//The goins needed to improve the level. For the first level, since we just obtain it, we do not need to spend goins
	int goldcoinneeded;//The goins needed to make 1 unit helicopter
};

Helicopter Helicopterlevel[2] = { {1200,1200,1,7,8,40000,1000},{1500,2000,2,0,8,0,1000} };
