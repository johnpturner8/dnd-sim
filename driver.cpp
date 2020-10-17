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
using namespace std;

int main(){
  int answer;
  do{
    cout << "Welcome to DnD Combat Sim" <<endl<<endl
	 << "[1] Make Encounter\n\t"
	 << "[2] Modify Party\n\t"
         << "[3] Load Encounter\n\t"
         << "[4] Generate Encounter\n\t"
         << "[5] Quit Program";
   cout << "\n\nPlease Select What you Want To Do ";
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
         break; 
      case 4:
         break; 
      case 5:
         break;
      }

   } while (answer!=5);
return 0;

}
