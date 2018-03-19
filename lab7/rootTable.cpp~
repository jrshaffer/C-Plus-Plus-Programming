/* File: rootTable.cpp
   Created by: Joseph Shaffer
   Created on: October 19, 2016
   Synopsis:This program prints out
   the values of a numbers roots in 
   a table, where the values are on
   the left hand side of the table
   are on a set increment up to 100
   and the number of roots of the value
   on the left hand side are given by the user.
   The root of the value is set to certain number
   of digits passed the decimal point by
   the user.
*/

#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	
	/* roots is the number of roots, meaning last column of x^1/(roots)
	   where roots is an integer given by the user and each column
	   increments by 1 from 2 to the roots value;
	   increment is for the left column, where the value is incremented
	   from the inputted value from the user and incremented by increment's
	   value until it is greater or equal to 100.
	   precision is the number of digits passed the decimal point that
	   the calculated root is set to by the user.
	   width is the column width defined to organize the table output
	   minColumnWidth is basically set to 5 for the column headers which
	   is basically equivalent to a precision of 4
	*/
	int roots, increment, precision, width, minColumnWidth(5);
	
	// Prompt user for roots, and initialize roots variable
	cout << "Enter number of roots: ";
	cin >> roots;

	// Prompt user for increment and initialize increment variable	
	cout << "Enter value increment (integer): ";
	cin >> increment;

	// Prompt user for precision and initialize precision variable
	cout << "Enter precision: ";
	cin >> precision;

	// Set width to precision + minColumnWidth 
	// and 1 with 0 precision
	// subtract 1 with greater than 1 precision
	if (precision < 1) {
		width = precision + minColumnWidth + 1;
	} else if (precision > 1) {
		width = precision + minColumnWidth - 1;
	} else {
		width = precision + minColumnWidth;
	}
	
	cout << "Value"; // First column header without width
	for (int i = 2; i <= roots + 1; i++) {
		if (i >= 10) {
			cout << setw(width - 1) << "x^1/" << i; // decrease width for x^1/i, where i > 9
								// Keeps column headers aligned with columns 
		} else {
			cout << setw(width) << "x^1/" << i;  // if i < 10, keep normal width
		}
	}
	cout << endl; // new row
	
	cout.setf(ios::fixed); // set output to fixed
	cout.precision(precision);	// set fixed output to given precision
	for (int i = increment; i <= 100; i += increment) { // increment by increment for each row value
		cout << setw(minColumnWidth) << i << " ";	// set columnWidth to mincolumnWidth for left column
		for (int j = 2; j <= roots + 1; j++) {
			cout << setw(width) << pow(i, (1.0 / j)) << " "; // print out value to set precision with set width for column
		}
		cout << endl; // new row
	}
	
	return 0; // end program
}
