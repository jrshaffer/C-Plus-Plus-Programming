/*
  File: polarcoord.cpp
  Created by: ???
  Creation Date: ???
  Synopsis: ??
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR degrees2radians


// FUNCTION PROTOTYPE FOR compute_coord


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


// DEFINE FUNCTION compute_coord here:


