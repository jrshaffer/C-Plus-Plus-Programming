/*
  File: freq.cpp
  Created by: Joseph Shaffer
  Creation Date: November 16, 2016
  Synopsis: This program asks the user to 
  input a line of text which can include
  any set of letters, numbers, or symbols,
  in any order that the user wishes. The program
  will read in this line of text and compute
  how many times each vowel (a, e, i, o, u, or y)
  occurs in that line of text and counts the number
  of consonants that appear in the line of text.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// FUNCTION PROTOTYPES GO HERE:

/* This procedure initializes the vector of vowels to 'a', 'e', 'i',
   'o', 'u', and 'y', and initializes the vector of frequencies to
    a size of 6 and full of 0's. Each vector is passed by reference
*/
void init_vectors(vector<char> & vowels, vector<int> & frequencies);

/* This function prompts the user to enter the text that they want.
   The function returns the text as a string and the prompt is passed
   as a constant string by reference.
*/
string read_text(const string & prompt);

/* is_alphabetic takes a character and returns true if the character passed
   by a constant value is in the alphabet and returns false otherwise.
*/
bool is_alphabetic(const char character);

/* create_list takes in the text from the user as a constant and by reference
   and an empty vector to store the text by reference. Only the characters
   from the user's inputted text that are part of the alphabet are inserted
   to the back of the text vector
*/
void create_list(const string & str_text, vector<char> & vec_text);

/* is_member returns true if the character passed by value is part of the 
   of the vector of characters that is passed as a constant and by reference.
   In the program this function is used to determine if a character in the 
   text is a vowel or not
*/
bool is_member(const vector<char> & list, char character);

/* find_index takes in a character passed by value and a vector that is 
   constant and passed by value and returns the index of the character
   in the vector parameter if the character is in the vector and returns 
   a -1 otherwise.
*/
int find_index(const vector<char> & list, char character);

/* compute_vowel_freqs is a function that takes in 3 vectors, 2 are constant
   but all are taken in by reference. The function goes through the text 
   vector that contains all the alphabetic characters from the inputted text
   from the user, and determines if each character in the text is a vowel or
   not by seeing if is in the vowels vector. The function then calls the find_index
   function to determine the index of the character if it is a vowel, because
   the index corresponds to what vowel the character is, thus the index corresponds
   to which value in the frequency vector at that index we increment by 1 if the 
   the character is a vowel. The function also keeps a count of how many consonants 
   there are in the text vector, and since all the characters in the text vector are
   alphabetic, any time a character is not a vowel, we increment the count of 
   consonants by 1 and return that value.
*/
int compute_vowel_freqs(const vector<char> & text, const vector<char> & vowels, vector<int> & freqs);

/* display_characters takes in a vector of characters as a constant and by 
   reference and an integer as a constant and by value. The procedure outputs
   the values stored in the vector, specifically the vowels in the vowel vector and
   uses the integer to format the output with setw() of the integer parameter.
*/
void display_characters(const vector<char> & characters, const int colwidth);

/* display_freqs takes in a vector of integers as a constant and by 
   reference and an integer as a constant and by value. The procedure outputs
   the values stored in the vector, specifically the frequencies of each vowel 
   stored in the frequency vector and uses the integer to format the output 
   with setw() of the integer parameter.
*/
void display_freqs(const vector<int> & freqs, const int colwidth);

int main()
{
	// Define local variables and constants
	vector<char> vowels; // vector of vowels(a, e, i, o, u, y)
	vector<int> freqs;   // vector representing frequencies of vowels in text
	string input;	     // string of text inputted from user
	vector<char> text;   // vector of alphabetic characters from inputted text
	int consonants(0);   // number of consonants in inputted text
	
	const int COLUMNWIDTH = 2; // constant column width to format output

	// Initialize the list of vowels and vowel frequencies.
	// Call function init_vectors with variables vowels and freqs
	init_vectors(vowels, freqs);
	
	// Prompt the user for the input text by calling function read_text	
	input  = read_text("Enter your text: ");
	
	// Copy the characters (ignoring non-alphabetic characters) in the input string to the vector of characters in variable text
	// Call function create_list to do this
	create_list(input, text);


	// Compute the frequencies of vowels and consonants from the input text containing only alphabetic letters
	// Call function compute_vowel_freqs to do this
	consonants = compute_vowel_freqs(text, vowels, freqs);

	
	// Display the vowels and their frequencies
	// Call functions display_characters and display_freqs
	display_characters(vowels, COLUMNWIDTH);

	display_freqs(freqs, COLUMNWIDTH);
	
	
	// Display the number of consonants. No function calls here.
	cout << "There are " << consonants << " consonants." << endl;
  
  return 0; // End Program
}
		 
// FUNCTION DEFINITIONS GO HERE:

/* This procedure initializes the vector of vowels to 'a', 'e', 'i',
   'o', 'u', and 'y', and initializes the vector of frequencies to
    a size of 6 and full of 0's. Each vector is passed by reference
*/
void init_vectors(vector<char> & vowels, vector<int> & frequencies) {
	vowels.push_back('a');
	vowels.push_back('e');
	vowels.push_back('i');
	vowels.push_back('o');
	vowels.push_back('u');
	vowels.push_back('y');
	for (int i = 0; i < 6; i++) {
		frequencies.push_back(0);
	}
}

/* This function prompts the user to enter the text that they want.
   The function returns the text as a string and the prompt is passed
   as a constant string by reference.
*/
string read_text(const string & prompt) {
	string text;
	cout << prompt;
	getline(cin, text);
	return text;
}


/* is_alphabetic takes a character and returns true if the character passed
   by a constant value is in the alphabet and returns false otherwise.
*/
bool is_alphabetic(const char character) {
	if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) {
		return true;
	}
	return false;	
}

/* create_list takes in the text from the user as a constant and by reference
   and an empty vector to store the text by reference. Only the characters
   from the user's inputted text that are part of the alphabet are inserted
   to the back of the text vector
*/
void create_list(const string & str_text, vector<char> & vec_text) {
	for (int i = 0; i < str_text.length(); i++) {
		if (is_alphabetic(str_text[i])) {
			vec_text.push_back(str_text[i]);
		}
	}
}

/* is_member returns true if the character passed by value is part of the 
   of the vector of characters that is passed as a constant and by reference.
   In the program this function is used to determine if a character in the 
   text is a vowel or not
*/
bool is_member(const vector<char> & list, char character) {
	for (int i = 0; i < list.size(); i++) {
		if (character == list[i]) {
			return true;
		}
	}
	return false;
}

/* find_index takes in a character passed by value and a vector that is 
   constant and passed by value and returns the index of the character
   in the vector parameter if the character is in the vector and returns 
   a -1 otherwise.
*/
int find_index(const vector<char> & list, char character) {
	for (int i = 0; i < list.size(); i++) {
		if (character == list[i]) {
			return i;
		}
	}
	return -1;
}

/* compute_vowel_freqs is a function that takes in 3 vectors, 2 are constant
   but all are taken in by reference. The function goes through the text 
   vector that contains all the alphabetic characters from the inputted text
   from the user, and determines if each character in the text is a vowel or
   not by seeing if is in the vowels vector. The function then calls the find_index
   function to determine the index of the character if it is a vowel, because
   the index corresponds to what vowel the character is, thus the index corresponds
   to which value in the frequency vector at that index we increment by 1 if the 
   the character is a vowel. The function also keeps a count of how many consonants 
   there are in the text vector, and since all the characters in the text vector are
   alphabetic, any time a character is not a vowel, we increment the count of 
   consonants by 1 and return that value.
*/
int compute_vowel_freqs(const vector<char> & text, const vector<char> & vowels, vector<int> & freqs) {
	int consonants(0);
	int index = -1;
	for (int i = 0; i < text.size(); i++) {
		if (is_member(vowels, tolower(text[i]))) {
			index = find_index(vowels, tolower(text[i]));
			freqs[index]++;
		} else {
			consonants++;
		}
	}
	return consonants;
}

/* display_characters takes in a vector of characters as a constant and by 
   reference and an integer as a constant and by value. The procedure outputs
   the values stored in the vector, specifically the vowels in the vowel vector and
   uses the integer to format the output with setw() of the integer parameter.
*/
void display_characters(const vector<char> & characters, const int colwidth) { 	
	cout << setw(colwidth) << characters[0];
	for (int i = 1; i < characters.size(); i++) {
		cout << ", " << setw(colwidth) << characters[i];
	}
	cout << endl;
}

/* display_freqs takes in a vector of integers as a constant and by 
   reference and an integer as a constant and by value. The procedure outputs
   the values stored in the vector, specifically the frequencies of each vowel 
   stored in the frequency vector and uses the integer to format the output 
   with setw() of the integer parameter.
*/
void display_freqs(const vector<int> & freqs, const int colwidth) {
	cout << setw(colwidth) << freqs[0];
	for (int i = 1; i < freqs.size(); i++) {
		cout << ", " << setw(colwidth) << freqs[i];
	}
	cout << endl;
}








