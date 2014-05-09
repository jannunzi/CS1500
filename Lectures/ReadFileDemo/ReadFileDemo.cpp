#include <ctime>
#include <time.h>	// for time(0)
#include <iostream>	// for cout, cin, endl
#include <fstream>	// for ofstream, ifstream
#include <conio.h>	// for getch()
#include <string>	// for string class
using namespace std;

string getCurrentDateAndTime();

int main() {
	/*
	 *	Reading a Hello World File
	 */
	cout	<< endl << "Reading a Hello World File" << endl;

	// creating a simple file
	ofstream helloWorldOutputFile;
	helloWorldOutputFile.open("HelloWorld.txt");
	helloWorldOutputFile << "Hello World" << endl;
	helloWorldOutputFile.close();
	cout << "Created File HelloWorld.txt" << endl;
	getch();

	// reading from a simple file
	ifstream helloWorldInputFile;
	helloWorldInputFile.open("HelloWorld.txt");
	string hello;
	getline(helloWorldInputFile, hello);
	cout << hello;
	getch();
//	return 0;

	/*
	 *	Reading a File Line by Line
	 */
	cout	<< endl << "Reading a File Line by Line" << endl;

	// creating a simple file
	ofstream multiLineOutputFile;
	multiLineOutputFile.open("MultiLine.txt");
	for(int i=0; i<10; i++)
		multiLineOutputFile << "Line " << i << " Data" << endl;
	multiLineOutputFile.close();
	cout << "Created File MultiLine.txt" << endl;
	getch();

	// reading from a simple file
	cout << "Reading File MultiLine.txt Line by Line" << endl;
	ifstream multiLineInputFile;
	multiLineInputFile.open("MultiLine.txt");
	string singleLine;
	while(multiLineInputFile.good()) {
		getline(multiLineInputFile, singleLine);
		cout << singleLine << endl;
	}
	getch();
	return 0;
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