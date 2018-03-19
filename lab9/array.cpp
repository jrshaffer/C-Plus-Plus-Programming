//File: array.cpp
// Created by: Joseph Shaffer
// Created on: November 2, 2016
/* Synopsis: The program asks the user
   to input up to 20 non-negative integers
   (>= 0) into an array. The program will only
   accept non-negative inputs and will end when 
   -99 is inputted. The program prints out the array,
    finds the max of the array and modifies the array by
    adding the max to each element of the array, and 
    finally the program prints out the modified array.

*/

#include <iostream>

using namespace std;

/* void read takes in 3 parameters, the constant is the max
   size of the array, the array is by reference since it is
   being manipulated, the n is by reference because it can be 
   the size of 0 through 20 and is the number of elements in the
   array
*/
void read_list(int numbers[], int &n, const int size);

/*void print_array takes in 2 parameters, the array
  and number of elements in the array as constants since
  they can not be manipulated
*/
void print_array(const int numbers[], const int n);

/* find_max returns the max value of the array and takes
   in 2 parameters, the array and the number of elements of 
   the array as constants since they will not be manipulated
*/
int find_max(const int numbers[], const int n);

/* array add takes in 3 parameters, the integer x and the number
   of elements in the array as constants and the array itself by
   reference because we are manipulating the elements of the array
*/
void array_add(const int x, int numbers[], const int n); 

int main() {
	const int max_size = 20; // max size of the array, stays constant

	int numbers[max_size]; // array declared to max size in memory

	int n(0);		// number of elements inputted into array

	int max(0);		// max value in array

	read_list(numbers, n, max_size); //calls read_list function

	cout << endl;			// new line
	
	// output statement for printing out original array
	cout << "Original list (" << n << " values):" << endl;
	
	// Call function to print out elements of array
	print_array(numbers, n);

	cout << endl; // new line

	// max value is changed to return value of find_max function
	max = find_max(numbers, n);
	
	// add max value to each element of array
	array_add(max, numbers, n);
	
	// output statement for printing out modified array
	cout << "Modified list (" << n << " values):" << endl;

	// print out modified array
	print_array(numbers, n);


return 0;
}

/* procedure will ask the user to enter non-negative numbers
   and terminate the input process when inputting -99. All 
   values 0 or greater will be inputted into the array. The procedure
   ignores any negative values and will end if -99 is inputted or 
   more than 20 numbers are inputted. Also less than 20 numbers can be
   inputted and the procedure keeps track of how many elements are 
   inputted into the array.
*/
void read_list(int numbers[], int &n, const int size) {
	int x(0);
	cout << "Enter non-negative numbers (ints) terminated by -99" << endl;
	while (x != -99 && n < size) {
		cin >> x;
		if (x >= 0) {
			numbers[n] = x;
			n++;
		}
	}
}

/* procedure prints out the contents of the array, which is 
   n elements, which can be in the range of 0 to 20 elements.
   Each element except for the last one has a comma after it,
   while the last element has a period after it.
*/
void print_array(const int numbers[], const int n) {
	
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << numbers[i] << "." << endl;
		} else {
			cout << numbers[i] << ", ";
		}
	}	
}

/* function returns the max value of the array. The function
   prints out what the max value is before returning.
*/
int find_max(const int negatives[], const int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (negatives[i] > max) {
			max = negatives[i];
		}
	}
	cout << "The maximum value is " << max << endl;
	cout << endl;
	return max;
}

/* procedure takes in an integer and adds the integer to each
   element of the array, the integer x will be the max value
   inputted from the main function when the procedure is called
   in main. The procedure modifies the array.
*/
void array_add(const int x, int negatives[], const int n) {
	for (int i = 0; i < n; i++) {
		negatives[i] += x;
	}
}


