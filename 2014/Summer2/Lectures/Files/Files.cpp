#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void appendToFile() {
	ofstream outFile;
	outFile.open("test.txt", ios::out | ios::app);

	outFile << "Hello Again" << endl;

	outFile.close();
}

void testFile() {
	ofstream outFile;
	outFile.open("test.txt");
	outFile << "Hello World!" << endl;
	outFile << "Goodbye World!" << endl;
	outFile.close();
}

void createApplication(string appName) {
	ofstream appDb;
	appDb.open("applications.txt", ios::out | ios::app);

	appDb << appName << endl;

	appDb.close();

}

void listApplications() {
	ifstream appDb;
	appDb.open("applications.txt");
	string line;
	while (appDb.good()) {
		getline(appDb, line);
		cout << line << endl;
	}
	appDb.close();
}

void copyApplication(string copyFileName) {
	ifstream appDb;
	ofstream temp;
	appDb.open("applications.txt");
	temp.open(copyFileName);
	string line;
	while (appDb.good()) {
		getline(appDb, line);
		temp << line << endl;
	}
	appDb.close();
}

void removeApplication(string appName) {
	ifstream appDb;
	ofstream temp;
	appDb.open("applications.txt");
	temp.open("temp.txt");
	string line;
	while (appDb.good()) {
		getline(appDb, line);
		if (appName == line)
			continue;
		cout << line << endl;
		temp << line << endl;
	}
	temp.close();
	appDb.close();
	remove("applications.txt");
	rename("temp.txt", "applications.txt");
}

int main() {
//	testFile();
//	appendToFile();
//	createApplication("To Do");
//	createApplication("Contact List");
//	createApplication("Calculator");
//	listApplications();
//	copyApplication("copyOfApplications.txt");
	removeApplication("Contact List");
}
