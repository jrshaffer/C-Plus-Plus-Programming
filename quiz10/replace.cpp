/*
  File: replace.cpp
  Created by:Joseph Shaffer
  Creation Date: November 18, 2016
  Synopsis: The program reads three strings
  from the user: a phrase, a letter to replace,
  and a replacement letter. The program will change
  the phrase by replacing each occurrence of a 
  letter with a replacement letter

*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes

/* replace will replace all occurrences of a letter in a phrase
   with a replacement letter. The function takes in string by reference
   and two more strings as constants and by reference and a vector of
   characters by reference.
*/
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text);

/* display_ phrase, takes in the vector of characters as a constant 
   and by reference and simply displays the contents of the vector passed in
*/
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

/* replace will replace all occurrences of a letter in a phrase
   with a replacement letter. The function takes in string by reference
   and two more strings as constants and by reference and a vector of
   characters by reference.
*/
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text)
{
	for (int i = 0; i < phrase.length(); i++) {
		if (phrase.substr(i, 1) == letter) {
			phrase.replace(i, 1, replacement);
		}
		text.push_back(phrase[i]);
	}
	cout << endl;
}

/* display_ phrase, takes in the vector of characters as a constant 
   and by reference and simply displays the contents of the vector passed in
*/
void display_phrase(const vector<char> & text)
{
	for (int i = 0; i < text.size(); i++) {
		cout << text[i];
	}
}
