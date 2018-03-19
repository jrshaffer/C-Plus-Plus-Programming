// File: triLength.cpp
// Created by: Joseph Shaffer
// Created on: September 16, 2016

/* This program prompts the user for
   the lengths of 2 sides of a triangle
   and the angle between those 2 sides.
   Then the program calculates the length 
   of the third side and returns that 
   value to the user 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main () {
	
	/* a is length of side A
	   b is length of side B
	   radians is the angle converted from degrees
	   degrees is the user input for the angle in degrees
	   c is the length of side C calculated from 
	   sides A and B and the degree of the angle 
	   between the 2 sides 
	*/

	double a, b, radians, degrees, c;
	
	// Prompt user for side Length A and get input
	cout << "Enter length of side A: ";
	cin >> a;

	// Prompt user for side Length B and get input
	cout << "Enter length of side B: ";
	cin >> b;

	// Prompt user for the angle between the sides in degrees and get result
	cout << "Enter angle between sides A and B (degrees): ";
	cin >> degrees;

	// Convert the angle from degrees to radians
	radians = degrees * M_PI / 180;
	
	// Calculate the length of side C from lengths A, B and the given angle
	c = sqrt(pow(a, 2.0) + pow(b, 2.0) - 2.0 * a * b * cos(radians));

	// Print out the length of the calculated side C
	cout << "Length of side C is " << c << "." << endl;

	// End program
	return 0;
}
