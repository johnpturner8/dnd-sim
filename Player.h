/*
 Player.h
10/17/2020
Emily and John 
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <vector>
using namespace std; 

class Player {
public:
	Player(); //Prompts user for player information
	Player(string filename); //Loads player from file
	virtual ~Player(); //destructor
	//functions to get basic stats

	int roll(int dice); //simulates a dice role by generating a random number % dice

	bool hits (int arkRoll); //returns if the attack role hits
	void takeDamage(int damage); //checks to see player died also
	bool death (int); //returns true of player dies
	void getHealed (int health);//Heals player by increasing current HP
	//Also retests deathSave back to 0
	//Also keeps it from going above maxHP

	int attack();
	int attack(int roll, int damage); //dmage includes the modifiers
	int heal (int health); //heals
	
	string getFileName(); 
	int getStr(); int getDex(); int getCon(); int getInt(); int getWis(); int getCha();
	int getMaxHP(); int getCurrentHP();
	int getInitiative();
	string getName();
	string getRace();
	string getClass(); 
		
	void setStr(int); void setDex(int); void setCon (int);
        void setInt(int); void setWis(int); void setCha(int);

	void setMaxHP(int); void setCurrentHP(int); 

	void setInitiative(int roll); //Sets the iniative

	void addStatus(string); void removeStatus(string); void removeStatus(int);
	void printStatus(); bool hasStatus(string); 
	
private:
	//Info found in player file 
	string filename; 
	
	string name;
	string race;
	string playerClass;
	int actPerTurn; //how many actions per turn

	int ac; //armor class
	int speed; //speed
	int maxHP;
	
	int str, dex, con, intelligence, wis, cha; //Basic ability stats

	//Info not in player file
	int currentHP;
	int deathSave; //Character dies when this hits 0 
	int initative; //initative for role order
	vector <string> status; 
       	
};

#endif /* PLAYER_H_ */
