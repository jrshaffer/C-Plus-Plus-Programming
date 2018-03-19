// File: sin.cpp
// Created by: Naeem Shareef
// Modified by: Joseph Shaffer
// Modified on: September 5, 2016

/* A program to read in an angle x in radians and
   compute sin(x) and sin(x) + sin(x)*sin(x) 
   and the square root of (1+sin(x))
   and output the solutions on separate lines.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double x, y;

  /* Read in angle in radians */
  cout << "Enter angle (radians): ";
  cin >>  x;                        // Angle x given by user

  /* Compute sin(x) */
  y = sin(x);           

  cout << "sin(x) = " << y << endl;

  // Calculate sin(x) + sin(x) * sin(x)
  cout << "sin(x) + sin(x)*sin(x) = "  << y + ( y * y) << endl; 

  // Calculates square root of (1 + sin(x)), sin(x) = y
  cout << "The square root of (1+sin(x)) = " <<  sqrt(1.0 + y) << endl;

  // Exit Program
  return 0;
}
