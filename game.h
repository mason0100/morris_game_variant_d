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
		string  board;//string representing char array for the board

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

	string board; // to be used as the global board
	string emptyBoard = "xxxxxxxxxxxxxxxxxxxxxxx";
	string board1;
	string board2;

	//helper funtions 
	//int position variable does not seem to be needed
	vector<int> generateMoveOpenings(int position, string board);
	vector<int> generateMovesMidgameEndgame(int position, string board);
	vector<int> generateAdd(int position, string board);
	vector<int> generateHopping(int position, string board);

	vector<string> generateMove(int position, string board);
	vector<string> generateRemove(int position, string board, vector<string> list);//be sure parameters are correct and rename vector<int> list
	vector<int> neighbors(int position);
	bool closeMill(int position, string board);
	int staticEstimationFunction(string board);
};

