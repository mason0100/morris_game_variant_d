#pragma once
#include <iostream>
#include <string.h>

using namespace std;


class Board
{
public:
	Board(string tempBoard);
	void minimaxOpening(string &tempBoard1, string &tempBoard2, int turn, int depth);

private:
	string board1;
	string board2;
	
	//represents each board postion
	struct Node {
		int miniMaxEstimate;
		string  board;
		Node(int x, string  board);
	};
};

