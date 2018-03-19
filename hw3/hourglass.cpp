/*
  File: hourglass.cpp
  Created by: Joseph Shaffer
  Creation Date: September 27, 2016
  Synopsis: This program creates an hour glass
  shape with the symbol '*' by asking the user
  for how many of the symbol to include in the 
  top row and how many rows to create in the 
  hourglass. The program takes the user input
  and makes an hour glass by basically making
  an upside down pyramid on top of a right side
  up pyramid.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Declare and initialize variables
	/* rowSize is the amount of '*' included in each row
	   numRows is the number of rows from the top to the
	   middle of the hour glass and the middle to the bottom
	   of the hourglass.
	   i is an integer incremented in a for loop
	   j is an integer incremented in a for loop
	   k is an integer incremented in a for loop
	*/
	int rowSize, numRows, i, j, k;
	

  // Repeatedly prompt for top row size until valid value is entered
 	/* Prompt the user for the size of the top row and initialize 
	   rowSize to that value */	
	cout << "Enter size of the top row: ";
	cin >> rowSize;
	
	/* if the size of the row is less than 3, the program continually
	   prompts the user to give a value for the size of the row that
	   is at least 3. 
	*/
	while (rowSize < 3) {
		cout << "Size of the top row must be at least three." << endl;
		cout << "Enter size of the top row again: ";
		cin >> rowSize;
	}
	

// Repeatedly prompt for the number of rows until valid value is entered
	/* Ask the user for the number of rows in the pyramid and
	   initialize the value of numRows to the input
	*/
	cout << "Enter number of rows: ";
	cin >> numRows;
	
	/* The program will tell the user that the number of rows inputted
	   is invalid if the numRows is less than 1 or if the numRows will 
	   eventually decrement to a point where the size of the row is less
	   than 2. Thus the user will be prompted for a new input until these
	   conditions are satisfied.
	*/
	while (numRows < 1 || (rowSize / numRows) < 2) {
		cout << "Invalid number of rows.\n";
		cout << "Enter number of rows again: ";
		cin >> numRows;
	}

	cout << endl; // Separate the input from user from actual hourglass
  
  // Print the hour glass
	
	/* Increment i from 1 to numRows to create top half of hourglass */
	for (i = 1; i <= numRows; i++) {
		/* Increment j to less than i to print out 1 less blank space
		   than the row number for top half of pyramid 
		*/
		for (j = 1; j < i; j++) {
			cout << " ";
		}
		/* Increment k to rowSize so that the '*' symbol prints out
		   a rowSize number of times per row
		*/
		for (k = 1; k <= rowSize; k++) {
			cout << '*';
		}	
		cout << endl; // Start new line for each row
		rowSize -= 2; /* decrement row size for each row 
				 so 2 less '*' are printed */
	}
	
	rowSize += 4; /* increase rowSize by 4 as rowSize would be
			 at 1 or 0 with the last decrement by 2 */
	/* Build bottom of hour glass, so there is one less row
	   since the middle row only is printed once, thus
	   i increments to numRows - 1;
	*/
	for (i = 1; i <= numRows - 1; i++) {
		/* We have to reverse the number of blank 
		   spaces printed out thus we start with numRows-1
		   and we skip the middle of the pyramid, we 
		   decrement j from numRows-1 to i
		*/
		for (j = numRows - 1; j > i; j--) {
			cout << " ";
		}
		/* we do the same thing with the symbols as in 
		   the top part of the hour glass, since rowSize
		   is already at the low end and we increment it 
		   up for every row, making it so more symbols
		   are printed out for every row
		*/
		for (k = 1; k <= rowSize; k++) {
			cout << '*';
		}
		cout << endl; // Start new line for every row
		rowSize += 2; // Increment rowSize by 2 for every row
	}
  

  // end program
  return 0;
}
