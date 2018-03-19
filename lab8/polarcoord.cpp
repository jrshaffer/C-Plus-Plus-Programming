/*
  File: polarcoord.cpp
  Created by: Joseph Shaffer
  Creation Date: October 26, 2016
  Synopsis: The program prompts the user for
  a radius and an angle in degrees and the 
  program will convert the angle to radians 
  and compute the cartesian coordinates from
  the polar coordinates inputted.
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR degrees2radians
/* degrees2radians takes in one paramater by 
   value and of type double. The function also
   returns a value of type double.
*/
double degrees2radians(double angle);

// FUNCTION PROTOTYPE FOR compute_coord
/* compute_coord takes in 4 paramaters, all of
   type double, but two are passed by value and two
   are passed by reference. The function does not
   return a value.
*/
void compute_coord(double polar_radius, double polar_angle, double &x_coord, double &y_coord);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
  double angle_degrees(0.0), angle_radians(0.0), radius(0.0);
  double coord_x(0.0), coord_y(0.0);

  // Read in polar coordinates
  cout << "Enter radius: ";
  cin >> radius;

  cout << "Enter polar angle (degrees): ";
  cin >> angle_degrees;

  // Convert degrees to radians
  angle_radians = degrees2radians(angle_degrees);

  // Compute Cartesian (x,y) coordinates
  compute_coord(radius, angle_radians, coord_x, coord_y);

  // Output Cartesian coordinates
  cout << "Cartesian coordinates: ";
  cout << "(" << coord_x << "," << coord_y << ")" << endl;

  return 0;
}

// DEFINE FUNCTION degrees2radians here:
/* degrees2radians converts the given parameter, which
   is an angle in degrees and returns the value of the 
   angle in radians.
*/
double degrees2radians(double angle) {
	return (angle * (M_PI / 180));
}

// DEFINE FUNCTION compute_coord here:
/* the function changes the value of the parameters x_coord and
   y_coord it by computing the cartesian values for the x and y coordinates
   by using the polar_radius and polar_angle parameters that are passed by
   value. The function does not return anything by changes the value of the
   parameters passed by reference.
*/
void compute_coord(double polar_radius, double polar_angle, double &x_coord, double &y_coord) {
	x_coord = polar_radius * cos(polar_angle);
	y_coord = polar_radius * sin(polar_angle);
}

