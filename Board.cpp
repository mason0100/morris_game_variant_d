#include "Board.h"

Board::Board(string tempBoard) {
	board1 = tempBoard;
	cout << board1 << endl;
}

void Board::minimaxOpening(string &tempBoard1, string &tempBoard2, int turn, int depth) {
	board1 = tempBoard1;
	board2 = tempBoard2;

	if (depth == 0) {
		//return the node because the bottom of the tree has been reached
	}

	if (turn == 0) {
		//whites turn
	}
	else{//turn == 1
		//blacks turns
	}

	//must make a node

	//must print out the results with a function to be created

}
