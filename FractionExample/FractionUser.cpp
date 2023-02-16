#include <iostream>
using namespace std;
#include <string>

#include "Fraction.h"

int main ( ) {
   string userInput;
   Fraction f1, f2, f3;
   while (1) {
      cout << "What would you like to do with two Fractions?!" << endl;
      cout << "Choose from [\"Enter\" \"Show\" \"Add\" \"Subtract\" \"Compare\" \"Quit\"]" << endl; 
      cout << "--> "; 

      cin >> userInput; 

      if (userInput == "Quit") break;

      if (userInput == "Enter") {
         cout << "Enter Fraction 1: " << endl;
         f1.promptedRead();
         cout << "Enter Fraction 2: " << endl;
         f2.promptedRead();
      }
      else if (userInput == "Show") {
         cout << "Fraction 1: " << f1 << endl;
         cout << "Fraction 2: " << f2 << endl;
      }
      else if (userInput == "Add")
         cout << "       Sum: " << (f1 + f2) << endl;
      else if (userInput == "Subtract") {
         f3 = f1 - f2;
         cout << "      Diff: " << (f1 - f2) << endl;
      }
      else if (userInput == "Compare") {
         cout << f1 << " and " << f2 << " are "; 
         if (f1 == f2) {} else cout << "not "; 
         cout << "equal." << endl;  
      } else 
         cout << "Command not recognized." << endl; 
   }
   return 0;
}
