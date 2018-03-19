/*
  File: temps.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class MilTime
{
private:
	int hour;
	int minutes;

public:
	int getHour() const;
	int getMin() const;
	void setHour(const int h);
	void setMin(const int m);
	
	void write_out(ofstream & fout);
};

class Celsius
{
private:
	double degree;
	MilTime time;

public:
	// member functions
	double getTemp() const;
	MilTime getTime() const;
	double getFahrenheit() const;
	
	void setTemp(const double temp);
	void setTime(const int h, const int m);
	
	void write_out(const string fname) const;
};

// FUNCTION PROTOTYPES GO HERE:
string read_filename(const string prompt);
int read_num_samples(const string prompt);
Celsius read_sample(const int k);
void write_to_file(const string filename, const vector<Celsius> & samples);
double average_temp(const vector<Celsius> samples);
double hottest_temp(const vector<Celsius> samples);
MilTime first_sample(const vector<Celsius> samples);

int main()
{
  
	// Define local variables
	string fname;   	 	// Output file name
	int n;				// Number of temperature samples
	vector<Celsius> temps;	// Temperature samples
	
	// Prompt for the name of the output file to write
	fname = read_filename("Enter the output file name: ");
	
	// Prompt for the number of temperature samples
	n = read_num_samples("Enter the number of samples: ");
	
	// Read temperature samples from user
	for (int i = 0; i < n; i++) {
		cout << endl;
		temps.push_back(read_sample(i + 1));
	}
	
	// Write the sample information to the outputfile
	write_to_file(fname, temps);
	cout << endl;
  	
	return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
			 
// CLASS MEMBER FUNCTION DEFINITINOS GO HERE:
	
int MilTime::getHour() const 
{
	/* INSERT YOUR CODE */
}

int MilTime::getMin() const 
{
	/* INSERT YOUR CODE */
}

void MilTime::setHour(const int h) 
{
	/* INSERT YOUR CODE */
}

void MilTime::setMin(const int m) 
{
	/* INSERT YOUR CODE */
}

void MilTime::write_out(ofstream & fout)
{
	/* INSERT YOUR CODE */
}

double Celsius::getTemp() const
{
	/* INSERT YOUR CODE */
}

MilTime Celsius::getTime() const
{
	/* INSERT YOUR CODE */
}

double Celsius::getFahrenheit() const
{
	/* INSERT YOUR CODE */
}
	
void Celsius::setTemp(const double temp) 
{
	/* INSERT YOUR CODE */
}

void Celsius::setTime(const int h, const int m) 
{
	/* INSERT YOUR CODE */
}

string read_filename(const string prompt)
{
	/* INSERT YOUR CODE */
}

int read_num_samples(const string prompt)
{
	/* INSERT YOUR CODE */
}

Celsius read_sample(const int k)
{
	/* INSERT YOUR CODE */
}

void write_to_file(const string filename, const vector<Celsius> & samples)
{
	/* INSERT YOUR CODE */
}

double average_temp(const vector<Celsius> samples)
{
	/* INSERT YOUR CODE */
}

double hottest_temp(const vector<Celsius> samples)
{
	/* INSERT YOUR CODE */
}

MilTime first_sample(const vector<Celsius> samples)
{
	/* INSERT YOUR CODE */
}
