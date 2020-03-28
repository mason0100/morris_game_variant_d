#pragma once
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


class Game
{
public:

	//represents each board postion
	struct Node {
		int miniMaxEstimate;
		string  boardPosition;//string representing char array for the board
	};

	//constructor
	Game(string tempBoard);

	//functions
	Node minimaxOpening(string &tempBoard1, string &tempBoard2, int turn, int depth);

private:
	//string constanats
	const char EMPTY = 'x';
	const char WHITE = 'W';
	const char BLACK = 'B';

	string emptyBoard = "xxxxxxxxxxxxxxxxxxxxxxx";
	string board1;
	string board2;

	//helper funtions 
	vector<string> generateMoveOpenings(string boardPosition);
	vector<string> generateMovesMidgameEndgame(string boardPosition);
	vector<string> generateAdd(string board);
	vector<string> generateHopping( string boardPosition);
	vector<string> generateMove(string boardPosition);
	vector<string> generateRemove(string boardPosition, vector<string> listOfBoardPositions);//be sure parameters are correct and rename vector<int> list
	vector<int> neighbors(int position);
	bool closeMill(int position, string boardPosition);
	int staticEstimationFunctionMidEnd(string boardPosition, vector<string> listOfBoardPositions);
	int staticEstimationFunctionOpening(string boardPosition);
};

