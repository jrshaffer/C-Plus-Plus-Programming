/*
  File: pickstones.cpp
  Created by:Joseph Shaffer
  Creation Date: November 1, 2016
  Synopsis: This program is a game 
  where the program prompts the user to
  enter 1 to 20 rods, and each rod can 
  contain 1 to 10 stones. The game 
  is played with 2 players, where each 
  player takes turns removing a certain
  amount of stones from a certain rod.
  The winner is the player that removes
  the last stone from the last rod.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string> // included to draw the stones

using namespace std;

// Made constants passed by reference instead of value to 
// save memory from creating copies of variable values.

// FUNCTION PROTOTYPES GO HERE:
/* prompts the reader for the number of rods 
   in the game, the parameter is constant as it
   cannot be changed and it the number of rods
   cannot be greater than the max constant
*/
int promptRods(const int max_rods);

/* 
   calls the promptStonesPerRod function and passes the maxStones
   array of rods variables and the index of the array to the function
   as constants except the array which is passed by reference,
   passes the array of rods by reference to update each index of
   the array, the other parameters are constant because the values
   for the size of the array and the max number of stones in a rod
   should not be changed and are thus constant 
*/
void promptStones(int *x, const int size, const int maxStones);

/* prompts the reader for how many stones to input in each rod
   the array of rods is passed by reference, while the index of 
   the array(i) and the max number of stones per rod are passed by
   value and are constant since they will not be changed.
*/
void promptStonesPerRod(int *x, const int i, const int maxStones);

/* drawRod has the array passed by reference and the size of the array
   passed by value and constant as it will not be changed. The function
   uses helper function to print out the current state of each rod, with
   the number of stones in each rod at each moment.
*/
void drawRods(int *x, const int size);

/* printDrawRods, has the index of the rod array, the number of stones for
   the rod and the total number of stones in the array passed as constants
   and calls the print stones function to help output the number of stones per
   rod 
*/
void printDrawRods(const int index, const int stones, const int total);
 
/* 
   printStones is a helper that returns a string of symbols representing
   the number of stones per each rod. The helper function takes in the 
   number of stones per rod in as a constant since the value will not be
   changed.
*/
string printStones(const int stones);

/* statistics is a function that calls on 3 helper functions to output
   which rods have the lowest number of stones, which rods have the 
   highest number of stones, and the average number of stones for non-
   empty rods. Has the array passed by reference and the size passed
   as a constant value and passes the array by reference and size
   by value to the helper values.
*/
void statistics(int *x, const int size);

/* helper function to statistics that finds and outputs the rod with
   the smallest number of stones when they are not 0
*/
void smallestRod(int *x, const int size);

/* helper function to statistics that finds and outputs the rod with
   the highest number of stones
*/
void largestRod(int *x, const int size);

/* helper function to statistics that finds and outputs the 
   average number of stones per rods that are not empty
*/
void averageNumberPerRod(int *x, const int size);

/* function has array passed by reference and size of array passed
   by value and determines if all the rods in the array have 0
   stones in them and returns true if so and false otherwise
*/
bool zeroStonesLeft(int *x, const int size);

/* makeMove takes int five parameters, the array of rods, the rod being chosen
   and the number of stones being removed by reference. It also has the size
   of the array and the id of the player passed by value and as a constant since
   the values do not change. The function has 4 helper functions to determine
   how many stones the specific player wants to move from a specific rod in the
   array
*/
void makeMove(int *x, const int size, const int id, int &rod,  int &stones);

/* rodPrompt takes in the player id as a constant value and continuously prompts
   the user for which rod that they want to remove stones from until the rod they
   choose exists and is not empty
*/
int rodPrompt(const int id);

/* verifyRod, takes in the rod as the reference, the player id and size of the array
   as a constant and determines if the rod chosen by the player exists and if not
   the user is prompted again by rodPrompt for a new rod to remove stones from. Thus, the value
   of rod can change.
*/
void verifyRod(const int id, int &rod, const int size);

/* verify stones takes in the array of rods and the rod chosen by reference and the id
   of the player as a constant value. The procedure determines if the rod chosen has
   any stones in it or not. If it does not, the function calls on rodPrompt again
   for a new value 
*/
void verifyStones(int *x, const int id, int &rod);

/* stonesToRemove takes in the number of stones and the corresponding
   rod and returns the number of stones to be removed from that
   rod, takes in the number of stones for that rod and the rod id
   as constant values
*/
int stonesToRemove(const int stones, const int rod);


/* updates the number of stones in a rod by taking out the number
   of stones the user wants to remove from a specific rod. Takes
   the array of rods in as a reference and the specific rod and 
   number of stones to be removed in as a constant value
*/
void updateStonesPerRod(int *x, const int rod, const int stones);

/* congratulate takes in the player's id as a constant value
   and outputs a message congratulating the player who won
*/
void congratulate(const int id);

/* the player id is passed as a reference as is changed to either
   player 1 or player 2 depending on whether the last player was 
   player 1 or player 2
*/
void changePlayer(int &id);


int main()
{
  // Define variables and constants here
	const int max_rods(20); // max number of rods per game constant
	const int max_stones(10); // max number of stones per rod constant
	int n; // Size of array of rods by user input for game
	int *x; // Pointer to array of size n
	int playerId(1); // integer for the player id
	int rodId;	// rod the player has chosen
	int removeStones; // number of stones player wants to remove

  // Algorithm:
  
  // Prompt and read number of rods
	// size of array or number of rods is return value of function
	n = promptRods(max_rods);

	// initialize pointer to array of size n

	x = new int[n]; // array of number of rods

	cout << endl; // new line

  // Prompt and read the number of objects in each rod
	
	// function inputs a different number of stones into each rod
	promptStones(x, n, max_stones);

	cout << endl; // new line
  // Draw the rods with percentages
	
	// function draws current state of game
	// outputs '*' for each stone in each rod
	drawRods(x, n);

	cout << endl; // new line
  
  // Display statistics

	/* output the statistics of the game
	   which rods have the smallest number of
           stones greater than 0 and which rods
	   have the most stones, and the average
           number of stones for non-empty rods.
	*/
	statistics(x, n);

	cout << endl; // new line

  // WHILE some rod is NOT empty DO
	// while a rod still has at least stone in it, game continues
	while (zeroStonesLeft(x, n) == false) {
		

	// Prompt and read the next player's move	
		
		/* the player, who's turn it is, inputs, which
          	   rod and how many stones they want to remove
		*/
		makeMove(x, n, playerId, rodId, removeStones);

		cout << endl; // new line

	// Remove the specified number of objects from the specified rod
		/* the array is updated by removing the number of stones
		   from the rod chosen above
		*/
		updateStonesPerRod(x, rodId, removeStones);

     	// IF all the heaps are empty, THEN
		// if no stones left after move
		if (zeroStonesLeft(x, n)) {

	// Print a message congratulating the winning player.
			// current player wins
			congratulate(playerId);
		} else {

     // ELSE

        // Redraw the rods with percentages
			// shows current state of rods and stones again
			drawRods(x, n);

			cout << endl; // new line

	// Display statistics
			// shows statistics per rod again
			statistics(x, n);

			cout << endl; // new line

        // Change to the other player	
			// change player id so other player gets a turn
			changePlayer(playerId);
		} // END IF
	} // END WHILE Game Over
	delete []x; // delete array
  
  return 0; // END Program
}
		 
// FUNCTION DEFINITIONS GO HERE:
/* prompts the reader for the number of rods 
   in the game, the parameter is constant as it
   cannot be changed and it the number of rods
   cannot be greater than the max constant
*/
int promptRods(const int maxRods) {
	int x;
	cout << "How many rods are in this game? ";
	cin >> x;
	while (x <= 0 || x > maxRods) {
		cout << "Number of rods must be positive and less than or equal to 20" << endl;
		cout << "Enter number of rods again : ";
		cin >> x;
	}
	return x;
}

/* 
   calls the promptStonesPerRod function and passes the maxStones
   array of rods variables and the index of the array to the function
   as constants except the array which is passed by reference,
   passes the array of rods by reference to update each index of
   the array, the other parameters are constant because the values
   for the size of the array and the max number of stones in a rod
   should not be changed and are thus constant 
*/
void promptStones(int *x, const int size, const int maxStones) {
	for (int i = 0; i < size; i++) {
		promptStonesPerRod(x, i, maxStones);
	}
}

void promptStonesPerRod(int *x, const int i, const int maxStones) {
	cout << "How many stones are on rod " << i + 1 << ": ";
		cin >> x[i];
		while (x[i] <= 0 || x[i] > maxStones) {
			cout << "Sorry, the number of stones must be positive and less than or equal to 10." << endl;
			cout << "How many stones are on rod " << i + 1 << ": ";
			cin >> x[i];
		}
}

/* drawRod has the array passed by reference and the size of the array
   passed by value and constant as it will not be changed. The function
   uses helper function to print out the current state of each rod, with
   the number of stones in each rod at each moment.
*/
void drawRods(int *x, const int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += x[i];
	}
	for (int i = 1; i <= size; i++) {
		printDrawRods(i, x[i - 1], total);
	}
}

/* printDrawRods, has the index of the rod array, the number of stones for
   the rod and the total number of stones in the array passed as constants
   and calls the print stones function to help output the number of stones per
   rod 
*/
void printDrawRods(const int index, const int stones, const int total) {
	string stonesPrinted = printStones(stones);
	cout << "Rod " << setw(3) << index << ": " << setw(10) << left << stonesPrinted << setw(5) << right << "(" << fixed << setprecision(3) << (((double)stones / (double) total) * 100.00) << "%)" << endl;
}

/* 
   printStones is a helper that returns a string of symbols representing
   the number of stones per each rod. The helper function takes in the 
   number of stones per rod in as a constant since the value will not be
   changed.
*/
string printStones(const int stones) {
	string stonesPrinted;
	for (int i = 0; i < stones; i++) {
		stonesPrinted += '*';
	}
	return stonesPrinted;
}


/* statistics is a function that calls on 3 helper functions to output
   which rods have the lowest number of stones, which rods have the 
   highest number of stones, and the average number of stones for non-
   empty rods. Has the array passed by reference and the size passed
   as a constant value and passes the array by reference and size
   by value to the helper values.
*/
void statistics(int *x, const int size) {
	smallestRod(x, size);
	largestRod(x, size);
	averageNumberPerRod(x, size);
}

/* helper function to statistics that finds and outputs the rod with
   the smallest number of stones when they are not 0
*/
void smallestRod(int *x, const int size) {
	int min = 10;
	for (int i = 0; i < size; i++) {
		if (x[i] < min && x[i] > 0) {
			min = x[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (x[i] == min) {
			cout << "Rod " << i + 1 << " has the smallest number of stones with " << min << " object(s)." << endl;
		}
	}
}

/* helper function to statistics that finds and outputs the rod with
   the highest number of stones
*/
void largestRod(int *x, const int size) {
	int max = 1;
	for (int i = 0; i < size; i++) {
		if (x[i] > max) {
			max = x[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (x[i] == max) {
			cout << "Rod " << i + 1 << " has the largest number of stones with " << max << " object(s)." << endl;
		}
	}
}

/* helper function to statistics that finds and outputs the 
   average number of stones per rods that are not empty
*/
void averageNumberPerRod(int *x, const int size) {
	int total = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		total += x[i];
		if (x[i] > 0) {
			count++;
		}
	}
	cout << "The average number of stones per rod (i.e., rods with stones) is " << setprecision(2) << (double) total / count << " stones." << endl;
}

/* function has array passed by reference and size of array passed
   by value and determines if all the rods in the array have 0
   stones in them and returns true if so and false otherwise
*/
bool zeroStonesLeft(int *x, const int size) {
	for (int i = 0; i < size; i++) {
		if (x[i] > 0) {
			return false;
		}
	}
	return true;
}

/* makeMove takes int five parameters, the array of rods, the rod being chosen
   and the number of stones being removed by reference. It also has the size
   of the array and the id of the player passed by value and as a constant since
   the values do not change. The function has 4 helper functions to determine
   how many stones the specific player wants to move from a specific rod in the
   array
*/
void makeMove(int *x, const int size, const int id, int &rod,  int &stones) {
	rod = rodPrompt(id);
	while (rod <= 0 || rod > size || x[rod - 1] == 0) {
		verifyRod(id, rod, size);
		verifyStones(x, id, rod);
	}
	stones = stonesToRemove(x[rod - 1], rod);
	while (stones <= 0 || stones > x[rod - 1]) {
		if (stones <= 0) {
			cout << "Number of stones you can remove must be positive. Try again." << endl;
		} else {
			cout << "Can only remove up to " << x[rod - 1] << " object(s). Please try again." << endl;
		}
		stones = stonesToRemove(x[rod - 1], rod);
	}
}

/* rodPrompt takes in the player id as a constant value and continuously prompts
   the user for which rod that they want to remove stones from until the rod they
   choose exists and is not empty
*/
int rodPrompt(const int id) {
	int rodId;
	cout << "Player (" << id << ") : Which rod would you like to play? ";
	cin >> rodId;
	return rodId;
}

/* verifyRod, takes in the rod as the reference, the player id and size of the array
   as a constant and determines if the rod chosen by the player exists and if not
   the user is prompted again by rodPrompt for a new rod to remove stones from. Thus, the value
   of rod can change.
*/
void verifyRod(const int id, int &rod, const int size) {
	while (rod <= 0 || rod > size) {
		cout << "Invalid rod number. Please try again." << endl;
		rod = rodPrompt(id);
	}
}

/* verify stones takes in the array of rods and the rod chosen by reference and the id
   of the player as a constant value. The procedure determines if the rod chosen has
   any stones in it or not. If it does not, the function calls on rodPrompt again
   for a new value 
*/
void verifyStones(int *x, const int id, int &rod) {
	if (x[rod - 1] == 0) {
		cout << "Rod " << rod << " has zero stones. Please select a different rod." << endl;
		rod = rodPrompt(id);
	}
}

/* stonesToRemove takes in the number of stones and the corresponding
   rod and returns the number of stones to be removed from that
   rod, takes in the number of stones for that rod and the rod id
   as constant values
*/
int stonesToRemove(const int stones, const int rod) {
	int removeStones;
	cout << "Enter number of stones to remove (" << stones << " or less) from rod " << rod << ": ";
	cin >> removeStones;
	return removeStones;
}
	
/* updates the number of stones in a rod by taking out the number
   of stones the user wants to remove from a specific rod. Takes
   the array of rods in as a reference and the specific rod and 
   number of stones to be removed in as a constant value
*/
void updateStonesPerRod(int *x, const int rod, const int stones) {
	x[rod - 1] -= stones;
}

/* congratulate takes in the player's id as a constant value
   and outputs a message congratulating the player who won
*/
void congratulate(const int id) {
	cout << "Congratulations! Player " << id << " wins." << endl;
}

/* the player id is passed as a reference as is changed to either
   player 1 or player 2 depending on whether the last player was 
   player 1 or player 2
*/
void changePlayer(int &id) {
	if (id == 1) {
		id = 2;
	} else {
		id = 1;
	}
}






