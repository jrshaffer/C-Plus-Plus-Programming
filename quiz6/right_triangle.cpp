/* File: right_triangle.cpp
   Created by: Joseph Shaffer
   Created on: October 7, 2016
   Synopsis: This program asks the user
   for the number of rows of a triangle
   and produces a right triangle with
   the character '%' and for each row
   of the triangle, there is one less
   character.
*/

#include <iostream>
using namespace std;

int main() {

	/* Declare variables n, i and j
	   n is the number of rows, 
	   i is incremented for the rows
	   j is incremented for the columns
	   of the triangle */
	int n, i, j;

	cout << "Enter number of rows: "; // ask user for number of rows
	cin >> n;	// Initialize n to inputted number of rows
	cout << endl; // Create new line

	// Loop from i equals 1 to n by 1
	for (i = 1; i <= n; i++) {
		// loop from j equals 1 to n-i+1 for each row
		for (j = 1; j <= n - i + 1; j++) {
			// output char for each j iteration for each row
			cout << '%'; 
		}
		cout << endl; // new line after each row
	}

	return 0; //End program
}
