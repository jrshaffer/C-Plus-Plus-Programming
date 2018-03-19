/*
  File: harmonic.cpp
  Created by: Joseph Shaffer
  Creation Date: September 30, 2016
  Synopsis:
	This program takes in an input
	number from the user and calculates
	the harmonic number of that input 
	which is the sum of 1 divided by that
	input where the input is decremented 
	to 1.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double sum(0); // changed to double for decimal point
  int n(0);	// kept same

  cout << "Enter n: "; // ask user for n
  cin >> n;		// given n
  
  //int i(1);		// not needed
  while (n >= 1) 	// as long as n is greater than 1 keep looping
  {
	sum += 1.0/n; // add 1/n to sum each loop
	n--;		// decrement n by 1 each loop
  }

  cout << "harmonic number = " << sum << endl; // print out harmonic number which is sum

  return 0; // End program
}
