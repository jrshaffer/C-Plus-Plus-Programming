/*
  File: triangles.cpp
  Created by: Joseph Shaffer
  Creation Date: November 25, 2016
  Synopsis: This program asks the user
  for the x and y coordinate of the 
  bottom left point of a triangle. Then
  the program asks the user for the length 
  and height of the triangle and then wil display
  the coordinates of each point of the triangle,
  the dimensions of the triangle, as well as
  the hypotenuse and the perimeter of the triangle.
  The program will then ask the user for a value
  to scale the triangle in the x direction and a
  value to scale the triangle in the y direction.
  The program will use these scale factors and
  ouput the same items as above for the triangle
  after being scaled in the x and y directions.
*/

#include <iostream>
#include <cmath>

using namespace std;

/* class Point has 2 private fields, which are
   the x and y coordinates of the point object.
   class Point has 4 public member functions, two
   functions to set the x and y coordinates of 
   the point and two functions to retrieve the
   x and y coordinates of the point.
*/	

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


/* class Triangle has 3 private fields, one of class Point
   that represents the bottom left point of the triangle,
   and the other two of type double that represent the length
   and height of the triangle. class triangle has 14 member 
   functions. 4 of type void, which set the bottome left point's 
   x and y coordinates of the triangle and set the length and height of 
   the triangle. 3 member functions of type Point which return the
   different points of the triangle (bottom left, bottom right, and top left).
   2 Member functions return the length and height of the triangle. 2 other 
   functions return the perimeter and hypotenuse of the triangle. scaleLength
   and scaleHeight return the length and height of the triangle that
   is scaled by a factor passed into the function. Finally the function display()
   displays each point of the triangle, its dimensions, perimeter and hypotenuse.
*/
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
	
	return 0; // end program
}
		 
// FUNCTION DEFINITIONS GO HERE:
			 
// CLASS MEMBER FUNCTION DEFINITINOS GO HERE:

/* function of class point that sets private field
   px of the point to the passed in parameter
*/
void Point::setX(const double x) 
{
	px = x;
}

/* function of class point that sets private field
   py of the point to the passed in parameter
*/
void Point::setY(const double y) 
{
	py = y;
}

// returns x coordinate of point
double Point::getX() const 
{
	return (px);
}

// returns y coordinate of point
double Point::getY() const 
{
	return (py);
}

/* sets x coordinate of bottom left point
   to value passed in to function.
*/
void Triangle::setBottomLeftX(const double x) 
{
	blPoint.setX(x);
}

/* sets y coordinate of bottom left point
   to value passed in to function.
*/
void Triangle::setBottomLeftY(const double y) 
{
	blPoint.setY(y);
}

/* sets length of triangle 
   to value passed in to function.
*/
void Triangle::setLength(const double inLength) 
{
	length = inLength;
}

/* sets height of triangle 
   to value passed in to function.
*/
void Triangle::setHeight(const double inHeight) 
{
	height = inHeight;
}

// returns bottom left point of triangle
Point Triangle::getBottomLeft() const
{
	return blPoint;
}

// returns bottom right point of triangle
Point Triangle::getBottomRight() const
{
	Point brPoint; // new point object
	brPoint.setY(blPoint.getY()); // set y coordinate
	brPoint.setX(blPoint.getX() + length); // set x coordinate
	return brPoint; // return point
}

// returns top left point of triangle
Point Triangle::getTopLeft() const
{
	Point tlPoint;	// new point object
	tlPoint.setY(blPoint.getY() + height);	// set y coordinate
	tlPoint.setX(blPoint.getX());	// set x coordinate
	return tlPoint;	// return point
}

// return length of triangle
double Triangle::getLength() const
{
	return length;
}

// return height of triangle
double Triangle::getHeight() const
{
	return height;
}

// calculate and return hypotenuse of triangle
double Triangle::hypotenuse() const
{
	return sqrt(pow(length, 2.0) + pow(height, 2.0));
}
	
// calculate and return perimater of triangle
double Triangle::perimeter() const
{
	return length + height + hypotenuse();
}
	
// scale length by scaled factor passed into function
void Triangle::scaleLength(const double scalefact) 
{
	length *= scalefact;	
}

// scale height by scaled factor passed into function
void Triangle::scaleHeight(const double scalefact) 
{
	height *= scalefact;
}

/* display function displays the lower left vertex, the top
   left vertex and the bottom right vertex to the triangle, as well
   as the dimensions of the triangle (length and height), the hypotenuse
   and the perimeter of the triangle. By utiizing the member functions of
   both the triangle and point class, the display function can display
   all the fields of each triangle and each point on each triangle.
*/
void Triangle::display() const
{
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "Lower Left Vertex (" << blPoint.getX() << ", " << blPoint.getY() << ")" << endl;
	cout << "Top Left Vertex (" << getTopLeft().getX() << ", " << getTopLeft().getY() << ")" << endl;
	cout << "Bottom Right Vertex (" << getBottomRight().getX() << ", " << getBottomRight().getY() << ")" << endl;
	cout << "Dimensions (" << length << ", " << height << ")" << endl;
	cout << "Hypotenuse = " << hypotenuse() << endl;
	cout << "Perimeter = " << perimeter() << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
}

/* read_triangle takes in triangle object
   passed by reference and sets the x and y coordinates
   of the objects bottom left point from the user's input.
   The function also sets the length and height of the 
   triangle passed in from the user's input.
*/
void read_triangle(Triangle & tri)
{	
	double x;
	cout << "Enter bottom left x coordinate: ";
	cin >> x;
	tri.setBottomLeftX(x);
	cout << "Enter bottom left y coordinate: ";
	cin >> x;
	tri.setBottomLeftY(x);
	cout << "Enter length: ";
	cin >> x;
	tri.setLength(x);
	cout << "Enter height: ";
	cin >> x;
	tri.setHeight(x);
}






