/*
 * driver.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: johnp
 */
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Encounter.h"
#include "Turn.h"
using namespace std;

int main(){
  Encounter e;
  Player p;
  Enemy e1, e2;

  e.addPlayer(p);
  e.addEnemy(e1);
  e.addEnemy(e2);

  Turn t(e);
  t.rollInit();
  t.runRound();
  
  /*  int answer;
  do{
     cout << "Welcome to DnD Combat Sim" <<endl<<endl
	 << "\t[1] Make Encounter\n\t"
	 << "[2] Modify Party\n\t"
	 << "[3] Load Encounter\n\t"
	 << "[4] Quit Program";
     cout << "\n\nPlease Select What you Want To Do: ";
   cin >> answer; 
   //For when the user enters invalid characters
   cin.clear();
   cin.ignore(9999, '\n');

   switch (answer)
      {
      case 1:
         break; 
      case 2:
         break; 
      case 3:
	cout << "Input filename: ";
    	 string filename;
    	 cin >> filename;
    	 Encounter e(filename);
    	 Turn t(e);
    	 t.rollInit();
    	 t.runRound();
         break; 
      case 4:
	exit(0);
	break;
      default:
	break;
      }

   } while (answer!=4);
  */
return 0;

}
