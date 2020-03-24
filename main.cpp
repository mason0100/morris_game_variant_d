#include <iostream>
#include <fstream>
#include <string>

#include "ReadFile.h"
#include "Game.h"

using namespace std;

const string ERROR_MESSAGE_1 = "Parameters not entered correctley";

int main(int argc, char* argv[]) {

	/*if (argc != 3) {
		cout << ERROR_MESSAGE_1 << endl;
		return -1;
	}*/

	//string fileName = argv[1];
	string fileName = "board1.txt";
	ReadFile boardFile = ReadFile();
	const string boardContents = boardFile.readFile(fileName);
	Game board = Game(boardContents);




	//need to write function to write ending result to second board.txt;
	return 0;
}