#pragma once
#include <iostream>
#include <string.h>
#include <vector>


using namespace std;


class Game
{
public:

	//represents each board postion
	struct node {
		int miniMaxEstimate = 0;
		string  board = "";
	};

	Board(string tempBoard);
	void minimaxOpening(string &tempBoard1, string &tempBoard2, int turn, int depth);

private:
	string board1;
	string board2;
	
	
};

