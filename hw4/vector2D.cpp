/*
  File: vector2D.cpp
  Created by: Joseph Shaffer
  Creation Date: October 11, 2016

  Synopsis: This program uses various functions
  to complete different operations on 2 dimensional
  vectors. The program uses functions to prompt the 
  user for 2 vectors and a scalar value. Then using
  the inputted values, the program uses functions
  to calculate the vector length of each vector, the
  vectors resulting from vector addition, subtraction,
  scalar multiplication and normalization of each or both
  of the vectors. Finally the program will tell us if the
  2 vectors inputted by the user are perpendicular to 
  each other by calling on another function.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPSILON(1e-12); // constant variable epsilon

// read_vector function prototype with parameters by reference
void read_vector(const string &PROMPT, double &x, double &y);

// vector_length function prototype with parameters by value
double vector_length(double x, double y);

// write_vector function prototype with parameters by reference and value
void write_vector(const string &MESSAGE, double x, double y);

// vector_add function prototype with parameters by value and reference
void vector_add(double x1, double y1, double x2, double y2, double &x3, double &y3);

// vector_subtract function prototype with parameters by value and reference
void vector_subtract(double x1, double y1, double x2, double y2, double &x3, double &y3);

// scalar_mult function prototype with parameters by value and reference
void scalar_mult(double x1, double y1, double s, double &x2, double &y2);

// normalize function prototype with parameters by reference
void normalize(double &x, double &y);

// perpendicular function prototype with paramaters by value
void perpendicular(double x1, double y1, double x2, double y2);

// NOT COMMENTING ON CODE IN MAIN AS I DID NOT WRITE IT

// *** DO NOT CHANGE ANY CODE IN THE MAIN FUNCTION.
int main()
{
  double u1, v1;	// coordinates of first vector
  double u2, v2;	// coordinates of second vector
  double u3, v3;
  double scalar;

  read_vector("Enter first vector (2 floats): ", u1, v1);
  read_vector("Enter second vector (2 floats): ", u2, v2);
  
  cout << "Enter scalar multiplier: ";
  cin >> scalar;
  cout << endl;

  write_vector("First vector: ", u1, v1);
  write_vector("Second vector: ", u2, v2);

  cout << endl;
  
  vector_add(u1, v1, u2, v2, u3, v3);
  write_vector("Vector add: ", u3, v3);

  vector_subtract(u1, v1, u2, v2, u3, v3);
  write_vector("Vector subtract: ", u3, v3);

  scalar_mult(u1, v1, scalar, u3, v3);
  write_vector("Scalar multiplier: ", u3, v3);

  cout << endl;
  
  write_vector("First vector: ", u1, v1);
  write_vector("Second vector: ", u2, v2);
  perpendicular(u1, v1, u2, v2);
  
  return(0);
}

/* read_vector has 3 parameters passed by reference
   function outputs the prompt and initializes parameters
   x and y to the input from the user after the prompt
*/
void read_vector(const string &PROMPT, double &x, double &y) {
	cout << PROMPT;
	cin >> x >> y;
}

/* vector_length has 2 parameters which are the x and y 
   values inputted by the user in read_vector
   the function calculates the length between the 2 
   coordinates and returns the calculated value
*/
double vector_length(double x, double y) {
	return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

/* write_vector 1 parameter by reference and two by value
   the function outputs the message passed to the function 
   and outputs the length between the 2 coordinates inputted
   by the user by using the vector_length function with
   passing parameters x and y into the function and then into
   vector_length function
*/
void write_vector(const string &MESSAGE, double x, double y) {
	cout << MESSAGE << "(" << x << ", " << y << ") has length " << vector_length(x, y) << endl;
}

/* vector_add takes in 4 parameters by value and 2 by reference
   the function does not return a value but changes the references of
   x3 to be x1 + x2 and y3 to be y1 + y2
*/
void vector_add(double x1, double y1, double x2, double y2, double &x3, double &y3) {
	x3 = x1 + x2;
	y3 = y1 + y2;
}

/* vector_subtract takes in 4 parameters by value and 2 by reference
   the function does not return a value but changes the references of 
   x3 to x1 - x2 and y3 to be y1 - y2
*/
void vector_subtract(double x1, double y1, double x2, double y2, double &x3, double &y3) {
	x3 = x1 - x2;
	y3 = y1 - y2;
}

/* scalar_mult takes in 3 parameters by value and 2 by refernce
   the function does not return a value but changes x2 to reference
   s * x1 and y2 to reference s * y1
*/
void scalar_mult(double x1, double y1, double s, double &x2, double &y2) {
	x2 = s * x1;
	y2 = s * y1;
}

/* normalize takes in 2 parameters by reference
   the function uses vector_length to calculate the length between
   x and y and if that length is 0 (or very, very close), the function
   sets x and y both to 0, and if the length is not 0, the function
   sets x to x divided by the length and y to y divided by the length
   which makes the vector of (x, y) to a unit vector of length 1;
*/
void normalize (double &x, double &y) {
	double length = vector_length(x, y);
	if (abs(length - 0) < EPSILON) {
		x = 0;
		y = 0;
	} else {
		x /= length;
		y /= length;
	}
}

/* perpendicular takes in 4 parameters by value
   the function uses the normalize function for x1, y1 and
   x2, y2. The function then creates perpendicular vectors p1 and 
   p2, which are perpendicular to unit vector v1, which corresponds
   to the normalized vector of x1, y1. The function then checks
   if the normalized vector of x2, y2 equals p1 or p2, and if so
   outputs that the vectors are perpendicular but if not, outputs
   that the vectors are not perpendicular.
*/
void perpendicular(double x1, double y1, double x2, double y2) {
	normalize(x1, y1);
	double vx1 = x1;
	double vy1 = y1;
	normalize(x2, y2);
	double vx2 = x2;
	double vy2 = y2;
	double px1 = -y1;
	double py1 = x1;
	double px2 = -px1;
	double py2 = -py1;
	if (abs(vx2 - px1) < EPSILON && abs(vy2 - py1) < EPSILON) {
		cout << "Vectors are PERPENDICULAR." << endl;
	} else if (abs(vx2 - px2) < EPSILON && abs(vy2 - py2) < EPSILON) {
		cout << "Vectors are PERPENDICULAR." << endl;
	} else { 
		cout << "Vectors are NOT PERPENDICULAR." << endl;
	}
}
	
	
