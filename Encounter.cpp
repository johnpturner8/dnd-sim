/*
 * Encounter.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#include "Encounter.h"
#include "Player.h"
#include "Enemy.h"

#include <vector>
#include <iostream>

using namespace std;

Encounter::Encounter() {
	// TODO Auto-generated constructor stub

}

Encounter::~Encounter() {
	// TODO Auto-generated destructor stub
}

//Adds player to the party vector
void Encounter::addPlayer(Player a){
  party.push_back(a);
}

//Removes player from party vector
void Encounter::removePlayer(Player a){
  for (int i = 0; i < party.size(); i++)
    {
      if(party[i] == a){
	party.erase(i);
      }
    }

}

//Adds enemy to enemies vector
void Encounter::addEnemy(Enemy a){
  enemies.push_back(a);
}

//Removes enemy from enemies vector
void Encounter::removeEnemy(Enemy a){
  for (int i = 0; i < enemies.size(); i++)
    {
      if(enemy[i] == a){
	enemies.erase(i);
      }
    }
}

//Returns player at a given index
Player Encounter::getPlayer(int playerInt){
  return party[playerInt];
}

//Returns player of given string
Player Encounter::getPlayer(string playerName){
  for (int i = 0; i < party.size(); i++){
    if(party[i].getName() == playerName)
      return party[i];
    else{
      cout << "Invalid player name" << endl;
      return NULL;
    }
  }
}

int Encounter::getPlayerIndex(string playerName){
  for(int i = 0; i < party.size(); i++){
    if (party[i].getName() == playerName){
      return i;
    }
    else
      {
	cout << "Invalid Player Name" << endl;
	return NULL;
      }
  }
}

//Returns enemy at a given index
Enemy Encounter::getEnemy(int enemyInt){
  return enemies[enemyInt];
}

//Returns enemy of a given name
Enemy Encounter::getEnemy(string enemyName){
  for (int i = 0; i < enemies.size(); i++){
    if(enemies[i].getName() == enemyName)
      return enemies[i];
    else{
      cout << "Invalid enemy name" << endl;
      return NULL;
    }
  }
}

int Encounter::getEnemyIndex(string enemyName){
  for (int i = 0; i < enemies.size(); i++){
    if(enemies[i].getName() == enemyName)
      return i;
    else
      {
	cout << "Invalid enemy name" << endl;
	return NULL;
      }
  }
}
