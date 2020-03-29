#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileManager
{

public:

	//Error message strings
	const string ERROR_MESSAGE_1 = "The file is not formatted correctly. \n The file  should only be one line and contain no spaces";
	const string ERROR_MESSAGE_2 = "File did not open correctly, check file name.";
	const string ERROR_MESSAGE_3 = "The board array must be exactly 23 characters.";

	//constant variables
	const int boardNodeCount = 23;
	
	//constructors
	FileManager();

	//functions 
	//returns a string to be used for the boardContents array for the rest of the program 
	string readFile(string tempFileName);
	

};


