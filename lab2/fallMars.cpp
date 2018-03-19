// File: fallMars.cpp
// Created by: Joseph Shaffer
// Created on: September 8, 2015

/* This program takes an input of time 
   from the user in seconds and calculates
   the velocity on mars and the falling 
   distance on mars with that time 
*/

#include <iostream>
using namespace std;

int main()
{
	double time, velocity, distance, gravity(3.73);
	
	// User gives a time in seconds
	cout << "Enter the time: ";
	cin >> time;

	/* velocity is calculated first then distance
	   since velocity is used to calculate distance
	*/
	velocity = gravity * time;
	distance = 0.5 * velocity * time;

	// Console out the velocity
	cout << "After " << time << " seconds, the velocity on mars is " << 		velocity << " meters per second." << endl;

	// Console out the falling distance
	cout << "After " << time << " seconds, the falling distance on mars is " << distance << " meters." << endl;

	return(0);
}




