/*	File: alt_harmonic.cpp
	Created by: Joseph Shaffer
	Created on: October 5, 2016
	Synopsis: The program prompts the user for
	a whole number that has to be greater than 
	1. If not given a number greater than 1,
	the program continously prompts the user
	for a new whole number. The program
	computes the alternating harmonic number of
	the given input, and the higher the input 
	the closer the harmonic number will be
	to ln(2), the natural logorithm of 2.
	So the program converges to ln(2) for the 
	bigger input numbers from the user.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	/* n is the number inputted by the user
	   sum is the sum of each calculation
	*/
	int n; 
	double sum(0.0);

	/* Prompt the user for n
	   initialize n to the inputted number
	*/
	cout << "Enter n: ";
	cin >> n;

	/* Keep prompting the user for a new input
	   if the previous input is less than 1 */
	while (n < 1) {
		// New prompt and input initialized to n
		cout << "Value n must be 1 or greater. Try again: ";
		cin >> n;   
	}

	/* For loop from 1 to n with k being incremented from 1 to n */
	for (int k = 1; k <= n; k++) {
		// Sum is equal to sum + (-1) ^ (k+1) divided by k
		sum += (pow(-1.0, (k + 1)) / k);
	}
	
	// Output the sum, which is what the alternating series converges to
	cout << "The alternating series converges to " << sum << endl;

	return 0; // End program
}
