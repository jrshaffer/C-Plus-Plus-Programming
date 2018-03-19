 // File: basics.cpp
// Created by: Joseph Shaffer
// Created on: September 4, 2016

/* This program illustrates the use of keyboard input, data 
   types, variables, assignment statements, and output
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() 
{ 
  double x;
  int y, z;
  char character;

  cout << "Enter a character: ";                // Ask user for character
  cin >> character;                     // Get character
  cout << "Enter value for double value x: ";     // Ask double from user
  cin >> x;                        // Get double
  cout << "Enter value for integer value y: ";  // Ask y integer from user
  cin >> y;                          // Get y integer
  cout << "Enter value for integer value z: ";  // Ask z integer from user
  cin >> z;;                             // Get z integer
  cout << endl;

  cout << "Your character is " << character << endl; // Print out character
  cout << "Your value for x is " << x << endl;       // Print out double
  cout << "Your value for y is " << y << endl;       // Print out y integer
  cout << "Your value for z is " << z << endl;       // Print out z integer
  cout << endl;

  cout << "The reciprocal of x is " << (1.0 / x) << endl; // Result of 1 / x
  cout << "x/z is " << (x / z) << endl;                  // Result of x / z
  cout << "x + y + z is " << ( x + y + z) << endl;         // Result of x + y + z
  cout << endl;

  cout << "The reciprocal of y is " << ( 1.0 / y) << endl; // Result of 1/ y
  cout << "The reciprocal of z is " << (1.0 / z) << endl; // Result of 1 / z
  cout << "y/z is " <<( y / z) << endl;                  // Result of y/z
  cout << "y modulus z is " << (y % z) << endl;           // Result of y mod z

  return(0);
}
