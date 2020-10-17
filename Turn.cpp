/*
 * Turn.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#include "Turn.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <iostream>
using namespace std;

Turn::Turn(Encounter e) {
	encounter = e;
	maxInit = 0;
}

void Turn::rollInit(){
	maxInit = 0;
	for(int i = 0; i < encounter.party.size(); i++){
		int init;
		cout << "Input initiative for " << encounter.party[i].getName() << ": ";
		cin >> init;
		if(init > maxInit)
			maxInit = init;
		encounter.party[i].setInitiative(init);
	}
	for(int i = 0; i < encounter.enemies.size(); i++){
		int init;
		cout << "Input initiative for " << encounter.enemies[i].getName() << ": ";
		cin >> init;
		encounter.party[i].setInitiative(init);
	}
}

void Turn::runRound(){
	for(int i = 0; i < maxInit; i++){
		for(int i = 0; i < encounter.party.size(); i++){
			if(encounter.party[i].getInitiative() == maxInit){
				runTurn(encounter.party[i]);
			}
		}
		for(int i = 0; i < encounter.enemies.size(); i++){
			if(encounter.enemies[i].getInitiative() == maxInit){
				runTurn(encounter.enemies[i]);
			}
		}
	}
}

void Turn::runTurn(Player p){

}

void Turn::runTurn(Enemy e){

}

void Turn::attack(){

}

void Turn::heal(){

}

void Turn::other(){

}

void Turn::reaction(){

}

Turn::~Turn() {
	// TODO Auto-generated destructor stub
}

