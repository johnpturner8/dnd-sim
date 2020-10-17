/*
 * Enemy.cpp
Emily
 */

#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>

//Purely here for testing, will delete later
int main()
{
  Enemy pl;
  return 0;
}

//*************** constructors and destructor ****************

int validInputNum (string request, fstream &file, int lower, int upper);
string validInputString(string request, fstream& file);

/*
Default constructor
Makes a file
Sets member values based on user input and writes them to file
to Call: Enemy EnemyObjectName;
Calls int validInputNum (string request, fstream &file, int lower, int upper) and
string validInputString(string request)
 */
Enemy::Enemy(void)
{
  fstream file;

  cout << "Please enter filename to save to: ";
  cin >> filename;
  //opens the file with given name
  //ios::out oepn for output operators
  //ios::out makes a file if ther is not one already
  file.open(filename.c_str(), ios::out);

  cout << "Please enter Enemy/character name: ";
  name = validInputString("NAME: ", file);
  cout << "Please enter character race: ";
  race = validInputString("RACE: ", file);
  cout << "Please enter character's class: ";
  EnemyClass = validInputString("CLASS: ", file);
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
Enemy::Enemy(string fileName)
{
}

/*
Destructor
 */
Enemy::~Enemy() {

}

//************** setter function **************

void Enemy :: setStr (int x)
{ str = x; }
void Enemy :: setDex (int x)
{ dex = x; }
void Enemy :: setCon (int x)
{ con = x; }
void Enemy :: setInt (int x)
{ intelligence = x; }
void Enemy :: setWis (int x)
{ wis = x; }
void Enemy :: setCha (int x)
{ cha = x; }

void Enemy :: setMaxHP (int x)
{ maxHP = x; }
void Enemy :: setCurrentHP(int x)
{ currentHP = x; }

void Enemy :: setInitiative (int roll)
{ initative = roll; }


//*************** getter functions ***************

string Enemy :: getFileName()
{ return filename; }

int Enemy :: getStr()
{ return str; }
int Enemy :: getDex()
{ return dex; }
int Enemy :: getCon()
{ return con; }
int Enemy :: getInt()
{ return intelligence; }
int Enemy :: getWis()
{ return wis; }
int Enemy :: getCha()
{ return cha; }

int Enemy :: getMaxHP()
{ return maxHP; }
int Enemy :: getCurrentHP()
{ return currentHP; }

int Enemy :: getInitiative()
{ return initative; }

string Enemy :: getName()
{ return name; }
string Enemy :: getRace()
{ return race; }
string Enemy :: getClass()
{ return EnemyClass; }
