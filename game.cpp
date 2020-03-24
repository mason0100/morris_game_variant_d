#include "Game.h"

Game::Game(string tempBoard) {
	board1 = tempBoard;
	cout << board1 << endl;
}

Game::Node Game::minimaxOpening(string &tempBoard1, string &tempBoard2, int turn, int depth) {

	struct Node tempNode;

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


//static estimation 
int Game::staticEstimationFunction(string board) {

	int whitePieces = 0;
	int blackPieces = 0;
	int whiteMinusBlack = 0;

	for (int i = 0; i < board.size(); i++) {
		if (board[i] == 'W') {
			whitePieces++;
		}
	}

	for (int j = 0; j < board.size(); j++) {
		if (board[j] == 'B') {
			blackPieces++;
		}
	}
	whiteMinusBlack = whitePieces - blackPieces;
	return whiteMinusBlack;
}
