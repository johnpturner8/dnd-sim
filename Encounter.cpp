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
#include <fstream>
#include <sstream>

using namespace std;

Encounter::Encounter() {
	// TODO Auto-generated constructor stub

}

Encounter::~Encounter() {
	// TODO Auto-generated destructor stub
}

/*Encounter::Encounter(string fileName){
  ifstream inFile;
  string name, nextEntry;
  bool firstPlayer = 1;

  inFile.open(fileName.c_str());

  while(!inFile.eof()){
    inFile >> name;
    if (name == "Players"){
      inFile >> nextEntry;
      while(nextEntry != "Enemies" && !inFile.eof())
	{
	  do{
	    Player p(nextEntry);
	    party.push_back(p);
	    firstPlayer = 0;
	  }while(firstPlayer);
	  
	  inFile >> nextEntry;
	  Player x(nextEntry);
	  party.push_back(x);
	  
	  inFile >> nextEntry;
	}
    }
    
    if (nextEntry == "Enemies"){
      while(!inFile.eof()){
	inFile >> nextEntry;
	Enemy y(nextEntry);
	enemies.push_back(y);
      }
    }
  }

  inFile.close();
}
*/

//Adds player to the party vector
void Encounter::addPlayer(Player a){
  party.push_back(a);
}

//Removes player from party vector
void Encounter::removePlayer(Player a){
  for (int i = 0; i < party.size(); i++)
    {
      if(party[i].getName() == a.getName()){
	party.erase(party.begin() + i);
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
      if(enemies[i].getName() == a.getName()){
	enemies.erase(enemies.begin() + i);
      }
    }
}

//Returns player at a given index
Player Encounter::getPlayer(int playerInt){
  if(playerInt < party.size())
    return party[playerInt];
  else
    return party[party.size()-1];
}

//Returns player of given string or the last player in the vector if that player does not exist
Player Encounter::getPlayer(string playerName){
  for (int i = 0; i < party.size(); i++){
    if(party[i].getName() == playerName)
      return party[i];
  }
  return party[party.size()-1];
}

int Encounter::getPlayerIndex(string playerName){
  for(int i = 0; i < party.size(); i++){
    if (party[i].getName() == playerName){
      return i;
    }
    else
      {
	cout << "Invalid Player Name" << endl;
	return -1;
      }
  }
}

//Returns enemy at a given index
Enemy Encounter::getEnemy(int enemyInt){
  if(enemyInt < enemies.size())
    return enemies[enemyInt];
  else
    return enemies[enemies.size()-1];
}

//Returns enemy of a given name
Enemy Encounter::getEnemy(string enemyName){
  for (int i = 0; i < enemies.size(); i++){
    if(enemies[i].getName() == enemyName)
      return enemies[i];
    }
  return enemies[enemies.size()-1];

}

int Encounter::getEnemyIndex(string enemyName){
  for (int i = 0; i < enemies.size(); i++){
    if(enemies[i].getName() == enemyName)
      return i;
    else
      {
	cout << "Invalid enemy name" << endl;
	return -1;
      }
  }
}
