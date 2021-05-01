// Carrik McNerlin
// 2/16/2021
// This program will solve a maze that is included in the "Header Files" section.
// It uses the "right-hand rule" of following the right "wall" of the maze until it finds the exit.
#include <iostream>
#include "mazelayout1.h"

using namespace std;

//mazes are all 12x12
const int mazeWidth = 12;
const int mazeHeight = 12;

const char location = '@'; //represents where player is in map
const char firstPass = '*'; //if player has been to a position, it is marked with an x
const char secondPass = '-'; //replace x's when you backtrack

//Algorithm:
// try to move to right
// if wall, try moving forward
// if wall, try turning to left
// if wall there too, you're in a dead-end. Only turn around completely now.
// repeat

int main() {
	//initialize position to the start
	int currRow = startRow;
	int currCol = startCol;
	//start by facing to the east (into the maze)
	string currOrientation = "east";


	//****************************************************************************************************************************
	// IMPORTANT: Map origin is top left
	// Move east:	 row, col+1
	// Move south :	 row+1, col
	// Move west:	 row, col-1
	// Move north:	 row-1, col
	//****************************************************************************************************************************

	//****************************************************************************************************************************
	// Repeat the actions of trying to move forward or switch directions until you find the end of the maze.
	//****************************************************************************************************************************
	while ((currRow != endRow) || (currCol != endCol)) {

		//************************************************************************************************************************
		// Try to move forward. 
		// If you have to change direction, attempt to do so clockwise and in as few turns as possible.
		//************************************************************************************************************************
		
		// Had to make switch based on first character of orientation because the functionality throws a fit otherwise 
		switch (currOrientation[0]) {

			
			case 'e':
				// facing east: try south, east, north, west
				if (maze[currRow + 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move south
					currOrientation = "south";
					currRow++;
					maze[currRow][currCol] = location;
				}
				//east
				else if (maze[currRow][currCol + 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move east
					currOrientation = "east";
					currCol++;
					maze[currRow][currCol] = location;
				}
				//north
				else if (maze[currRow - 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move north
					currOrientation = "north";
					currRow--;
					maze[currRow][currCol] = location;
				}
				//west
				else if (maze[currRow][currCol - 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					currOrientation = "west";
					currCol--;
					maze[currRow][currCol] = location;
				}
			
				break;

			case 's':
				//try moving west, then south, then east, then north

				//west
				if (maze[currRow][currCol - 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					currOrientation = "west";
					currCol--;
					maze[currRow][currCol] = location;
				}
				//south
				else if (maze[currRow + 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move south
					currOrientation = "south";
					currRow++;
					maze[currRow][currCol] = location;
				}
				//east
				else if (maze[currRow][currCol + 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move east
					currOrientation = "east";
					currCol++;
					maze[currRow][currCol] = location;
				}
				//north
				else if (maze[currRow - 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move north
					currOrientation = "north";
					currRow--;
					maze[currRow][currCol] = location;
				}

			
				break;

			case 'w':
				// facing west: try north, west, south, east
				if (maze[currRow - 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move north
					currOrientation = "north";
					currRow--;
					maze[currRow][currCol] = location;
				}
				else if (maze[currRow][currCol - 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					currOrientation = "west";
					currCol--;
					maze[currRow][currCol] = location;
				}
				else if (maze[currRow + 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move south
					currOrientation = "south";
					currRow++;
					maze[currRow][currCol] = location;
				}
				else if (maze[currRow][currCol + 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move east
					currOrientation = "east";
					currCol++;
					maze[currRow][currCol] = location;
				}


				break;

			case 'n':
				// facing north: try east, north, west, south
				if (maze[currRow][currCol + 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move east
					currOrientation = "east";
					currCol++;
					maze[currRow][currCol] = location;
				}
				else if (maze[currRow - 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move north
					currOrientation = "north";
					currRow--;
					maze[currRow][currCol] = location;
				}
				else if (maze[currRow][currCol - 1] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					currOrientation = "west";
					currCol--;
					maze[currRow][currCol] = location;
				}
				else if (maze[currRow + 1][currCol] != '#') {
					//switch current position to indicate we've been there before
					if (maze[currRow][currCol] == '.') {
						maze[currRow][currCol] = firstPass;
					}
					else {
						maze[currRow][currCol] = secondPass;
					}

					//move south
					currOrientation = "south";
					currRow++;
					maze[currRow][currCol] = location;
				}
				break;
		}//end switch/case



		//print current maze
		for (int x = 0; x < mazeWidth; x++) {
			cout << "[";
				for (int y = 0; y < mazeHeight; y++) {
					cout << maze[x][y] << ", ";
				}
			cout << "]" << endl;
		}
		cout << "Currently facing: " << currOrientation << endl;
		cout << endl; //just making space between outputs

		system("pause"); //wait for my input so I can actually understand this mess
	} //end while


	//print the final maze
	cout << "MAZE SOLVED!" << endl;
	for (int x = 0; x < mazeWidth; x++) {
		cout << "[";
		for (int y = 0; y < mazeHeight; y++) {
			cout << maze[x][y] << ", ";
		}
		cout << "]" << endl;
	}
}