#pragma once
#include <iostream>
#include <string.h>

using namespace std;


class Game
{
public:

	//represents each board postion
	struct Node {
		int miniMaxEstimate;
		string  board;

	};


	Game(string tempBoard);
	Node minimaxOpening(string &tempBoard1, string &tempBoard2, int turn, int depth);

private:
	string board1;
	string board2;

	//helper funtions 
	int staticEstimationFunction(string board);
	
	
};

