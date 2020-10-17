/*
 * Turn.h
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#ifndef TURN_H_
#define TURN_H_
#include "Encounter.h"
#include "Player.h"
#include "Enemy.h"

class Turn {
public:
	Turn(Encounter e);
	virtual ~Turn();
	void rollInit();
	void runRound();
	void runTurn(Player p);
	void attack();
	void heal();
	void other();
	void reaction();
private:
	Encounter encounter;
	int curTurn;
};

#endif /* TURN_H_ */
