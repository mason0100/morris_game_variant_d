#include <iostream>
#include <fstream>
#include <string>

#include "FileManager.h"
#include "Game.h"

using namespace std;


const string ERROR_MESSAGE_1 = "Parameters not entered correctley";

//global class variable
int Game::globalPositionCount;
int Game::globalStaticEstimate;
string Game::globalBoardPosition;

int main(int argc, char* argv[]) {

	/*
	*argv[1] == input board
	*argv[2] == output board
	*argv[3] == depth to be evaluated
	*argv[4] == which program is to be ran, see ReadMe
	*/

	/*if (argc != 5) {
		cout << ERROR_MESSAGE_1 << endl;
		return -1;
	}*/

	//string fileName = argv[1];
	string fileName = "board1.txt";
	FileManager boardFile = FileManager();
	const string boardContents = boardFile.readFile(fileName);
	Game board = Game();
	board.minimaxOpening(boardContents, true, 3);
	board.printGlobalVars();

	//use switch statement and argv[4] to select program to run




	//need to write function to write ending result to second board.txt;
	return 0;
}


