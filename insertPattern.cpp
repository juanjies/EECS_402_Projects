#include "ColorImageClass.h"
#include <fstream>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "selectColor.h"
#include <cstdlib>
#include "TransparencyClass.h"

using namespace std;
// Programmer: Juan-Jie Sun
// Date: November 2020
// Purpose: insert a pattern to the input image

void insertPattern(ColorImageClass &image)  {
  string filename;
  ifstream inFile;
  RowColumnClass upperLeftLocation, tempLocation;
  ColorClass patternColor;
  bool isValidInput = false;
  int inRow = 0, inCol = 0, tempInt = 0;
  int patternLen = 0, patternWid = 0;

  cout << "Enter string for file name containing pattern: " << endl;
  cin >> filename;
  inFile.open(filename.c_str());
  // error check for file opening process
  if (inFile.fail())  {
		cout << "Unable to open the pattern file!" << endl;
    exit(1);
	}
	// pattern file contents error checking
  while (!isValidInput)  {
    if (inFile.eof())  {
			cout << "EOF before reading the image" << endl;
      exit(2);
		}
		else if (inFile.fail())  {
			inFile.clear();
      inFile.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid pattern" << endl;
		}
    else  {
      isValidInput = true;
      inFile >> patternWid;
      inFile >> patternLen;      
    }
  }

  isValidInput = false;
  while (!isValidInput)  {
    cout << "Enter upper left corner of pattern row and column: ";
    cin >> inRow >> inCol;

    if (cin.fail())  {
      cin.clear();
      cin.ignore(IGNORED_CHAR_LEN, '\n');
      cout << "Invalid row or column input" << endl;
    }
    else  {
      isValidInput = true;
    }
  }

  upperLeftLocation.setRowCol(inRow, inCol);
  patternColor = selectColor("pattern");

  // dynamic allocate a 2D array to read in the pattern
  /*
  pattern = new int *[patternLen];
  for (int rInd = 0; rInd < patternLen; rInd++)  {
    pattern[rInd] = new int[patternWid];
  }
  */
  TransparencyClass pattern(patternLen, patternWid);

  // read in pattern
  for (int rInd = 0; rInd < patternLen; rInd++)  {
    for (int cInd = 0; cInd < patternWid; cInd++)  {
      inFile >> tempInt;
      tempLocation.setRowCol(rInd, cInd);
      if (tempInt == 0)  {
        pattern.setTransAtLocation(tempLocation);
      }
      else if (tempInt == 1)  {
        pattern.setNotTransAtLocation(tempLocation);
      }
    }
  }
  // add pattern to the image
  for (int rInd = 0; rInd < patternLen; rInd++)  {
    for (int cInd = 0;  cInd < patternWid; cInd++)  {
      if (pattern.getTransAtLocation(rInd, cInd) == 1)  {
        tempLocation.setRowCol(upperLeftLocation.getRow() + rInd,
          upperLeftLocation.getCol() + cInd);
        image.setColorAtLocation(tempLocation, patternColor);
      }
      else if (pattern.getTransAtLocation() == 0) {
        ;
      }
    }
  }
  /*
  // deletion
  for (int rInd = 0; rInd < patternLen; rInd++)  {
    delete [] pattern[rInd];
  }
  delete [] pattern;
  */
}