/*
 * Encounter.h
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */

#ifndef ENCOUNTER_H_
#define ENCOUNTER_H_

#include <Player.h>
#include <Enemy.h>

#include <vector>
#include <fstream>

class Encounter {
 public:
  Encounter();
  Encounter(ifstream);
  virtual ~Encounter();
  
  void removePlayer(Player);
  void removeEnemy(Enemy);
  void addPlayer(Player);
  void addEnemy(Enemy);
  
 private:
  vector<Player> party;
  vector<Enemy> enemies;
  
};

#endif /* ENCOUNTER_H_ */
