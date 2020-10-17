/*
 * Player.cpp 
Emily 
 */

#include "Player.h"
#include <iostream>
#include <fstream> 
#include <string>

//Purely here for testing, will delete later 
int main()
{
  Player pl;
  return 0;
}

//*************** constructors and destructor ****************

int validInputNum (string request, fstream &file, int lower, int upper); 
string validInputString(string request, fstream& file);

/*
Default constructor 
Makes a file
Sets member values based on user input and writes them to file 
to Call: Player playerObjectName;
Calls int validInputNum (string request, fstream &file, int lower, int upper) and 
string validInputString(string request)
 */
Player::Player(void)
{
  fstream file;
  
  cout << "Please enter filename to save to: ";
  cin >> filename;
  //opens the file with given name
  //ios::out oepn for output operators
  //ios::out makes a file if ther is not one already
  file.open(filename.c_str(), ios::out); 
  
  cout << "Please enter player/character name: ";
  name = validInputString("NAME: ", file); 
  cout << "Please enter character race: ";
  race = validInputString("RACE: ", file);
  cout << "Please enter character's class: ";
  playerClass = validInputString("CLASS: ", file); 
  cout << "Please enter how many actions character can make per turn: ";
  actPerTurn = validInputNum("NUMBER_OF_ACTIONS_PER_TURN: ", file, 0, 5); 
  
  cout << "Please enter armor class (AC): ";
  ac = validInputNum("ARMOR_CLASS: ", file, 0, 30);
  cout << "Please enter character's speed: ";
  speed = validInputNum("SPEED: ", file, 0, 30);
  cout << "Please enter character's hit point maximum: ";
  maxHP = validInputNum("HIT_POINT_MAXIUM: ", file, 0, 30);
  
  cout << "Pleaser enter character strength: ";
  str = validInputNum("STRENGTH: ", file, 0, 30);
  cout << "Pleaser enter character dexterity: ";
  dex = validInputNum("DEXTERITY: ", file, 0, 30);
  cout << "Pleaser enter character constitution: ";
  con = validInputNum("CONSTITUTION: ", file, 0, 30);
  cout << "Pleaser enter character intelligence: ";
  intelligence = validInputNum("INTELLIGENCE: ", file, 0, 30);
  cout << "Pleaser enter character wisdom: ";
  wis = validInputNum("WISDOM: ", file, 0, 30);
  cout << "Pleaser enter character charisma: ";
  cha = validInputNum("CHARISMA: ", file, 0, 30);

  currentHP = maxHP;
  deathSave = 0;
}

/*
Recursive input validation for int's 
makes sure it's an int and within a range [upper, lower] 
Clears cin and writes to the file 
Called by default constructor 
SCRAPPED VALIDATION FOR  TIME
 */
int validInputNum (string request, fstream &file, int lower, int upper)
{
  int temp;
  cin >> temp;
  cin.clear();
  cin.ignore(9999,'\n');
  file << request << temp << endl;
  return temp;
}

/*
No input validation is needed for strings currently
Clears cin, so anything after a whitespace is ignored
Writes to the file
Called by default constructor 
*/
string validInputString(string request, fstream& file)
{
  string temp;
  cin >> temp;
  cin.clear();
  cin.ignore(9999,'\n');
  file << request << temp << endl;
  return temp;
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
