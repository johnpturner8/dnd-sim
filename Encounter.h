/*
 * Encounter.h
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#ifndef ENCOUNTER_H_
#define ENCOUNTER_H_

#include "Player.h"
#include "Enemy.h"


#include <vector>
#include <fstream>

using namespace std;

class Encounter {
 public:
  Encounter();
  Encounter(string filename);
  virtual ~Encounter();
  
  void removePlayer(Player); //Removes players from the player vector
  void removeEnemy(Enemy); //Removes enemies from enemy vector 
  void addPlayer(Player); //Adds players to player vector
  void addEnemy(Enemy); // Adds enemies to enemy vector
  Player getPlayer(int); // Returns player object at a given index
  Player getPlayer(string); // Returns player object given a name
  Enemy getEnemy(int); // Returns enemy object at a given index
  Enemy getEnemy(string); // Returns enemy object given a name
  friend class Turn;
  
 private:
  vector<Player> party;
  vector<Enemy> enemies;
  
};

#endif /* ENCOUNTER_H_ */
