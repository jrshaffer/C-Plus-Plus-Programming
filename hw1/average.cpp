// File: average.cpp
// Created by: Naeem Shareef
// Modified by: Joseph Shaffer
// Modified on: September 5, 2016

/* A program to compute the averages of 3,5,8 and 
   of 4,6,13 and of 7,9,13,14 and output the 
   three averages on separate lines.
*/

#include <iostream>
using namespace std;

int main()
{

  // Calculates Average of 3, 5, and 8 and writes result
  cout << "The average of 3, 5 and 8 is: "  << (3 + 5 + 8) / 3.0 << endl;                      

  // Calculates Average of 4, 6, & 13 and writes result
  cout << "The average of 4, 6 and 13 is: " << (4 + 6 + 13) / 3.0 << endl;                    

  // Calculates Average of 7, 9, 13, and 14 and writes result
  cout << "The average of 7,9,13 and 14 is: " << (7 + 9 + 13 + 14) / 4.0 << endl;   

  return 0;
}
