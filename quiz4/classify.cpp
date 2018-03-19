/*
  File: classify.cpp
  Created by: Joseph Shaffer
  Creation Date: September 23, 2016
  Synopsis: This program prompts the user
  for a x-coordinate and y-coordinate
  then lets the user know where that point
  from the x and y-coordinates lies on the 
  cartesian plane.
*/

#include <iostream>
using namespace std;

int main()
{
  // Variable declarations

  // Point to classify - (x, y)
  int x_loc(0), y_loc(0);

  
  // Prompt and read in point to classify
	cout << "Enter x-coordinate of point to classify: ";
	cin >> x_loc;
	
	cout << "Enter y-coordinate of point to classify: ";
	cin >> y_loc;
	cout << endl;  
  
  // Classify point in the Cartesian plane
	if (y_loc == 0 && x_loc > 0) {
		cout << "On the +X axis." << endl; // on x-axis positive
	} else if (x_loc == 0 && y_loc > 0) {
		cout << "On the +Y axis." << endl; // on y-axis positive
	} else if (y_loc == 0 && x_loc < 0) {
		cout << "On the -X axis." << endl; // on x-axis negative
	} else if (x_loc == 0 && y_loc < 0) {
		cout << "On the -Y axis." << endl; // on y-axis negative
	} else if (x_loc > 0 && y_loc > 0) {
		cout << "In Quadrant I." << endl; // positive x and y
	} else if (x_loc < 0 && y_loc > 0) {
		cout << "In Quadrant II." << endl; // negative x and positive y
	} else if (x_loc < 0 && y_loc < 0) {
		cout << "In Quadrant III." << endl; // negative x and y
	} else if (x_loc > 0 && y_loc < 0) {
		cout << "In Quadrant IV." << endl; // positve x and negative y
	} else {
		cout << "Is the origin." << endl; // both x and y are zero
	}

  return 0;
}
