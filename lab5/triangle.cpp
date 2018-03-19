/* File: triangle.cpp
   Created by: Joseph Shaffer
   Created on: September 28, 2016

   Synopsis: This program takes in
   an input from the user for the 
   number of rows and numbers from 1
   to the inputted number for the top 
   row and for each row afterwards,
   it removes the highest number 
   creating a triangle with the numbers;
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	// n is the input for the number of rows
	// i will increment the outer while loop
	// j will increment the innter while loop
	int n, i(1), j(1);

	// ask user for number of rows and take input as n
	cout << "Enter number of rows: ";
	cin >> n;
	cout << endl;

	// Loop while i is less than or equal to n for the rows
	while (i <= n) {
		// Loop while j is less than n-i + 1
		// because this will give us one less number per row
		while (j <= (n - i) + 1) {
			// mod 10 of j to print out numbers not greater than 9
			cout << j % 10; 
			// increment each number in the same row by 1
			j++;
		}
		cout << endl; // create new line per row
		i++;	// increment i for each row
		j = 1; // reset j back to one for each row
	} 

	// End program
	return 0;
}
