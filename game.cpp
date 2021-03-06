#include "Game.h"

Game::Game() {
	globalPositionCount = 0;
	globalStaticEstimate = 0;
	globalBoardPosition = "";	
}


//deconstructor
Game::~Game() {
	globalPositionCount = 0;
	globalStaticEstimate = 0;
	globalBoardPosition = "";	
}

int Game::minimaxOpening(string boardPosition, bool whiteTurn, int depth) {

	//this will be the variable to be returned
	int staticEstimate;

	if (depth == 0) {
		staticEstimate = staticEstimationFunctionOpening(boardPosition);
		return staticEstimate;
	}

	if (whiteTurn == true) {
		vector<string> listOfBoardPositions = generateMoveOpenings(boardPosition);
		//somtehing happens
		int min = INT_MIN;
		bool blackTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxOpening(tempBoardPosition, blackTurn, depth-1);
			if (value > min) {
				min = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;
				
			}
		}
	}
	else{//whiteTurn == false
		vector<string> listOfBoardPositions = generateMoveOpeningsBlack(boardPosition);
		//something happens
		int max = INT_MAX;
		bool whiteTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxOpening(tempBoardPosition, whiteTurn, depth - 1);
			if (value < max) {
				max = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;
				
			}
		}
	}
	return staticEstimate;
}


//minimax game 
int Game::minimaxGame(string boardPosition, bool whiteTurn, int depth) {
	//this will be the variable to be returned
	int staticEstimate;

	if (depth == 0) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		staticEstimate = staticEstimationFunctionMidEnd(boardPosition, listOfBoardPositions);
		return staticEstimate;
	}

	if (whiteTurn == true) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgame(boardPosition);
		//somtehing happens
		int min = INT_MIN;
		bool blackTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxGame(tempBoardPosition, blackTurn, depth - 1);
			if (value > min) {
				min = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		//something happens
		int max = INT_MAX;
		bool whiteTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxGame(tempBoardPosition, whiteTurn, depth - 1);
			if (value < max) {
				max = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	return staticEstimate;
}


//ABOpening
//must be primed with INT_MAX and INT_MIN
//alpha = -infinity
//beta = infinity 
int Game::ABOpening(string boardPosition, bool whiteTurn, int depth, int alpha, int beta) {
	//this will be the variable to be returned
	int staticEstimate;
	int tempAlpha = alpha;
	int tempBeta = beta;

	if (depth == 0) {
		staticEstimate = staticEstimationFunctionOpening(boardPosition);
		return staticEstimate;
	}
	
	if (whiteTurn == true) {
		vector<string> listOfBoardPositions = generateMoveOpenings(boardPosition);
		
		bool blackTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			
			//globalStaticEstimate = staticEstimate;
			int value = ABOpening(tempBoardPosition, blackTurn, depth - 1, tempAlpha, tempBeta);
			if (value > tempAlpha) {
				tempAlpha = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;
			}
			if (tempAlpha >= tempBeta) {
				break;
			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMoveOpeningsBlack(boardPosition);
		
		bool whiteTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			
			//globalStaticEstimate = staticEstimate;
			int value = ABOpening(tempBoardPosition, whiteTurn, depth - 1, tempAlpha, tempBeta);
			if (value < tempBeta) {
				tempBeta = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;
			}
			if (tempAlpha >= tempBeta) {
				break;
			}
		}
	}
	
	return staticEstimate;
}

//ABGame
int Game::ABGame(string boardPosition, bool whiteTurn, int depth, int alpha, int beta) {
	//this will be the variable to be returned
	int staticEstimate;
	int tempAlpha = alpha;
	int tempBeta = beta;

	if (depth == 0) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		staticEstimate = staticEstimationFunctionMidEnd(boardPosition, listOfBoardPositions);
		return staticEstimate;
	}

	if (whiteTurn == true) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgame(boardPosition);

		bool blackTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];

			//globalStaticEstimate = staticEstimate;
			int value = ABGame(tempBoardPosition, blackTurn, depth - 1, tempAlpha, tempBeta);
			if (value > tempAlpha) {
				tempAlpha = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;
			}
			if (tempAlpha >= tempBeta) {
				break;
			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);

		bool whiteTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];

			//globalStaticEstimate = staticEstimate;
			int value = ABGame(tempBoardPosition, whiteTurn, depth - 1, tempAlpha, tempBeta);
			if (value < tempBeta) {
				tempBeta = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;
			}
			if (tempAlpha >= tempBeta) {
				break;
			}
		}
	}

	return staticEstimate;
}

//minimax open black game
int Game::minimaxOpeningBlack(string boardPosition, bool blackTurn, int depth) {
	//this will be the variable to be returned
	int staticEstimate;

	if (depth == 0) {
		staticEstimate = staticEstimationFunctionOpening(boardPosition);
		return staticEstimate;
	}

	if (blackTurn == true) {
		vector<string> listOfBoardPositions = generateMoveOpeningsBlack(boardPosition);
		//somtehing happens
		int min = INT_MIN;
		bool whiteTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxOpeningBlack(tempBoardPosition, whiteTurn, depth - 1);
			if (value > min) {
				min = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMoveOpenings(boardPosition);
		//something happens
		int max = INT_MAX;
		bool blackTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxOpeningBlack(tempBoardPosition, blackTurn, depth - 1);
			if (value < max) {
				max = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	return staticEstimate;
}


//minimax black game
int Game::minimaxGameBlack(string boardPosition, bool blackTurn, int depth) {
	//this will be the variable to be returned
	int staticEstimate;

	if (depth == 0) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		staticEstimate = staticEstimationFunctionMidEnd(boardPosition, listOfBoardPositions);
		return staticEstimate;
	}

	if (blackTurn == true) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		//somtehing happens
		int min = INT_MIN;
		bool whiteTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxGameBlack(tempBoardPosition, whiteTurn, depth - 1);
			if (value > min) {
				min = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMovesMidgameEndgame(boardPosition);
		//something happens
		int max = INT_MAX;
		bool blackTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxGameBlack(tempBoardPosition, blackTurn, depth - 1);
			if (value < max) {
				max = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	return staticEstimate;
}


int Game::minimaxOpeningImproved(string boardPosition, bool whiteTurn, int depth) {

	//this will be the variable to be returned
	int staticEstimate;

	if (depth == 0) {
		staticEstimate = staticEstimationFunctionOpeningImproved(boardPosition);
		return staticEstimate;
	}

	if (whiteTurn == true) {
		vector<string> listOfBoardPositions = generateMoveOpenings(boardPosition);
		//somtehing happens
		int min = INT_MIN;
		bool blackTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxOpening(tempBoardPosition, blackTurn, depth - 1);
			if (value > min) {
				min = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMoveOpeningsBlack(boardPosition);
		//something happens
		int max = INT_MAX;
		bool whiteTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxOpening(tempBoardPosition, whiteTurn, depth - 1);
			if (value < max) {
				max = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	return staticEstimate;
}


//minimax game 
int Game::minimaxGameImproved(string boardPosition, bool whiteTurn, int depth) {
	//this will be the variable to be returned
	int staticEstimate;

	if (depth == 0) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		staticEstimate = staticEstimationFunctionMidEndImproved(boardPosition, listOfBoardPositions);
		return staticEstimate;
	}

	if (whiteTurn == true) {
		vector<string> listOfBoardPositions = generateMovesMidgameEndgame(boardPosition);
		//somtehing happens
		int min = INT_MIN;
		bool blackTurn = false;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxGame(tempBoardPosition, blackTurn, depth - 1);
			if (value > min) {
				min = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	else {//whiteTurn == false
		vector<string> listOfBoardPositions = generateMovesMidgameEndgameBlack(boardPosition);
		//something happens
		int max = INT_MAX;
		bool whiteTurn = true;

		for (int boardPosition = 0; boardPosition < listOfBoardPositions.size(); boardPosition++) {
			string tempBoardPosition = listOfBoardPositions[boardPosition];
			//globalStaticEstimate = staticEstimate;
			int value = minimaxGame(tempBoardPosition, whiteTurn, depth - 1);
			if (value < max) {
				max = value;
				staticEstimate = value;

				//gobal assignments
				globalPositionCount++;
				globalBoardPosition = tempBoardPosition;
				globalStaticEstimate = staticEstimate;

			}
		}
	}
	return staticEstimate;
}


//generate opening moves
vector<string> Game::generateMoveOpenings(string boardPosition) {
	vector<string> listOfBoardPositions;
	listOfBoardPositions = generateAdd(boardPosition);
	return listOfBoardPositions;
}


//generate black mover openings
vector<string> Game::generateMoveOpeningsBlack(string boardPosition) {
	string tempBoardPosition = boardPosition;
	//inverts board to evaluate black turn
	string blackBoardPosition = invertBoard(tempBoardPosition);

	vector<string> listofBoardPosistions = generateAdd(blackBoardPosition);

	//inverts all boardPositions in listOfBoardPositions
	for (int i = 0; i < listofBoardPosistions.size(); i++) {
		string tempBlackBoardPosition = listofBoardPosistions[i];
		listofBoardPosistions[i] = invertBoard(tempBlackBoardPosition);
	}
	return listofBoardPosistions;
}


//generate mid and end game moves
vector<string> Game::generateMovesMidgameEndgame(string boardPosition) {
	vector<string> listOfBoardPositions;
	int whitePieceCount = 0; 

	for (int position = 0; position < boardPosition.size(); position++) {
		if (boardPosition[position] == WHITE) {
			whitePieceCount++;
		}
	}

	if (whitePieceCount == 3) {
		listOfBoardPositions = generateHopping(boardPosition);
	}
	else {
		listOfBoardPositions = generateMove(boardPosition);
	}

	return listOfBoardPositions;
}


//
vector<string> Game::generateMovesMidgameEndgameBlack(string boardPosition) {
	vector<string> listOfBoardPositions;
	string tempBoardPositions = invertBoard(boardPosition);
	listOfBoardPositions = generateMovesMidgameEndgame(tempBoardPositions);
	
	for (int i = 0; i < listOfBoardPositions.size(); i++) {
		string tempBlackBoardPosition = listOfBoardPositions[i];
		listOfBoardPositions[i] = invertBoard(tempBlackBoardPosition);
	}

	return listOfBoardPositions;
}


//generate add
vector<string> Game::generateAdd(string boardPosition) {
	vector<string> listOfBoardPositions;

	for (int position = 0; position < boardPosition.size(); position++) {
		if (boardPosition[position] == EMPTY) {
			string tempBoardPositionB = boardPosition;
			tempBoardPositionB[position] = WHITE; 

			if (closeMill(position, tempBoardPositionB)) {
				listOfBoardPositions = generateRemove(tempBoardPositionB, listOfBoardPositions);
			}
			else {
				listOfBoardPositions.push_back(tempBoardPositionB);
			}
		}
	}
	return listOfBoardPositions;
}


//generate hopping
vector<string> Game::generateHopping(string boardPosition) {
	vector<string> listOfBoardPositions; 

	for (int alpha = 0; alpha < boardPosition.size(); alpha++) {
		if (boardPosition[alpha] == WHITE) {
			for (int beta = 0; beta < boardPosition.size(); beta++) {
				if (boardPosition[beta] == EMPTY) {
					
					string tempBoardPositionB = boardPosition;
					tempBoardPositionB[alpha] = EMPTY;
					tempBoardPositionB[beta] = WHITE;

					if (closeMill(beta, tempBoardPositionB)) {
						listOfBoardPositions = generateRemove(tempBoardPositionB, listOfBoardPositions);
					}
					else {
						listOfBoardPositions.push_back(tempBoardPositionB);
					}
				}
			}
		}
	}
	return listOfBoardPositions;
}


//generates the moves for pieces
vector<string> Game::generateMove(string boardPosition) {

	vector<string> listOfBoardPositions;

	for (int i = 0; i < boardPosition.size(); i++) {
		if (boardPosition[i] == WHITE) {
			vector<int> tempNeighbors = neighbors(i);
			//for every neighbor
			for (int j = 0; j < tempNeighbors.size(); j++) {
				int neighborPosition = tempNeighbors[j];
				if (boardPosition[neighborPosition] == EMPTY) {
					
					string tempBoardPositionB = boardPosition;
					tempBoardPositionB[i] = EMPTY;
					tempBoardPositionB[neighborPosition] = WHITE;

					if (closeMill(neighborPosition, tempBoardPositionB)) {
						listOfBoardPositions = generateRemove(tempBoardPositionB, listOfBoardPositions);
					}
					else {
						listOfBoardPositions.push_back(tempBoardPositionB);
					}
				}
			}

		}
	}

	return listOfBoardPositions;
}


//removes piece from board
//this needs to be corrected suedo code is needs reevaluatings
vector<string> Game::generateRemove(string board, vector<string> listOfBoardPositions) {
	for (int position = 0; position < board.size(); position++) {
		if (board[position] == BLACK) {
			if (closeMill(position, board) == false) {
				string tempBoard = board;
				tempBoard[position] = EMPTY;
				listOfBoardPositions.push_back(tempBoard);
			}
		}
	}
	//if no black pieces were added(all blaack pieces are in mills) add b to L
	return listOfBoardPositions;
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


//inverts boardPositions to evaluate black 
string Game::invertBoard(string boardPosition) {
	string tempBoardPosition = boardPosition;
	for (int i = 0; i < tempBoardPosition.size(); i++) {
		if (tempBoardPosition[i] == WHITE)
			tempBoardPosition[i] = BLACK;
		else if (tempBoardPosition[i] == BLACK)
			tempBoardPosition[i] = WHITE;
	}
	return tempBoardPosition;
}


//static estimation
int Game::staticEstimationFunctionMidEnd(string boardPosition, vector<string> listOfBoardPositions) {
	int whitePieces = 0;
	int blackPieces = 0;
	int numBlackMoves = listOfBoardPositions.size();

	for (int i = 0; i < boardPosition.size(); i++) {
		if (boardPosition[i] == WHITE) {
			whitePieces++;
		}
	}

	for (int j = 0; j < boardPosition.size(); j++) {
		if (boardPosition[j] == BLACK) {
			blackPieces++;
		}
	}

	if (blackPieces <= 2) {
		return 10000;
	}
	else if (whitePieces <= 2) {
		return -10000;
	}
	else if (numBlackMoves == 0) {
		return 10000;
	}
	else {
		return (1000 * (whitePieces - blackPieces) - numBlackMoves);
	}
}

//static estimation 
int Game::staticEstimationFunctionOpening(string boardPosition) {

	int whitePieces = 0;
	int blackPieces = 0;
	int whiteMinusBlack = 0;

	for (int i = 0; i < boardPosition.size(); i++) {
		if (boardPosition[i] == WHITE) {
			whitePieces++;
		}
	}

	for (int j = 0; j < boardPosition.size(); j++) {
		if (boardPosition[j] == BLACK) {
			blackPieces++;
		}
	}
	whiteMinusBlack = whitePieces - blackPieces;
	return whiteMinusBlack;
}

//impoved static estimation
int Game::staticEstimationFunctionMidEndImproved(string boardPosition, vector<string> listOfBoardPositions) {
	int whitePieces = 0;
	int blackPieces = 0;
	int numBlackMoves = listOfBoardPositions.size();
	int whiteMinusBlack = 0;
	int staticEstimate = 0;
	int mills = 0;

	for (int i = 0; i < boardPosition.size(); i++) {
		if (boardPosition[i] == WHITE) {
			whitePieces++;
		}
	}

	for (int j = 0; j < boardPosition.size(); j++) {
		if (boardPosition[j] == BLACK) {
			blackPieces++;
		}
	}

	for (int k = 0; k < boardPosition.size(); k++) {
		if (boardPosition[k] == EMPTY) {
			if (closeMill(k, boardPosition) == true) {
				mills++;
			}
		}
	}
	whiteMinusBlack = whitePieces - blackPieces;
	staticEstimate = mills + whiteMinusBlack;

	if (blackPieces <= 2) {
		return 10000;
	}
	else if (whitePieces <= 2) {
		return -10000;
	}
	else if (numBlackMoves == 0) {
		return 10000;
	}
	else {
		return (1000 * (staticEstimate) - numBlackMoves);
	}
}


//improved static estimation
int Game::staticEstimationFunctionOpeningImproved(string boardPosition) {
	int whitePieces = 0;
	int blackPieces = 0;
	int whiteMinusBlack = 0;
	int staticEstimate = 0;
	int mills = 0;

	for (int i = 0; i < boardPosition.size(); i++) {
		if (boardPosition[i] == WHITE) {
			whitePieces++;
		}
	}

	for (int j = 0; j < boardPosition.size(); j++) {
		if (boardPosition[j] == BLACK) {
			blackPieces++;
		}
	}

	for (int k = 0; k < boardPosition.size(); k++) {
		if (boardPosition[k] == EMPTY) {
			if (closeMill(k, boardPosition) == true) {
				mills++;
			}
		}
	}
	whiteMinusBlack = whitePieces - blackPieces;
	staticEstimate = mills + whiteMinusBlack;
	return staticEstimate;
}


//Uitilty functions
void Game::printGlobalVars(string boardPosition) {
	cout << "Board Position: " << boardPosition << endl;
	cout << "Positions evaluated by static evaluation: " << globalPositionCount << endl;
	cout << "Minimax Estimate: " << globalStaticEstimate << endl;
}