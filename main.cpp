#include <iostream>
#include <fstream>
#include <string>

#include "FileManager.h"
#include "Game.h"

using namespace std;


const string ERROR_MESSAGE_1 = "Parameters not entered correctley";
const string ERROR_MESSSAGE_2 = "Program selection parameter incorrect";

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

	if (argc != 5) {
		cout << ERROR_MESSAGE_1 << endl;
		return -1;
	}

	
	string inputFile = argv[1];
	string outputFile = argv[2];
	int depth = stoi(argv[3]);
	int selector = stoi(argv[4]);

	FileManager boardFile = FileManager();
	const string boardContents = boardFile.readFile(inputFile);
	Game board = Game();
	
	switch (selector) {
	case 0: 
		board.minimaxOpening(boardContents, true, 3);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 1:
		board.minimaxGame(boardContents, true, 3);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 2:
		board.ABOpening(boardContents, true, 3,INT_MIN, INT_MAX);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 3:
		board.ABGame(boardContents, true, 3, INT_MIN, INT_MAX);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 4:
		board.minimaxOpeningBlack(boardContents, true, 3);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 5:
		board.minimaxGameBlack(boardContents, true, 3);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 6:
		board.minimaxOpeningImproved(boardContents, true, 3);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	case 7:
		board.minimaxGameImproved(boardContents, true, 3);
		board.printGlobalVars(boardContents);
		boardFile.writeFile(Game::globalBoardPosition, outputFile);
		break;
	default:
		cout << ERROR_MESSSAGE_2 << endl;

	
	}

	return 0;
}


