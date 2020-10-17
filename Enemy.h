/*
 * Enemy.h
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include <string>
#include <vector>
using namespace std;

class Enemy {
public:
	Enemy(void); //Prompts user for Enemy information
	Enemy(string filename); //Loads Enemy from file
	virtual ~Enemy(); //destructor
	//functions to get basic stats

	int roll(int dice); //simulates a dice role by generating a random number % dice

	bool hits (int arkRoll); //returns if the attack role hits
	void takeDamage(int damage); //checks to see Enemy died also
	bool death (int); //returns true of Enemy dies
	void getHealed (int health);//Heals Enemy by increasing current HP
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
	//Info found in Enemy file
	string filename;
	
	string name;
	string race;
	string EnemyClass;
	int actPerTurn; //how many actions per turn

	int ac; //armor class
	int speed; //speed
	int maxHP;
	
	int str, dex, con, intelligence, wis, cha; //Basic ability stats

	//Info not in Enemy file
	int currentHP;
	int deathSave; //Character dies when this hits 0
	int initative; //initative for role order
	vector <string> status;

};

#endif /* ENEMY_H_ */
