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
	string board1;
	string board2;

	//helper funtions 
	vector<int> generateMoveOpenings(int position, string board);
	vector<int> generateMovesMidgameEndgame(int position, string board);
	vector<int> generateAdd(int position, string board);
	vector<int> generateHopping(int position, string board);
	vector<int> generateMove(int position, string board);
	vector<int> generateRemove(int position, vector<int> list, string board);//be sure parameters are correct and rename vector<int> list
	vector<int> neighbors(int position);
	bool closeMill(int position, string board);
	int staticEstimationFunction(string board);
};

