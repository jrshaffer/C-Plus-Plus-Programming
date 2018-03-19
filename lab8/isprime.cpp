/*
  File: isprime.cpp
  Created by: Joseph Shaffer
  Creation Date: October 26, 2016
  Synopsis: The program will read a minimum
  and maximum integer from the user and will then
  return all the prime numbers between the minimum
  and maximum integers.
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR read_range
/* read_range takes to integer parameters
   by reference and does not return a value 
*/
void read_range(int &min, int &max);

// FUNCTION PROTOTYPE FOR is_prime
/* is_prime takes one integer paramet by value
   and has a return type of type boolean, so 
   it returns true or false;
*/
bool is_prime(int x);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
  int imin(0), imax(0);

  // Read in range
  read_range(imin, imax);

  // Print prime numbers
  cout << "Primes:";
  for (int j = imin; j <= imax; j++) {
    if (is_prime(j)) 
      { 
        cout << "  " << j; 
      }
  }
  cout << endl;

  return 0;
}

// DEFINE FUNCTION read_range() HERE:
/* will prompt user for the minimum and maximum value for the range
   and will print an error message first if either the minimum or maximum
   value is less than 2. It will also print an error message if the 
   minimum value is less than the maximum value. The function
   will continuously prompt the user for new minimum and maximum values
   if an error continues to occur. 
   The function read_range takes in two integers by reference and has
   no return value.
*/
void read_range(int &min, int &max) {
	// Prompt and initialize min and max values
	cout << "Enter minimum and maximum: ";
	cin >> min >> max;

	/* while min or max are less than 2  or min is greater than max
	   print corresponding error message and re-prompt user for
	   new min and max values.
	*/
	while ((min < 2 || max < 2) || (min > max)) {
		// Error if min or max less than 2
		if (min < 2 || max < 2) {
			cout << "Error. Minimum and maximum must be at least 2." << endl;
		} else {
			// Error if min greater than max
			cout << "Error. Minimum must be less than maximum." << endl;
		}
		// Continuous prompt for each error
		cout << "Enter minimum and maximum: ";		
		cin >> min >> max;
	} 
}
	
	
// DEFINE FUNCTION is_prime() HERE:

/* Function will check if the integer that is passed
   as a parameter by value is prime by checking if 
   the number can be divided by every number between 2
   and the parameter value - 1, with no remainder. 
   Which is equivalent to x mod i, where i ranges from 
   2 to x-1. If a case exists where x mod i equals 0,
   then x can be divided by i without a remainder and 
   we return false for the x being prime. If not case
   exists, we return true for x being prime.
   This function has a boolean return value of either true or false;
*/
bool is_prime(int x) {
	// loop over all numbers between i = 2 and i = x-1
	for (int i = 2; i < x; i++) {
		// return false, because x is not prime if condition is true
		if (x % i == 0) {
			return false;
		}
	}
	// return true because x%i == 0 was never true, meaning x is prime
	return true;
}


