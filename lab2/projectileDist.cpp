// File: projectileDist.cpp
// Created by: Joseph Shaffer
// Created on: September 8, 2016

/* This file will compute the horizontal
   distance travelled by a projectile shot
   at a 45 degree angle with an initial velocity
   v on earth given by the user
*/

#include <iostream>
using namespace std;

int main()
{

	/* Declare variables distance, velocity, velocity_squared
	   and gravity; also initialize gravity to given value
	*/
	double distance, velocity, velocity_squared, gravity(9.81);
	
	// Ask the user for the initial velocity
	cout << "Enter the initial velocity (meter/second): ";
	cin >> velocity;

	// Calculate the velocity squared
	velocity_squared = velocity * velocity;
	
	// Calculate the distance with velocity squared and gravity
	distance = velocity_squared / gravity;

	// Print out the horizontal distance
	cout << "Horizontal distance travelled is " << distance << " meters." << endl;

	return(0);
}
	
