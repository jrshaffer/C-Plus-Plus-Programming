/*	File: pyramid.cpp
	Created by: Joseph Shaffer
	Created on: October 5, 2016
	Synopsis: This program takes
	an input from the user that has to 
	be an odd integer. Then the program
	makes a pyramid from the integer by
	first outputting a row from the 
	number 1 to the inputted integer.
	Then each following row removes
	the beginning and last number from
	the previous row. Thus, the final
	row has 1 number which is the median
	between 1 and the inputted number.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	// n is the inputted number from the user
	int n;

	// Prompt user for positive odd number and initialize to n
	cout << "Enter a positive odd number: ";
	cin >> n;

	/* Prompt user for new number if the input is odd or less than 1 */
	while (n % 2 == 0 || n < 1) {
		// New prompt and input initialized to n
		cout << "Enter a positive odd number. Try again: ";
		cin >> n;
	}

	cout << endl; // Output is blank line

	// Run i from 1 to half of n plus 1, which is the number of rows
	for (int i = 1; i <= (n / 2) + 1; i++) {
		// Print 1 less blank space than the row
		for (int k = 1; k < i; k++) {
			cout << " "; // Output blank space
		}
	
		/* output numbers from i to inputted number - i + 1
		   Thus each row has one less number at the beginning
		   and one less number at the end than the previous row
		*/
		for (int l = i; l <= (n - i + 1); l++) {
			cout << l % 10; // mod 10 to print out the digit in singles place
		}	 
		
		cout << endl; // Create new row 
	}
		
	// End program				
	return 0;

}
