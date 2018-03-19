// File: factors.cpp
// Created by: Joseph Shaffer
// Created on: September 27, 2016
/* Synopsis: This program prompts the user
   for a low integer and high integer and 
   prints out all the factors of all the 
   integers within the range between the
   low and high integer.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	/* low is the low integer of the range
	   high is the high integer of the range.
	*/
	int low, high;
	
	// Prompt the user for the low integer
	cout << "Enter low integer: ";
	cin >> low;

	/* if the low value given is less than 1
	   continuously prompt the user for a new low integer
 	   until one is given that is greater than 1.
	*/
	while (low <= 1) {
		cout << "Number must be greater than 1.\n" << "Enter low integer again: ";
		cin >> low;
	}

	// Prompt the user for the high integer
	cout << "Enter high integer: ";
	cin >> high;
	
	/* if high integer is greater than the low integer
	   continuously prompt the user for a new high integer
	   until one is given that is equal to or greater than
	   the low integer.
	*/
	while (high < low) {
		cout << "Number must be greater than or equal to " << low << ".\n" << "Enter high integer again: ";
		cin >> high;
	}

	cout << endl; //Separate prompts to user from printed out part

	cout << "Factors of all numbers in the range: [ " << low << ", " << high << " ]" << endl; // State range of integers factors are from

	/* Increment by 1 to capture all integers from low integer
	   to high integer and any integers in between
	*/
	for (low; low <= high; low++) {
		/* We have to factor every number from low 
		   integer to high, so we start with low 
		   and increment it by 1 until it reaches high
		   and we know every number is a factor of itself
		*/
		cout << low << ": " << low; 
		// find if numbers less than low are factors of low
		for (int i = (low - 1); i >= 1; i--) {
			/* if low mod i is 0 then i is a factor of low
			   and low is incremented to every number from
			   where it starts to high. We print i if it
			   is a factor of what low is
			*/
			if (low % i == 0) {
				cout << ", " << i;
			}
		}
		cout << endl; // Start new line for each integer
	}
	
	// End program
	return 0;
}

	





