/*
 * Enemy.h
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include <string>

class Enemy {
public:
	Enemy(); //Constructor
	virtual ~Enemy(); //Destructor

	//Functions to get basic stats
	int getStr(); int getDex(); int getCon(); int getInt(); int getWis(); int getCha();
	string getName();
	string getRace();
	int getInitiative();

	void setStr(int); vod setDex(int); void setCon(int); 
	void setInt(int); void setWis(int); void setCha(int);
	void setInitiative(int roll); //Sets the initiative

	int roll(int dice); //Simulates a dice role by generating a random number % dice
	
	bool hits(int arkRoll); //Returns if the attack role hits
	bool takeDamage(int damage); //Checks to see if the player died also 
	void getHealed(int health); //Heals player by increasing current HP (also prevents from going over max HP)
	
	int attack();
	int attack(int roll, int damage); //Damage includes the modifiers
	
	int heal(int health); //Heals
	
private:
	std::string filename;
	int str, dex, con, intelligence, wis, cha; //Basic ability stats
	int maxHP, current HP; //Hit Points
	int ac; //Armor class
	int speed; //Speed
	int initiative; //Initiative for role order
	int actPerTurn; //How many actions per turn

	string name; //name of enmemy
	string race; //enemy race
};

#endif /* ENEMY_H_ */
