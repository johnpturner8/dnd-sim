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
	int getStr(); int getDex(); int getCon(); int getInt(); int getWis(); int getCha();
	string getName();
	string getRace();
	string getClass(); 
	int getInitiative();
	
	
	void setStr(int); void setDex(int); void setCon (int);
        void setInt(int); void setWis(int); void setCha(int); 
	void setInitiative(int roll); //Sets the iniative
	void addStatus(string); void removeStatus(string); void removeStatus(int); 

	int roll(int dice); //simulates a dice role by generating a random number % dice

	bool hits (int arkRoll); //returns if the attack role hits
	bool takeDamage(int damage); //checks to see player died also
	void getHealed (int health);//Heals player by increasing current HP
	//Also keeps it from going above maxHP

	int attack(); 
	int attack(int roll, int damage); //dmage includes the modifiers

	int heal (int health); //heals 

private:
	int str, dex, con, intelligence, wis, cha; //Basic ability stats
	int maxHP, currentHP; //Hit points 
	int ac; //armor class
	int speed; //speed
	int initative; //initative for role order
	int actPerTurn; //how many actions per turn 
	
	string name; 
	string race;
	string playerClass;
	
	vector <string> status; 
       
	string filename;
	
};

#endif /* PLAYER_H_ */
