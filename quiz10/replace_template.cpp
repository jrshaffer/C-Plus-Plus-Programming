/*
  File: replace.cpp
  Created by:??
  Creation Date: ??
  Synopsis: ??
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text);
void display_phrase(const vector<char> & text);
 
int main()
{
  string phrase, letter, replacement;
  vector<char> text_vec;

  cout << "Enter phrase: ";
  getline(cin, phrase);

  if (phrase.length() > 0)
  {
	cout << "Enter letter to replace: ";
	getline(cin, letter);

	if (letter.length() == 1)
	{
		cout << "Enter replacement letter: ";
		getline(cin, replacement);
  
		if (replacement.length() == 1)
		{
			replace(phrase, letter, replacement, text_vec);
			cout << "String phrase: " << phrase << endl;
			cout << "Vector phrase: ";
			display_phrase(text_vec);
			cout << endl;
		}
		else
		{
			cout << "Replacement letter must be a single letter" << endl;
		}
	}
	else
	{
		cout << "Letter to replace must be a single letter" << endl;
	}
  }
  
  return 0;
}

// FUNCTION 
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text)
{
	// Insert your code here
}

void display_phrase(const vector<char> & text)
{
	// Insert your code here
}