/*
 * Player.cpp 
Emily 
 */

#include "Player.h"
#include <iostream>
#include <fstream> 
#include <string>

//*************** constructors and destructor ****************

/*
Constuctor
Asks for input and makes a file 
 */
Player::Player()
{
  fstream file;
  
  cout << "Please enter filename to save to: ";
  cin >> filename;
  //opens the file with given name
  //ios::out oepn for output operators
  //ios::out makes a file if ther is not one already
  file.open(filename.c_str(), ios::out); 
  
  cout << "Please enter player/character name: ";
  cout << "Please enter character race: ";
  cout << "Please enter character's class: ";
  cout << "Please enter how many actions character can make per turn: "; 

  cout << "Please enter armor class (AC): ";
  cout << "Please enter character's speed: ";
  cout << "Please enter character's hit point maximum: "; 
  
  cout << "Pleaser enter character strength: ";
  cout << "Pleaser enter character dexterity: ";
  cout << "Pleaser enter character constitution: ";
  cout << "Pleaser enter character intelligence: ";
  cout << "Pleaser enter character wisdom: ";
  cout << "Pleaser enter character charisma: ";
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
