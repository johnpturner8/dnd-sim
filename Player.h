/*
 * Player.h
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

class Player {
public:
	Player(); //Prompts user for player information
	Player(string filename); //Loads player from file
	void damage(int damage); //damages player health
	void heal(int health); //heals player health
	int attack(); //rolls the players default attack
	int attack(int num, int dice); //rolls an attack with a different damage die
	int attack(int mod); //rolls an attack with a different modifier
	int attack(int num, int dice, int mod); //rolls an attack with a different damage die and modifier
	bool hits(int atkRoll) //returs true if the attack hits the player
	virtual ~Player();
private:
	int health;
	int damageMod;
	int attackMod;
	int AC;

	std::string filename;
};

#endif /* PLAYER_H_ */
