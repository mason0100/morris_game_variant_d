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


//generates the moves for pieces
vector<string> Game::generateMove(int position, string board) {
	vector<string> list;
	for (int i = 0; i < board.size(); i++) {
		int positionI = i;
		if (board[positionI] == WHITE) {
			vector<int> tempNeighbors = neighbors(positionI);
			for (int j = 0; i < board.length; i++) {
				int positionJ = j;
				if (board[positionJ == EMPTY]) {
					//something happend here
				}
			}

		}
	}

	return list;
}


//removes piece from board
//this needs to be corrected suedo code is needs reevaluatings
vector<string> Game::generateRemove(int position, string board, vector<string> list) {
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == BLACK) {
			int position = i;
			if (closeMill(position, board) == false) {
				string tempBoard = board;
				tempBoard[i] = EMPTY;
				list.push_back(tempBoard);
			}
		}
	}
	//if no black pieces were added(all blaack pieces are in mills) add b to L
	//might be correct might not be correct take a closer look later
	//might need to put a copy of emptyBoard in list
	return list;
}


//Generates the neigbors of the given location
vector<int> Game::neighbors(int position) {
	switch (position) {
	case 0:
		return { 1,3,8 };
	case 1:
		return { 0,2,4 };
	case 2:
		return { 1,5,13 };
	case 3:
		return { 0,4,6,9 };
	case 4:
		return { 1,3,5 };
	case 5:
		return { 2,4,7,12 };
	case 6:
		return { 3,7,10 };
	case 7:
		return { 5,6,11 };
	case 8:
		return { 0,9,20 };
	case 9:
		return { 3,8,10,17 };
	case 10:
		return { 6,9,14 };
	case 11:
		return { 7,12,16 };
	case 12:
		return { 5,11,13,19 };
	case 13:
		return { 2,12,22 };
	case 14:
		return { 10,15,17 };
	case 15:
		return { 14,16,18 };
	case 16:
		return { 11,15,19 };
	case 17:
		return { 9,14,18,20 };
	case 18:
		return { 15,17,19,21 };
	case 19:
		return { 12,16,18,22 };
	case 20:
		return { 8,17,21 };
	case 21:
		return { 18,20,22 };
	case 22:
		return { 13,19,21 };
	default:
		return {};
	}
}


//closes a mill
bool Game::closeMill(int position, string board) {
	switch (position) {
	case 0: {
		if ((board[1] == board[0] && board[2] == board[0]) || 
			(board[3] == board[0] && board[6] == board[0]) || 
			(board[8] == board[0] && board[20] == board[0]))
			return true;
		else 
			return false; }
	case 1: {
		if ((board[0] == board[1] && board[2] == board[1])) 
			return true;
		else 
			return false; }
	case 2: {
		if ((board[0] == board[2] && board[1] == board[2]) || 
			(board[5] == board[2] && board[7] == board[2]) || 
			(board[13] == board[2] && board[22] == board[2]))
			return true;
		else 
			return false; }
	case 3: {
		if ((board[0] == board[3] && board[6] == board[3]) || 
			(board[4] == board[3] && board[5] == board[3]) || 
			(board[9] == board[3] && board[17] == board[3]))
			return true;
		else 
			return false; }
	case 4: {
		if ((board[3] == board[4] && board[5] == board[4])) 
			return true;
		else 
			return false; }
	case 5: {
		if ((board[2] == board[5] && board[7] == board[5]) || 
			(board[3] == board[5] && board[4] == board[5]) || 
			(board[12] == board[5] && board[19] == board[5]))
			return true;
		else return false; }
	case 6: {
		if ((board[0] == board[6] && board[3] == board[6]) || 
			(board[10] == board[6] && board[14] == board[6])) 
			return true;
		else 
			return false; }
	case 7: {
		if ((board[2] == board[7] && board[5] == board[7]) || 
			(board[11] == board[7] && board[16] == board[7])) 
			return true;
		else 
			return false; }
	case 8: {
		if ((board[0] == board[8] && board[20] == board[8]) || 
			(board[9] == board[8] && board[10] == board[8])) 
			return true;
		else 
			return false; }
	case 9: {
		if ((board[8] == board[9] && board[10] == board[9]) || 
			(board[3] == board[9] && board[17] == board[9])) 
			return true;
		else 
			return false; }
	case 10: {
		if ((board[8] == board[10] && board[9] == board[10]) || 
			(board[6] == board[10] && board[14] == board[10])) 
			return true;
		else 
			return false; }
	case 11: {
		if ((board[7] == board[11] && board[16] == board[11]) || 
			(board[12] == board[11] && board[13] == board[11])) 
			return true;
		else 
			return false; }
	case 12: {
		if ((board[11] == board[12] && board[13] == board[12]) || 
			(board[5] == board[12] && board[19] == board[12])) 
			return true;
		else 
			return false; }
	case 13: {
		if ((board[11] == board[13] && board[12] == board[13]) || 
			(board[2] == board[13] && board[22] == board[13])) 
			return true;
		else 
			return false; }
	case 14: {
		if ((board[6] == board[14] && board[10] == board[14]) || 
			(board[15] == board[14] && board[16] == board[14]) || 
			(board[17] == board[14] && board[20] == board[14])) 
			return true;
		else 
			return false; }
	case 15: {
		if ((board[14] == board[15] && board[16] == board[15]) || 
			(board[18] == board[15] && board[21] == board[15])) 
			return true;
		else 
			return false; }
	case 16: {
		if ((board[14] == board[16] && board[15] == board[16]) || 
			(board[19] == board[16] && board[22] == board[16]) || 
			(board[7] == board[16] && board[11] == board[16])) 
			return true;
		else 
			return false; }
	case 17: {
		if ((board[3] == board[17] && board[9] == board[17]) || 
			(board[18] == board[17] && board[19] == board[17]) || 
			(board[14] == board[17] && board[20] == board[17])) 
			return true;
		else 
			return false; }
	case 18: {
		if ((board[15] == board[18] && board[21] == board[18]) || 
			(board[17] == board[18] && board[19] == board[18])) 
			return true;
		else 
			return false; }
	case 19: {
		if ((board[17] == board[19] && board[18] == board[19]) || 
			(board[5] == board[19] && board[12] == board[19]) || 
			(board[16] == board[19] && board[22] == board[19])) 
			return true;
		else 
			return false; }
	case 20: {
		if ((board[0] == board[20] && board[8] == board[20]) || 
			(board[21] == board[20] && board[22] == board[20]) || 
			(board[14] == board[20] && board[17] == board[20])) 
			return true;
		else 
			return false; }
	case 21: {
		if ((board[20] == board[21] && board[22] == board[21]) || 
			(board[15] == board[21] && board[18] == board[21])) 
			return true;
		else 
			return false; }
	case 22: {
		if ((board[20] == board[22] && board[21] == board[22]) || 
			(board[16] == board[22] && board[19] == board[22]) || 
			(board[2] == board[22] && board[13] == board[22])) 
			return true;
		else 
			return false; }
	default:
		return false;
	}

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
