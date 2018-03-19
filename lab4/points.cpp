// File: points.cpp
// Created by: Joseph Shaffer
// Created on: September 21, 2016

/* This program prompts the user to enter
   the coordinates of 2 points and the 
   program then determines where the 2 points are
   in relation to each other and outputs the result
*/

#include <iostream>
#include <sstream>
using namespace std;


int main () {

	/* x1 is the x-coordinate of the first point
	   y1 is the y-coordinate of the first point
	   x2 is the x-coordinate of the second point
	   y2 is the y-coordinate of the second point
	*/
	double x1, y1, x2, y2;
	
	// Prompt the user for the coordinates of the first point
	// record coordinates as x1 and y1
	cout << "Enter coordinates of the first point (2 values): ";
	cin >> x1 >> y1;

	// prompt the user for the coordinates of the second point
	// record the coordinates as x2 and y2
	cout << "Enter coordinates of the second point (2 values): ";
	cin >> x2 >> y2;

	/* stringstreams point1 and point2 are basically just a 
	   combination of different strings and the variables x1,
	   y1, x2, and y2, into 2 different strings, for the purpose
	   of saving time in writing out the exact same parts to cout
	   for every if statement. It is also used because it looks better 
	   instead of having a cout with several different small strings
	   separated by the variables. Removing repitition in a way.
	*/
	stringstream point1; 
	point1 << "Point (" << x1 << "," << y1 << ")";
	stringstream point2;
	point2 << "point (" << x2 << "," << y2 << ").";

	/* Check if x-coordinate of the first point is less 
	   than the x-coordinate of the second point */
	if (x1 < x2) {
		// if x1 < x2, check if y-coordinates of both points are equal
		if (y1 == y2) {
			// conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is left of " << point2.str() << endl;
		} 
		// if x1 < x2, check if y1 < y2
		else if (y1 < y2) {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is below and left of " << point2.str() << endl;
		}
		// if x1 < x2, and other if statements are false, then y1 > y2 
		else {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is above and left of " << point2.str() << endl;
		}
	}
	// Check if x1 equals x2 if x1 is not less than x2
	else if (x1 == x2) {
		// if x1 == x2, check if y1 equals y2
		if (y1 == y2) {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " equals " << point2.str() << endl;
		}
		// if x1 == x2, check if y1 < y2 
		else if (y1 < y2) {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is below " << point2.str() << endl;
		}
		// if x1 == x2, and y1 is not less than or equal to y2 then y1 < y2 
		else {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is above " << point2.str() << endl;
		}
	} 
	// If x1 is not equal to or less than x2, then x1 > x2
	else {
		// since x1 > x2, check if y1 equals y2
		if (y1 == y2) {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is right of " << point2.str() << endl;
		} 
		// since x1 > x2, check if y1 is less than y2
		else if (y1 < y2) {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is below and right of " << point2.str() << endl;
		} 
		// at this point, x1 is greater than x2 and y1 is greater than y2 by default basically
		else {
			//  conditions hold, print out where point 1 is in reference to point 2
			cout << point1.str() << " is above and right of " << point2.str() << endl;
		}
	}

	// Exit program
	return 0;
}		
