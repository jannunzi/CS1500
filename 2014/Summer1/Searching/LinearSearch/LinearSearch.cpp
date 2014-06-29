#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int searchByAppName(string, string[], int);
void displayApp(int, string[], int[]);

void main() {
	string appNames[] = {
		"Pages", "Keynote", "Numbers",
		"Word", "PowerPoint", "Excel"
	};
	int appPrices[] = {
		12, 23, 34, 45, 34, 45
	};
	int index = searchByAppName("PowerPoint", appNames, 6);
	displayApp(index, appNames, appPrices);
	getch();
}

int searchByAppName(
	string name,
	string appNames[],
	int size) {
	for (int i = 0; i < size; i++) {
		if (appNames[i] == name)
			return i;
	}
	return -1;
}

void displayApp(int index, string names[], int prices[]) {
	cout << names[index] << " $" << prices[index] << endl;
}
