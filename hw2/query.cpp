/*
  File: query.cpp
  Created by: Joseph Shaffer
  Creation Date: September 13, 2016
  Synopsis: This program prompts the user for 
	    the coordinates of the origin of 3 circles
	    and the radius of the 3 circles and determines 
	    if a given point is inside 1,and/or 2, and/or
	    all 3 circles or none of them.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Variable declarations
  /* c1x, c1y, c1r are circle C1's x & y coordinates & radius r
     c2x, c2y, c2r are circle C2's x & y coordinates & radius r
     c3x, c3y, c3r are circle C3's x & y coordinates & radius r
     px, py are the query point's x and y coordinates
     dc1, dc2, and dc3 are the distance the query point is from the center
     of circles C1, C2, and C3;
  */
	double c1x, c1y, c1r, c2x, c2y, c2r, c3x, c3y, c3r, px, py, dc1, dc2, dc3;

  // Prompt and read center and radius for each circle
	cout << "Enter x and y coordinates of circle C1 (2 values): ";
	cin >> c1x >> c1y;
	cout << "Enter radius of circle C1: ";
	cin >> c1r;
	
	cout << "Enter x and y coordinates of circle C2 (2 values): ";
	cin >> c2x >> c2y;
	cout << "Enter radius of circle C2: ";
	cin >> c2r;

	cout << "Enter x and y coordinates of circle C3 (2 values): ";
	cin >> c3x >> c3y;
	cout << "Enter radius of circle C3: ";
	cin >> c3r;

  // Prompt and read in query point
	cout << "Enter x and y coordinates of query point (2 values): ";
	cin >> px >> py; 

	dc1 = sqrt(pow((px - c1x), 2.0) + pow((py - c1y), 2.0));
	dc2 = sqrt(pow((px - c2x), 2.0) + pow((py - c2y), 2.0));
	dc3 = sqrt(pow((px - c3x), 2.0) + pow((py - c3y), 2.0));

  // Determine location of query point relative to the circles
	if (dc1 <= c1r) 
	{
		// if in C1 check C2
		if (dc2 <= c2r)
		{
			// if C1 and C2 check C3
			if (dc3 <= c3r) 
			{
				// print out all circles contain point
				cout << "Circles C1, C2, and C3 contain point (" << px << "," << py << ")." << endl;
			} else 
			{ 

				// print C1 and C2 contain point since C3 doesn't
				cout << "Circles C1 and C2 contain point (" << px << "," << py << ")." << endl;
			}
		
		// Not C2 but C1, so check C3
		} else if (dc3 <= c3r) 
		{
			// print C1 and C3 contain point
			cout << "Circles C1 and C3 contain point (" << px << "," << py << ")." << endl;
		} else 
		{			
			// Not C2 or C3, print only C1 contains point
			cout << "Circle C1 contains point (" << px << "," << py << ")." << endl;
		}

	// Not C1, check C2
	} else if (dc2 <= c2r) 
	{
		// if C2, check C3
		if (dc3 <= c3r) 
		{
			// print out C2 and C3 contain point
			cout << "Circles C2 and C3 contain point (" << px << "," << py << ")." << endl;
		} else 
		{
			// Not C3 but C2, print C2 contains point
			cout << "Circle C2 contains point (" << px << "," << py << ")." << endl;
		}

	// Not C1 or C2, check C3
	} else if (dc3 <= c3r)  
	{
		// Print C3 contains point
		cout << "Circle C3 contains point (" << px << "," << py << ")." << endl;
	// Not any circle contains point, print out
	} else 
	{
		cout << "No circle contains point (" << px << "," << py << ")." << endl;
	}


  return 0;
}
