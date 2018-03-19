/*
  File: rectangles.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
*/

#include <iostream>
#include <string>
#include <vector>

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

class Rectangle
{
private:
	string name;
	Point blPoint;
	double length, height;

public:
	// member functions
	void setName(const string & inName);
	void setBottomLeft(const double x, const double y);
	void setDimensions(const double inLength, const double inHeight);

	string getName() const;
	Point getBottomLeft() const;
	double getLength() const;
	double getHeight() const;
	
	double area() const;
	double perimeter() const;
	Point midPoint() const;
	void scaleBy3();
	void display() const;
};

// FUNCTION PROTOTYPES GO HERE:

int main()
{
	// Define your local variables, e.g. a vector of class Rectangle
	
	// Display welcome banner

	/* Prompt user for first rectangle or 'stop' */
	// WHILE user input is invalid
		// Display "Try again! "

	// IF user input is not 'stop'
		// Extract rectangle name from user input
		// Prompt for bottom left point
		// Prompt for length and height
		// Add rectangle to the rectangle list
	
	/* Prompt user for next rectangle or 'stop' */
	// WHILE user input is not 'stop'
		// Display "Thank you! "

		// WHILE user input is invalid
			// Display "Try again! "
			// IF user input is not 'stop'
				// Extract rectangle name from user input
				// Prompt for bottom left point
				// Prompt for length and height
				// Add rectangle to the rectangle list

	// IF the rectangle list is not empty
		// Display all rectangles in the rectangle list
	// ELSE 
		// Display that no rectangles are in the list
  
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

void Rectangle::setName(const string & inName) 
{
	// replace with your code
}

void Rectangle::setBottomLeft(const double x, const double y) 
{
	// replace with your code
}

void Rectangle::setDimensions(const double inLength, const double inHeight) 
{
	// replace with your code
}

string Rectangle::getName() const
{
	// replace with your code
}

Point Rectangle::getBottomLeft() const
{
	// replace with your code
}

double Rectangle::getLength() const
{
	// replace with your code
}

double Rectangle::getHeight() const
{
	// replace with your code
}

double Rectangle::area() const
{
	// replace with your code
}
	
double Rectangle::perimeter() const
{
	// replace with your code
}

Point Rectangle::midPoint() const
{
	// replace with your code
}
	
void Rectangle::scaleBy3() 
{
	// replace with your code
}

void Rectangle::display() const
{
	// replace with your code
}			