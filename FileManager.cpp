#include "FileManager.h"

FileManager::FileManager() {

}


//Reads file and converts the contents of the file to a string
string FileManager::readFile(string FileName) {


	//creates file object
	fstream myFile;

	//opens file
	myFile.open(FileName);

	if (myFile.is_open() == false) {
		cout << ERROR_MESSAGE_2 << endl;
		exit(EXIT_FAILURE);
	}


	int lineNumber = -1;
	string boardContents;

	//This while statement reads a .txt file line by line
	while (getline(myFile, boardContents)) {
			
		//if lineNumber increments the program ends with a failure
		lineNumber++;
		if (lineNumber > 0){
			cerr << ERROR_MESSAGE_1<< endl;
			exit(EXIT_FAILURE);
		}
	}

	//if the boardContent.size is NOT 23 the program ends with a failure
	if (boardContents.size() != boardNodeCount) {
		cerr << ERROR_MESSAGE_3 << endl;
		exit(EXIT_FAILURE);
	}

	//this returns the string to be used as  the board array
	return boardContents;
}





