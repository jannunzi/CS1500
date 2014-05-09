#include <ctime>	// for time(0)
#include <iostream>	// for cout, cin, endl
#include <fstream>	// for ofstream, ifstream
#include <conio.h>	// for getch()
#include <string>	// for string class
#include <stdio.h>
using namespace std;

string getCurrentDateAndTime();

int main() {
	/*
	 *	Writing a Hello World File
	 */
	cout	<< endl << "Writing a Hello World File" << endl;
	ofstream helloWorldFile;
	helloWorldFile.open("HelloWorld.txt");
	helloWorldFile << "Hello World" << endl;
	helloWorldFile.close();
	getch();
//	return 0;

	/*
	 *	Appending to an Existing File
	 */
	cout	<< endl << "Appending to an Existing File" << endl;
	ofstream appendFile;
	appendFile.open("HelloWorld.txt", ios::out | ios::app);
	appendFile << "Current Time Is: ";
	appendFile << time(0) << endl;
	appendFile.close();
	getch();
//	return 0;

	/*
	 *	Renaming a File
	 */
	cout	<< endl << "Renaming a File" << endl;
	// create the file
	string renameMeFileName = "RenameMe.txt";
	ofstream renameMeFile;
	renameMeFile.open(renameMeFileName);
	// write to the file
	renameMeFile << "I'm being renamed" << endl;
	renameMeFile.close();
	getch();
	// Renaming the file
	string newFileName = "NewName.txt";
	if (rename(renameMeFileName.c_str(), newFileName.c_str()) != 0)
		cout << "Unable to rename" << endl;
	else
		cout << "Successfully renamed" << endl;
	getch();
//	return 0;

	/*
	 *	Removing a File
	 */
	cout	<< endl << "Removing a File" << endl;
	// create the file
	string removeMeFileName = "RemoveMe.txt";
	ofstream removeMeFile;
	removeMeFile.open(removeMeFileName);
	removeMeFile << "Goodbye World" << endl;
	removeMeFile.close();
	getch();
	// Removing the file
	if( remove( removeMeFileName.c_str() ) != 0 )
		cout << "Unable to remove" << endl;
	else
		cout << "Successfully removed" << endl;
	getch();
//	return 0;
	
	/*
	 *	Writing Several Lines to a File
	 */
	cout	<< endl << "Writing Several Lines to a File" << endl;
	ofstream manyLinesFile;
	manyLinesFile.open("ManyLinesFile.txt", ios::out | ios::app);
	string inputLine = "";
	do {
		manyLinesFile << inputLine << endl;
		getline(cin, inputLine);
	} while ( inputLine != "done" );
	getch();
//	return 0;

	/*
	 *	Getting Current Date and Time
	 */
	cout << "Getting Current Date and Time" << endl;
	cout << getCurrentDateAndTime();
	getch();
//	return 0;

	/*
	 *	Creating a CSV File
	 */
	cout	<< endl << "Creating a CSV File" << endl;
	string	fileName;
	cout	<< "File Name: ";
	cin		>> fileName;
	fileName += ".csv";
	cout	<< "Creating file: " << fileName << endl;
	ofstream outputFile;
	outputFile.open(fileName, ios::out | ios::app);

	outputFile << getCurrentDateAndTime() << ",Deposit,123.45,234.56" << endl;
	outputFile << getCurrentDateAndTime() << ",Withdraw,22.33,333.44" << endl;
	outputFile.close();
	getch();
//	return 0;
}

/*
 *	Getting Current Date & Time
 */
string getCurrentDateAndTime() {
	time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime (buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
	return buffer;
}