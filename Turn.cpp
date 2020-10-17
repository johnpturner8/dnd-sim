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
	cout << p.getName() << "'s turn." << endl;
	if(!p.hasStatus("Unconscious") && !p.death()){ //CHECK THIS LATER
		int input = 0;
		do{
			cout << "Select an option:" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Heal" << endl;
			cout << "3: Other" << endl;
			cout << "4: Trigger Reaction" << endl;
			cout << "5: End Turn" << endl;

			input = 0;
			cin >> input;

			cin.clear();
		    cin.ignore(9999, '\n');

			switch(input){
			case 1:
				attack();
				break;
			case 2:
				heal();
				break;
			case 3:
				other();
				break;
			case 4:
				reaction();
				break;
			case 5:
				break;
			default:
				cout << "Invalid Input." << endl;
				break;
			}
		}while (input != 5);
	}
	else if (p.hasStatus("Unconscious")){
		cout << p.getName() << " is downed." << endl;
		// *** PRINT DEATH SAVES ***
		cout << "Enter death saving throw result: " << endl;
		int deathSave;
		cin >> deathSave;
		// *** TODO ENTER DEATH SAVE ***
		if(p.death()) // *** TODO update method name
			encounter.removePlayer(p);
	}
}

void Turn::runTurn(Enemy e){
	cout << e.getName() << "'s turn." << endl;
	if(!e.death()){ //CHECK THIS LATER
		int input = 0;
		do{
			cout << "Select an option:" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Heal" << endl;
			cout << "3: Other" << endl;
			cout << "4: Trigger Reaction" << endl;
			cout << "5: End Turn" << endl;

			input = 0;
			cin >> input;

			cin.clear();
			cin.ignore(9999, '\n');

			switch(input){
			case 1:
				attack();
				break;
			case 2:
				heal();
				break;
			case 3:
				other();
				break;
			case 4:
				reaction();
				break;
			case 5:
				break;
			default:
				cout << "Invalid Input." << endl;
				break;
			}
		}while (input != 5);
	}
}

void Turn::attack(){
	cout << "Attacking" << endl;

	string name;
	bool redo = false;
	bool player = false;

	int ind;

	do{
		redo = false;
		cout << "\t" << "Enter Target Name." << endl << "\t";
		getline(cin, name);
		ind = encounter.getEnemyIndex(name);
		player = false;
		if(ind == -1){
			ind = encounter.getPlayerIndex(name);
			player = true;
		}
		if(ind == -1){
			cout << "\t" << "Not a valid target." << endl;
			redo = true;
		}
	}while(redo);
	int damage;
	cout << "Enter damage: ";
	cin >> damage;
	if(player){
		encounter.getPlayer(ind).takeDamage(damage);
	}
	else{
		encounter.getEnemy(ind).takeDamage(damage);
	}
}

void Turn::heal(){
	cout << "Healing" << endl;

	string name;
	bool redo = false;
	bool player = false;

	int ind;

	do{
		cout << "\t" << "Enter Target Name." << endl << "\t";
		getline(cin, name);

		ind = encounter.getEnemyIndex(name);
		player = false;
		if(ind == -1){
			ind = encounter.getPlayerIndex(name);
			player = true;
		}
		if(ind == -1){
			cout << "\t" << "Not a valid target." << endl;
			redo = true;
		}

	}while(redo);
	int healing;
	cout << "Enter healing: ";
	cin >> healing;
	if(player){
		encounter.getPlayer(ind).getHealed(healing);
	}
	else{
		encounter.getEnemy(ind).getHealed(healing);
	}
	cout << endl;
}

void Turn::other(){
	int input = 0;
	do{
		cout << "Select an option:" << endl;
		cout << "1: Apply Status" << endl;
		cout << "2: Remove Status" << endl;
		cout << "3: Back" << endl;

		input = 0;
		cin >> input;

		cin.clear();
		cin.ignore(9999, '\n');

		switch(input){
		case 1:
		{
			string name;
			bool redo = false;
			bool player = false;
			int ind;
			do{
				cout << "\t" << "Enter Target Name." << endl << "\t";
				getline(cin, name);

				ind = encounter.getEnemyIndex(name);
				player = false;
				if(ind == -1){
					ind = encounter.getPlayerIndex(name);
					player = true;
				}
				if(ind == -1){
					cout << "\t" << "Not a valid target." << endl;
					redo = true;
				}

			}while(redo);

			cout << "Enter the status: ";
			string status;
			cin >> status;

			if(player){
				encounter.getPlayer(ind).addStatus(status);
			}
			else{
				encounter.getEnemy(ind).addStatus(status);
			}
			break;
		}
		case 2:
		{
			string name;
			bool redo = false;
			bool player = false;
			int ind;
			do{
				cout << "\t" << "Enter Target Name." << endl << "\t";
				getline(cin, name);

				ind = encounter.getEnemyIndex(name);
				player = false;
				if(ind == -1){
					ind = encounter.getPlayerIndex(name);
					player = true;
				}
				if(ind == -1){
					cout << "\t" << "Not a valid target." << endl;
					redo = true;
				}

			}while(redo);

			if(player){
				encounter.getPlayer(ind).printStatus();
			}
			else{
				encounter.getEnemy(ind).printStatus();
			}

			string status;
			do{
				cout << endl << "Enter the status to remove or enter quit to exit: ";
				cin >> status;
				if(player){
					if(encounter.getPlayer(ind).hasStatus(status)){
						encounter.getPlayer(ind).removeStatus(status);
						status = "quit";
					}
					else
						cout << "Status not found." << endl;
				}
				else{
					if(encounter.getEnemy(ind).hasStatus(status)){
						encounter.getEnemy(ind).removeStatus(status);
						status = "quit";
					}
					else
						cout << "Status not found." << endl;
				}
			}while(status != "quit");

			break;
		}
		case 3:
			break;
		default:
			cout << "Invalid Input." << endl;
			break;
		}
	}while (input != 1 && input != 2 && input != 3);
}

void Turn::reaction(){
	string name;
	bool redo = false;
	bool player = false;
	int ind;
	do{
		cout << "\t" << "Enter Reaction Taker's Name." << endl << "\t";
		getline(cin, name);

		ind = encounter.getEnemyIndex(name);
		player = false;
		if(ind == -1){
			ind = encounter.getPlayerIndex(name);
			player = true;
		}
		if(ind == -1){
			cout << "\t" << "Not a valid target." << endl;
			redo = true;
		}
	}while(redo);

	if(player){
		runTurn(encounter.getPlayer(ind));
	}
	else{
		runTurn(encounter.getEnemy(ind));
	}
}

Turn::~Turn() {
	// TODO Auto-generated destructor stub
}

