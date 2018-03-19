/*
  File: isprime.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
  
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR read_range


// FUNCTION PROTOTYPE FOR is_prime


// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
  int imin(0), imax(0);

  // Read in range
  read_range(imin, imax);

  // Print prime numbers
  cout << "Primes:";
  for (int j = imin; j <= imax; j++) {
    if (is_prime(j)) 
      { 
        cout << "  " << j; 
      }
  }
  cout << endl;

  return 0;
}

// DEFINE FUNCTION read_range() HERE:


// DEFINE FUNCTION is_prime() HERE:




