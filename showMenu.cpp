#include <iostream>
#include "showMenu.h"
#include "constants.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: show the top menu for users to choose a image edit option

int showMenu()  {
  int topMenuOpt = 0;  
  bool isValidInput = false;

  while (!isValidInput)  {
    cout << "1. Annotate image with rectangle" << '\n'
       << "2. Annotate image with pattern from file" << '\n'
       << "3. Insert another image" << '\n'
       << "4. Write out current image" << '\n'
       << "5. Exit the program" << '\n'
       << "Enter int for main menu choice: " << endl;
    
    cin  >> topMenuOpt;
    // error cheching for cin
    if (cin.fail)  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN);
      cout << "Error found when reading the input" 
           << " - expected a integer between 1 and 5"
           << " but found " << topMenuOpt << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  return topMenuOpt;
}