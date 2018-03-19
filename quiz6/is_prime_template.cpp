/*
  File: is_prime.cpp
  Created by: ??
  Creation Date: ??
  Synopsis:
  This program determines if an input value is a prime number
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  bool isprime(true);
  int i, number;

  cout << "Enter an integer greater than 2: ";
  cin >> number;
  cout << endl;
  
  i = 2;
  while (i < number) {
	if (number % i == 0) {
		isprime = false;
	}
	i++;
  }
  
  if (isprime) {
	cout << "The value " << number << ": PRIME." << endl;
  }
  else
  {
	cout << "The value " << number << ": NOT PRIME." << endl;
  }
  return 0;
}
