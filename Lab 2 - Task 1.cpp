#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream myFile;

	// Asks for file name
	string Filename;
	cout << "Input file to read: ";
	cin >> Filename;

	// opening text file
	myFile.open(Filename, ios::in);


	if (!myFile) {
		cout << "File couldn't be opened" << endl; //reports if could not open or identify file
	}
	else {
		int lines = 0;
		string content;
		cout << "File read successfully: " << endl; //Reports that the specified file was opened and read
		cout << "-------------------------------" << endl;
		while (myFile.is_open()){
			lines++;
			if (myFile.eof()){
				cout << "-------------------------------" << endl;
				cout << "Reached end of file" << endl; //Identifies the end of the file and exit the loop
				break;
			}
			else if (lines > 10){
				cout << "-------------------------------" << endl;
				cout << "10 lines read successfully, closing the file." << endl; //If read 10 lines succesfully, exit the loop.
				break;
			}
			getline(myFile, content);
			cout << content << endl;
		}
	}

	myFile.close();

	return 0;
};