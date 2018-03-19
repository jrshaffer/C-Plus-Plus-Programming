// File: fallMeters.cpp
// Created by: Joseph Shaffer
// Created on: September 9, 2016

/* Computes the falling velocity and distance in meters */

#include <iostream>
using namespace std;

int main() 
{ 
  double g = 32.185;         //feet per second^2
  double t;                  // time in seconds
  double ratio = 0.3048;     // ratio of meters over feet
  double velocity;           // velocity after time t in meters per second
  double distance;           // distance after time t in  meters

  cout << "Enter the time: ";
  cin >> t;

  // Compute the velocity and the distance
  velocity = g * t * ratio;
  distance = (1.0 / 2.0) * velocity * t;

  cout << "After " << t << " seconds, the velocity is " << velocity << " meters per second." << endl;
  cout << "After " << t << " seconds, the falling distance is " << distance << " meters." << endl;

  return(0);

}
  
