#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void addApplication(string applicationName) {
	ofstream fileHandle;
	fileHandle.open("applications.txt", ios::out | ios::app);
	fileHandle << applicationName << endl;
	fileHandle.close();
}

void listApplications() {
	ifstream fileHandle;
	fileHandle.open("applications.txt");
	string line;
	while (fileHandle.good()) {
		getline(fileHandle, line);
		cout << line << endl;
	}
}

void removeApplication(string appName) {
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("applications.txt");
	outputFile.open("temp.txt");
	string line;
	while (inputFile.good()) {
		getline(inputFile, line);
		if (line == appName)
			continue;
		outputFile << line << endl;
	}
	inputFile.close();
	outputFile.close();
	remove("applications.txt");
	rename("temp.txt", "applications.txt");
}

int main() {
	addApplication("App 3");
	listApplications();
	removeApplication("App1");
}
