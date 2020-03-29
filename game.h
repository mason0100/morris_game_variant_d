#pragma once
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


class Game
{
public:

	
	//not sure if this wll be used or required to make program work
	//evaluate at end of node struct will be beneficial
	struct Node {
		int miniMaxEstimate;
		string  boardPosition;//string representing char array for the board
	};

	//When calling this prgram the doconstructor MUST be called
	//a the end of each class object instance to ensure the 
	//static positionCount int resets to zero

	//constructor
	Game();

	//deconstructor
	~Game();

	//functions
	int minimaxOpening(string boardPosition, bool whiteTurn, int depth);//case 0
	int minimaxGame(string boardPosition, bool whiteTurn, int depth);//case1 
	int ABOpening(string boardPosition, bool whiteTurn, int depth, int alpha, int beta);// case 3
	int ABGame(string boardPosition, bool whiteTurn, int depth, int alpha, int beta);//case 4



	//utility functions
	void printGlobalVars();

private:
	//string constanats
	const char EMPTY = 'x';
	const char WHITE = 'W';
	const char BLACK = 'B';

	//global position counter
	static int globalPositionCount;
	static int globalStaticEstimate; 
	static string globalBoardPosition;

	//helper funtions 
	vector<string> generateMoveOpenings(string boardPosition);
	vector<string> generateMoveOpeningsBlack(string boardPosition);
	vector<string> generateMovesMidgameEndgame(string boardPosition);
	vector<string> generateMovesMidgameEndgameBlack(string boardPosition);
	vector<string> generateAdd(string board);
	vector<string> generateHopping( string boardPosition);
	vector<string> generateMove(string boardPosition);
	vector<string> generateRemove(string boardPosition, vector<string> listOfBoardPositions);//be sure parameters are correct and rename vector<int> list
	vector<int> neighbors(int position);
	bool closeMill(int position, string boardPosition);

	string invertBoard(string boardPosition);

	int staticEstimationFunctionMidEnd(string boardPosition, vector<string> listOfBoardPositions);
	int staticEstimationFunctionOpening(string boardPosition);

	
};

