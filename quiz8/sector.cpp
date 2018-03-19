/*
  File: sector.cpp
  Created by: Joseph Shaffer
  Creation Date: October 28, 2016
  Synopsis:
  This program utilizes two functions.
  one function returns the value of 
  the area of the sector determined
  by the radius and angle in radians,
  while the other function returns the
  value of the area of the segment
  determined by the given radius and 
  angle in radians.
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR sector_area
// Computes the area of the entire sector
/* Function has two parameters of type double and 
   returns the area which is of type double
   radius and angle are passed by value from
   the input of the user and their values are not changed, but
   used to calculate the area
*/
double sector_area(double r, double angle);


// FUNCTION PROTOTYPE FOR segment_area
/* Fuction has two parameters of type double, the
   radius and the angle which are both of type double
   and computes the area of the segment and returns
   the computed value as type double
   radius and angle are passed by value from the input
   of the user and their values are not changed, but
   used to calculate the area
*/

double segment_area(double r, double angle);

// Not commenting on main since I did not edit/program it

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
  // Declare and initialize variables
  double circle_radius(0.0), angle_radians(0.0), area_sec(0.0), area_seg(0.0);

  // Read circle radius
  cout << "Enter radius: ";
  cin >> circle_radius;

  // Read circle angle
  cout << "Enter sector angle (radians): ";
  cin >> angle_radians;

  // Compute sector area
  area_sec = sector_area(circle_radius, angle_radians);

  // Compute segment area
  area_seg = segment_area(circle_radius, angle_radians);

  // Output areas
  cout << endl;
  cout << "The circle has radius " << circle_radius << " and the sector has angle " << angle_radians << endl;
  cout << "The area of the sector is " << area_sec << endl;
  cout << "The area of the segment is " << area_seg << endl;
  
  return 0;
}

// DEFINE FUNCTION sector_area here:
// Computes the area of the entire sector
/* Function has two parameters of type double and 
   returns the area which is of type double
   parameters are of type double and passed by
   value, their values are not changed but used
   to calculate the area which is the return value
*/
double sector_area(double r, double angle) {
	return (0.5 * angle * pow(r, 2.0));
}


// DEFINE FUNCTION segment_area here:

/* Fuction has two parameters of type double, the
   radius and the angle which are both of type double
   and computes the area of the segment and returns
   the computed value as type double
   parameters are of type double and passed by
   value, their values are not changed but used
   to calculate the area which is the return value
*/
double segment_area(double r, double angle) {
	return (0.5 * (angle - sin(angle)) * pow(r, 2.0));
}

