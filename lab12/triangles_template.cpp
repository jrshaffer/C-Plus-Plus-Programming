/*
  File: triangles.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
*/

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	double px;
	double py;

public:
	void setX(const double x);
	void setY(const double y);
	double getX() const;
	double getY() const;
};

class Triangle
{
private:
	Point blPoint;
	double length, height;

public:
	// member functions
	void setBottomLeftX(const double x);
	void setBottomLeftY(const double y);
	void setLength(const double inLength);
	void setHeight(const double inHeight);

	Point getBottomLeft() const;
	Point getBottomRight() const;
	Point getTopLeft() const;
	double getLength() const;
	double getHeight() const;
	
	double perimeter() const;
	double hypotenuse() const;
	void scaleLength(const double sx);
	void scaleHeight(const double sy);
	void display() const;
};

// FUNCTION PROTOTYPES GO HERE:
void read_triangle(Triangle & tri);

int main()
{
	// Define local variables
	Triangle tri;
	double sx, sy;
	
	//Prompt the user for triangle information and fill Class Triangle object, tri,
	//with this information
	read_triangle(tri);
	
	// Display triangle information
	tri.display();
	
	// Prompt and read scale factors to change length and height
	cout << "Enter scale factor in x direction: ";
	cin >> sx;
	
	cout << "Enter scale factor in y direction: ";
	cin >> sy;
	
	// Apply scale factors
	tri.scaleLength(sx);
	tri.scaleHeight(sy);
	
	// Display triangle information
	tri.display();
	
	return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
			 
// CLASS MEMBER FUNCTION DEFINITINOS GO HERE:

void Point::setX(const double x) 
{
	px = x;
}

void Point::setY(const double y) 
{
	py = y;
}

double Point::getX() const 
{
	return (px);
}

double Point::getY() const 
{
	return (py);
}

void Triangle::setBottomLeftX(const double x) 
{
	/* INSERT YOUR CODE */
}

void Triangle::setBottomLeftY(const double y) 
{
	/* INSERT YOUR CODE */
}

void Triangle::setLength(const double inLength) 
{
	/* INSERT YOUR CODE */
}

void Triangle::setHeight(const double inHeight) 
{
	/* INSERT YOUR CODE */
}

Point Triangle::getBottomLeft() const
{
	/* INSERT YOUR CODE */
}

Point Triangle::getBottomRight() const
{
	/* INSERT YOUR CODE */
}

Point Triangle::getTopLeft() const
{
	/* INSERT YOUR CODE */
}

double Triangle::getLength() const
{
	/* INSERT YOUR CODE */
}

double Triangle::getHeight() const
{
	/* INSERT YOUR CODE */
}

double Triangle::hypotenuse() const
{
	/* INSERT YOUR CODE */
}
	
double Triangle::perimeter() const
{
	/* INSERT YOUR CODE */
}
	
void Triangle::scaleLength(const double scalefact) 
{
	/* INSERT YOUR CODE */
}

void Triangle::scaleHeight(const double scalefact) 
{
	/* INSERT YOUR CODE */
}

void Triangle::display() const
{
	/* INSERT YOUR CODE */
}

void read_triangle(Triangle & tri)
{
	/* INSERT YOUR CODE */
}
