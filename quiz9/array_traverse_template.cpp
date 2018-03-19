/*
  File: array_traverse.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE(10);
  
// Function prototypes
void read_list(int a[], int & num_elements);
void print_array(const int a[], const int num_elements);
double compute_average(const int a[], const int num_elements);
void print_evens_below(const int a[], const int num_elements, const double val);

int main()
{
  int num_elements(0);
  double avg(0.0);
  int array[SIZE];

  read_list(array, num_elements);
	
  if (num_elements > 0)
  {
	// Display original list
	cout << endl << "You entered the list:" << endl;
	print_array(array, num_elements);
	
	// Compute average
	avg = compute_average(array, num_elements);
	cout << "Average = " << avg << endl;
	
	// Display list values less than the average
	cout << endl << "Even values at or below the average:" << endl; 
	print_evens_below(array, num_elements, avg);
  }
  else {
	cout << "The list is empty." << endl;
  }
  
  return 0;
}

// INSERT FUNCTIONS HERE