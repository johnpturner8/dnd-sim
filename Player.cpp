/*
 * Player.cpp 
Emily 
 */

#include "Player.h"
#include <string>

/*
Constuctor
Asks for input and makes a file 
 */
Player::Player() {

}

/*
Constuctor 
Opens a file and uses data from it 
 */
Player::Player(string fileName)
{
}

/*
Destructor 
 */
Player::~Player() {

}

//************** setter function **************

void Player :: setStr (int x)
{ str = x; }
void Player :: setDex (int x)
{ dex = x; }
void Player :: setCon (int x)
{ con = x; }
void Player :: setInt (int x)
{ intelligence = x; }
void Player :: setWis (int x)
{ wis = x; }
void Player :: setCha (int x)
{ cha = x; }

void Player :: setMaxHP (int x)
{ maxHP = x; }
void Player :: setCurrentHP(int x)
{ currentHP = x; } 

void Player :: setInitiative (int roll)
{ initative = roll; }


//*************** getter functions ***************

string Player :: getFileName()
{ return filename; }

int Player :: getStr()
{ return str; }
int Player :: getDex()
{ return dex; }
int Player :: getCon()
{ return con; }
int Player :: getInt()
{ return intelligence; }
int Player :: getWis()
{ return wis; }
int Player :: getCha()
{ return cha; }

int Player :: getMaxHP()
{ return maxHP; }
int Player :: getCurrentHP()
{ return currentHP; } 

int Player :: getInitiative()
{ return initative; }

string Player :: getName()
{ return name; }
string Player :: getRace()
{ return race; }
string Player :: getClass()
{ return playerClass; }
