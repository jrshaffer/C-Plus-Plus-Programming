/*
  File: tris.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
*/

#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
private:
	double locx, locy;
	double length, height;

public:
	// member functions
	void setBottomLeftX(const double x);
	void setBottomLeftY(const double y);
	void setLength(const double inLength);
	void setHeight(const double inHeight);

	double getBottomLeftX() const;
	double getBottomLeftY() const;
	double getLength() const;
	double getHeight() const;
	
	double area() const;
	void display() const;
};

// FUNCTION PROTOTYPES GO HERE:
void read_triangle(Triangle & tri);

int main()
{
	// Define local variables
	Triangle tri;
	
	//Prompt the user for triangle information and fill Class Triangle object, tri,
	//with this information
	read_triangle(tri);
	
	// Display triangle information
	tri.display();
		
	return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
			 
// CLASS MEMBER FUNCTION DEFINITINOS GO HERE:

void Triangle::setBottomLeftX(const double x) 
{
	locx = x;
}

void Triangle::setBottomLeftY(const double y) 
{
	locy = y;
}

void Triangle::setLength(const double inLength) 
{
	length = inLength;
}

void Triangle::setHeight(const double inHeight) 
{
	height = inHeight;
}

double Triangle::getBottomLeftX() const
{
	return locx;
}

double Triangle::getBottomLeftY() const
{
	return locy;
}

double Triangle::getLength() const
{
	return length;
}

double Triangle::getHeight() const
{
	return height;
}

double Triangle::area() const
{
	/* INSERT YOUR CODE  */
}

void Triangle::display() const
{
	/* INSERT YOUR CODE  */	
}

void read_triangle(Triangle & tri)
{
	/* INSERT YOUR CODE  */
}
