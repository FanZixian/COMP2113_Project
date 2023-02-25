# Comp2113-Group61
**Group members:
1.Jiang Yucheng 3035772391 BSc(Ac)
2.Fan Zixian 3035771610 BSc

# Topic: Island Conquer

# Dscription of the game:
//Background:
   This is an era of war, and the world is composed of islands. We need to get resources by attacking other islands, and finally become the most powerful one in the    world.
//Playing method:
   This is a single-player game.The player needs to use troops and technology, design offensive strategies to get through checkpoints of increasing difficulty, and then get rewarded for upgrading their troops and technology.

# Game Rules:
1. Victory/Defeated:
   In the beginning, we had a level 1 headquarters. We need to constantly improve the level of the headquarters to gain the ability to attack the enemy. The              headquarters has a total of 7 levels. If we can successfully reach level 7 and defeat the last enemy, we can win the game.
   Please note that this game is possible to lose, as long as your gold coins are not enough to support you to search for finding enemies and build troops!
   
2. Resources:
   There are 2 kinds of resources in the game: gold coins and steel. 
   After defeating the enemy, we will obtain these resources (different quantities). Searching for the enemy requires gold coins (the cost of searching for the enemy      under different levels of headquarters will be different), and the upgrading of many of our own things also needs to consume these resources. 

3. Basic rules: 
   Our attack and the enemy's defense are round-based. We always attack first.

4. We: Attacking side
   We have 2 kinds of things that can be used in the attack, one is troops, the other is technology.
   Troops:
   At headquarters level 1, level 3, level 4, and level 6, we will get different troops. They are infantry, heavy weapons guy, tank, and armed helicopter. They have      different HP and attack power, and what they can do can also be divided into single damage and group damage. It takes gold coins to make them. At the same time,        different arms need to occupy the space of our landing ship are limited, we can upgrade the level of landing ships to increase the number of arms we can carry.        Please note that soldiers will attack in order, and they will also be attacked in order.

   When we get them, they are all level one. We can upgrade them by consuming gold coins, so as to improve their HP and attack power. We can also upgrade our landing      ships as steel is needed to carry more arms.
   
   Landing ships have different levels:
   level 1: 10 space; level 2: 15 space; level 3: 20 space; level 4: 25 space; level 5: 30 space; level 6: 40 space; level 7: 50 space;

   Some details:
   Infantry: Take 1 place on the landing ship.
   Heavy weapons guy: Take 3 places on the landing ship.
   Tank: Take 5 places on the landing ship.
   Armed helicopter: Take 8 places on the landing ship.

   Orders: Heavy weapons guy, Infantry, Tank, Helicopter. 

   Technology:
   There are 2 kinds of technologies in total. They are missiles and multiple missiles. They will be obtained at levels 1 and 4 of the headquarters.

   Similarly, we need to use gold coins to upgrade them to get specific effects. We can use them at the beginning of any turn. At the same time, we have a limit on the    number of times we can use it in each battle. Fuel is our limiting factor. We can increase the total amount of our fuel by raising the level of the headquarters. 

   Some details:
   Missiles: A certain damage to a building. 2 Fuel consumption. 
   Multiple missiles: Damage to all buildings. 5 Fuel consumption.

   We can check their information at any time before the battle. Please note that all of them will die if they are put in one battle.
   
5. Enemy: Defend side:
   Our enemies have defensive buildings. We can only win if we resist their attack and destroy all of them.
   At different base camp levels, we will randomly encounter enemies in different difficulty ranges, and they will also have a different range of resource rewards.        They have a total of three defense buildings, namely sniper towers, mortars, rocket launchers. We not only change the number of them but also change their HP and      attack power. You will lose soldiers in the battle with them. After you get to the 7 level of headquarter, you will meet the final boss!

   Some details: 
   Sniper towers: Attack the nearest target one.
   Mortars: Attack the troops on the ground.
   Rocket launchers: Attack all the troops.

   For enemies of different levels, the number of their buildings varies in a random range.
   
6. Data summary for checking:
   Troops:
         Infantry: (Space take: 1; Coins need to make 1: 20)
               Level 1: HP: 50; attackpower: 30. Headquarterlevel required to improve: 1. Coins required to improve: 100.
               Level 2: HP: 70; attackpower: 40. Headquarterlevel required to improve: 2. Coins required to improve: 500.
               Level 3: HP: 100; attackpower: 55. Headquarterlevel required to improve: 4. Coins required to improve: 3000.
               Level 4(Highest): HP: 130; attackpower: 75
               
         Heavyweaponsguy: (Space take: 3; Coins need to make 1: 100; Obtained when Headquarterlevel is 3) 
               Level 1: HP: 500; attackpower: 10. Headquarterlevel required to improve: 3. Coins required to improve: 400.
               Level 2: HP: 800; attackpower: 20. Headquarterlevel required to improve: 5. Coins required to improve: 1200.
               Level 3: HP: 1400; attackpower: 45. Headquarterlevel required to improve: 6. Coins required to improve: 5000.
               Level 4(Highest): HP: 2200; attackpower: 60
               
         Tank: (Space take: 5; Coins need to make 1: 400; Obtained when Headquarterlevel is 4)
               Level 1: HP: 800; attackpower: 200. Headquarterlevel required to improve: 4. Coins required to improve: 8000.
               Level 2: HP: 1500; attackpower: 400. Headquarterlevel required to improve: 5. Coins required to improve: 20000.
               Level 3(Highest): HP: 2500; attackpower: 700
               
         Helicopter: (Space take: 8; Coins need to make 1: 1000; Obtained when Headquarterlevel is 6) (Won't be hurt by Mortars)
               Level 1: HP: 1200; attackpower: 1200. Headquarterlevel required to improve: 7. Coins required to improve: 40000.
               Level 2(Highest): HP: 1800; attackpower: 2000
   
   Technology: (After using each technology once, the fuel cost of them will increase by 2)
         Missles: (Initial fuel cost = 2)
               Level 1: Damage: 200. Headquarterlevel required to improve: 1. Coins required to improve: 500.
               Level 2: Damage: 400. Headquarterlevel required to improve: 2. Coins required to improve: 2000.
               Level 3: Damage: 650. Headquarterlevel required to improve: 2. Coins required to improve: 5000.
               Level 4(Highest): Damage: 900.
               
         Multiple missles: (Initial fuel cost = 6; Obtained when Headquarterlevel is 4)
               Level 1: Damage: 200. Headquarterlevel required to improve: 5. Coins required to improve: 8000.
               Level 2: Damage: 300. Headquarterlevel required to improve: 6. Coins required to improve: 30000.
               Level 3(Highest): Damage: 500.

 # Install and Implementation:
 Please use these commands to run in X2Go or SSH. Please create a Makefile including these commands.
 
 FLAGS = -pedantic-errors -std=c++11
 
 Game.o: Game.cpp Defensive.h Headquarter.h IPage.h Landship.h Page1.h Page2.h Page3.h Page4.h Page5.h Resources.h Technology.h Troops.h
 	g++ $(FLAGS) -c $<

Game: Game.o
	g++ $(FLAGS) $^ -o $@

clean: rm -f *.o main

.PHONY: clean
 
 


# List of features and coding requirements:
1. Generation of random game sets or events:
   For every level of enemy, we will design several sets of their defensive buildings(including the final boss). In every game we will use random number to choose a 
   unique set.
   
   Code example:
   
   //Game.cpp 
   
```
else if (Hlevel == 6) {
int x = ((rand() % 5) + 4); //x represents the number of Snipertowers
int y = ((rand() % 3) + 2); //y represents the number of Mortars
int z = ((rand() % 2) + 2); //z represents the number of Rocketlaunchers
cout << "The enemy has " << x << " Snipertowers: HP: " << D6.S.HP << " ; attackpower: " << D6.S.attackpower << endl;
cout << "The enemy has " << y << " Mortars: HP: " << D6.M.HP << " ; attackpower: " << D6.M.attackpower << endl;
cout << "The enemy has " << z << " Rocketlaunchers: HP: " << D6.R.HP << " ; attackpower: " << D6.R.attackpower << endl;
```
   
2. Data structures for storing game status:
   We have used two types of data structures to represent different information. 
   The first data type is our resources(including gold coins and steel). These two resources will be shown continuously during the game and will be altered every time 
   after defeating an enemy. 
   
   Code example:
   
   //Resources.h line 7 to 11
   
   ```
   struct Resources {
	int GoldCoins;
	int Steel;
   };
   Resources R1 = { 1000,0 };//Set up the initial goldcoins = 1000 and initial steel = 0
   ```
   
   The second data type is the data generated during the game, including HP of our troops and enemy buildings, fuel remaining(for using 
   technologies) and space of our landing ship(for checking remaining available troops).
   We  use array and vector to achieve these needs.
   Code example:
   //Example1 -> Game.cpp
   ```
   vector<int> troop;
	troop.push_back(0);
	int spaceleft = LS[LSlevel - 1].Space;//This function is used to store troop and calculate the space left in landship```
   
   //Example2 -> Game.cpp 
	```vector<int> SHP;
	for (int i = 0; i < x; i++) {
	SHP.push_back(D1.S.HP);}
	vector<int> InfantryHP;
	int a1 = troop[0];//The Infantry number
	for (int i = 0; i < a1; i++) {
	InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);}
	//This function is used to store in-battle data such as infantry HP and Sniper Tower HP(SHP)```
3. Dynamic memory management:

   We will conduct dynamic memory management when setting up arms. We can remove arms as well.
   
   Code example:
   
   //Example1 -> Game.cpp 
   
   ```
   cout << "Do you want to remove yout troops: Y/N" << endl;
   string remove;
   cin >> remove;
   if (remove == "Y") {
   for (int i = 0; i < troop.size(); i++) {
   if (i == 0) {R1.GoldCoins = R1.GoldCoins + troop[i] * Infantrylevel[InfLevel - 1].goldcoinneeded;}
   else if (i == 1) {R1.GoldCoins = R1.GoldCoins + troop[i] * Heavyweaponsguylevel[HWGLevel - 1].goldcoinneeded;}
   else if (i == 2) {R1.GoldCoins = R1.GoldCoins + troop[i] * Tanklevel[TKLevel - 1].goldcoinneeded;}
   else if (i == 3) {R1.GoldCoins = R1.GoldCoins + troop[i] * Helicopterlevel[HCLevel - 1].goldcoinneeded;}
   troop[i] = 0;}
   spaceleft = LS[LSlevel - 1].Space;
   //These lines show the progress of remove troops and release storage
    ```
                                                   
4. File input/output (e.g., for loading/saving game status):

   When the battle begins or ends, we will read a text file storing the data of gold coins and steel. Either we win or lose the battle, the number of gold coins will 
   be changed. After each battle, we have to train new troops or upgrade them as well as technologies(hence we will consume steel).
   
   Code Example:
   
   //Game.cpp 
   ```
   else if (Mortarsremainingnumber == 0 && Snipertowersremainingnumber == 0) {
   cout << "Congratulate, you win this battle" << endl;
   cout << "Here is your bonus: Coin: 3000; Steel: 150" << endl;
   R1.GoldCoins = R1.GoldCoins + 3000;
   R1.Steel = R1.Steel + 150;
   //After winning the battle, we go to Resources.h and modify the goldcoins and steel
   ```
                                                                           
5. Program codes in multiple files:

   All of the functions have been separated into different files. Each file contains one or more functions depending on the task that they perform.
   
   Code example:
   
   //Page2.h 
   
   ```
   #include<iostream>
   //other includes are omitted because there's no need to show the detailed code here
   using namespace std;
   void PrintPage2()//Info of troops
   void TroopsUpGrade()//The function to upgrade the troops
   //Also, the contents inside the functions are omitted.
   ```
	
   
6. Proper indentation and naming styles:

   We will use appropriate name for the variables to make it readable. And we will use visual studio to adjust the indentation.
   
   Code Example:
   
   //Game.cpp
   ```
   void askfornewpage()//To let the player choose next page to go
   ```
	
   //Game.cpp 
   ```
   void checkdefeat()//After the player spent his goldcoin, check if his goldcoin are insufficient for the next search(and he lose the game)
   ```
   
   
7. In-code documentation:

   In-text comments will be provided to make the code readable.
   
   Code example:
	
   //Game.cpp 
   ```//Searching cost
   cout << "The cost of search is: " << 50 * Hlevel << endl;
   R1.GoldCoins = R1.GoldCoins - 50 * Hlevel;
   cout << "Your coin now is: " << R1.GoldCoins << endl;
   cout << "\n";
   //Showing the defensive
   if (Hlevel == 1) {
   int x = ((rand() % 2) + 1); //x represents the number of Snipertowers
   cout << "The enemy has " << x << " Snipertowers: HP: " << D1.S.HP << " ; attackpower: " << D1.S.attackpower << endl;
   //Buildings' HP vector
   vector<int> SHP;
   for (int i = 0; i < x; i++) {
   SHP.push_back(D1.S.HP);}
   vector<int> InfantryHP;
   int a1 = troop[0];//The Infantry number
   for (int i = 0; i < a1; i++) {
   InfantryHP.push_back(Infantrylevel[InfLevel - 1].HP);}
