#include <iostream>
#include <fstream>
#include <string>

#include "ReadFile.h"

using namespace std;

const string ERROR_MESSAGE_1 = "Parameters not entered correctley";

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << ERROR_MESSAGE_1 << endl;
		return -1;
	}

	string fileName = argv[1];

	ReadFile boardFile = ReadFile();
	const string boardContents = boardFile.readFile(fileName);

	return 0;
}