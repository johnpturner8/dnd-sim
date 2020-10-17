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
	Enemy();
	virtual ~Enemy();
private:
	std::string filename;
};

#endif /* ENEMY_H_ */
