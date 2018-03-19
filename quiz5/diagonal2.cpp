/*
  File: diagonal2.cpp
  Created by: Joseph Shaffer
  Creation Date: September 30, 2016
  Synopsis:
	Program asks the user for
	an amount for the rows in the 
	diagonal and produces a diagonal row
	of x's where every x that is pushed to
	the right by one more of the '#' symbol for every
	row down the diagonal goes.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

  int numRows(0); // integer for number of rows
  
  cout << "Enter number of table rows: "; // Ask user for number of rows
  cin >> numRows;		// get number of rows and assign to numRows
  
  cout << endl;			// create empty line
  
  int row = 1;			// change row to 1 want to increment to numRows
  while (row <= numRows)	// While row is less than numRows keep looping	
  {
	int col = 1;		// column declared and initialized to 1
    while (col < row)		// Alwasy want column to be less than row
    {
      cout << "#";	// Print this symbol 1 less than row times per row
	  col++;	// Increment column for inner loop
    }
    cout << "x" << endl; // Print x at end of every row & create new line for a new row
	row++;		// increment row by 1 every loop of the outer loop
  }

	return 0; // End program
}
