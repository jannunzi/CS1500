#include <iostream>		// for cout and cin
#include <conio.h>		// for getch()
#include <string>		// for string class
using namespace std;	// for cout and cin

string parseCsvRow ( string row, int commaOffset );

int main() {
	string csvRow = "12/23/2012 12:23:21,DEPOSIT,monthly mortgage,123.45,234.56";

	string date = parseCsvRow(csvRow, 0);
	string type = parseCsvRow(csvRow, 1);
	string description = parseCsvRow(csvRow, 2);
	float amount = atof(parseCsvRow(csvRow, 3).c_str());
	float balance = atof(parseCsvRow(csvRow, 4).c_str());

	cout << date << endl;
	cout << type << endl;
	cout << description << endl;
	cout << amount << endl;
	cout << balance << endl;

	getch();
}

string parseCsvRow ( string row, int commaOffset ) {
	int commaIndex = row.find(",",0);
	if ( commaIndex == -1 )
		return "";

	commaOffset++;
	row += ",";

	commaIndex = 0;
	int lastCommaIndex = 0;
	string data;
	for(int i = 0; i < commaOffset; i++ ) {
		lastCommaIndex = commaIndex;
		if(lastCommaIndex > 0) {
			lastCommaIndex++;
		}
		commaIndex = row.find(",",lastCommaIndex);
		if(commaIndex == -1)
			return "";
		data = row.substr(lastCommaIndex, commaIndex - lastCommaIndex);
	}
	return data;
}
