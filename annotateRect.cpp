#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"
#include "selectColor.h"
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "selectFill.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: implement the function of annotating an image with a rectangle

void annotateRect(ColorImageClass &image)  {
  int rectOption = 0;
  int inRow = 0, inCol = 0, numRow = 0, numCol = 0;
  const int OPT_MAX = 3, OPT_MIN = 1;
  const int OPT_ONE = 1, OPT_TWO = 2, OPT_THREE = 3;
  bool isValidInput = false, isFilled = false;
  ColorClass rectColor;
  RowColumnClass upperLeftLocation, lowerRightLocation, tempLocation;

  cout << "1. Specify upper left and lower right corners of rectangle"
       << '\n'
       << "2. Specify upper left corner and dimensions of rectangle"
       << '\n'
       << "3. Specify extent from center of rectangle" << '\n';
         
  while (!isValidInput)  {
    cout << "Enter int for retangle specification method" << endl;
    cin >> rectOption;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid specification method input" 
           << " - expected an integer of 1 or 2 or 3 " << '\n' 
           << "try again"
           << endl;
    }
    else if (rectOption > OPT_MAX || rectOption < OPT_MIN)  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid specification method input" 
           << " - expected an integer of 1 or 2 or 3 " << '\n' 
           << "try again"
           << endl;
    }
    else  {
      isValidInput = true;
    }
  }
  // method 1 - upper left and lower right
  if (rectOption == OPT_ONE)  {
    isValidInput = false;
    // error checking for row and column input
    while (!isValidInput)  {
      // get rectangle region
      cout << "Enter upper left corner row and column: " << endl;
      cin >> inRow >> inCol;

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row or column input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }
      else if (inRow < 0 || inCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification method input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        isValidInput = true;
        upperLeftLocation.setRowCol(inRow, inCol);
      }
    }

    isValidInput = false;
    while (!isValidInput)  {
      cout << "Enter lower right corner row and column: " << endl;
      cin >> inRow >> inCol;
 
      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row or column input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }
      else if (inRow < 0 || inCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification method input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        lowerRightLocation.setRowCol(inRow, inCol);
        isValidInput = true;
      }
    }
  }  
  
  // method 2 - upper left and dimension
  else if (rectOption == OPT_TWO)  {
    isValidInput = false;
    // error checking for row and column input for upperLeftLocation
    while (!isValidInput)  {
      // get rectangle region
      cout << "Enter upper left corner row and column: " << endl;
      cin >> inRow >> inCol;

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row or column input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }
      else if (inRow < 0 || inCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification method input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        isValidInput = true;
        upperLeftLocation.setRowCol(inRow, inCol);
      }
    }

    isValidInput = false;
    while (!isValidInput)  {
      cout << "Enter int for number of rows: " << endl;
      cin >> numRow;

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row number input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }

      else if (numRow < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row number input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        isValidInput = true;
      }
    }

    isValidInput = false;
    while (!isValidInput)  {
      cout << "Enter int for number of columns " << endl;
      cin >> numCol;
      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification column number input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }

      else if (numCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification column number input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        isValidInput = true;
      }
      lowerRightLocation.setRowCol(inRow + numRow, inCol + numCol);
    }
  }
  // method 3 - center and dimension
  else if (rectOption == OPT_THREE)  {
    
    isValidInput = false;
    while (!isValidInput)  {
      cout << "Enter rectangle center row and column: " << endl;
      cin >> inRow >> inCol;

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row or column input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }
      else if (inRow < 0 || inCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification method input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        isValidInput = true;
      }
    }

    isValidInput = false;
    while (!isValidInput)  {
      cout << "Enter int for half number of rows: " << endl;
      cin >> numRow;

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row number input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }

      else if (numCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification row number input" 
            << " - expected non-negative integers " << '\n'  
            << "try again"
            << endl;
      }
      else  {
        isValidInput = true;
      }
    }

    isValidInput = false;
    while (!isValidInput)  {
      cout << "Enter int for half number of columns " << endl;
      cin >> numCol;

      if (cin.fail())  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification column number input" 
            << " - expected positive integers " << '\n' 
            << "try again"
            << endl;
      }

      else if (numCol < 0)  {
        cin.clear();
        cin.ignore(IGNORED_CHAR_LEN, '\n');
        cout << "Invalid specification column number input" 
             << " - expected non-negative integers " << '\n'  
             << "try again"
             << endl;
      }
      else  {
        isValidInput = true;
      }
    }
    upperLeftLocation.setRowCol(inRow - numRow, inCol - numCol);
    lowerRightLocation.setRowCol(inRow + numRow, inCol + numCol);
  } 

  // get rectangle color
  rectColor = selectColor("rectangle");
  // get fill option
  isFilled = selectFill();
  // annotate the input object 
  // filled means a solid rectangle
  if (isFilled)  {
    for (int rInd = upperLeftLocation.getRow(); 
          rInd < lowerRightLocation.getRow();
          rInd++)  {
      for (int cInd = upperLeftLocation.getCol();
          cInd < lowerRightLocation.getCol();
          cInd++)  {
        tempLocation.setRowCol(rInd, cInd);
        image.setColorAtLocation(tempLocation, rectColor);
      }
    }
  }
  // not filled means an empty rectangle
  else if (!isFilled)  {
    // loop throught the top and the bottom row
    for (int rInd = upperLeftLocation.getRow();
          rInd < lowerRightLocation.getRow();
          rInd++)  {
      // top row of the empty rectangle
      int cInd;
      cInd = upperLeftLocation.getCol();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
      // bottom row of the empty rectangle
      cInd = lowerRightLocation.getCol();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
    }
    // loop throught the left and the right column
    for (int cInd = upperLeftLocation.getCol();
          cInd < lowerRightLocation.getCol();
          cInd++)  {
      // left column of the empty rectangle
      int rInd;
      rInd = upperLeftLocation.getRow();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
      // right column of the empty rectangle
      rInd = lowerRightLocation.getRow();
      tempLocation.setRowCol(rInd, cInd);
      image.setColorAtLocation(tempLocation, rectColor);
    }
  }
}