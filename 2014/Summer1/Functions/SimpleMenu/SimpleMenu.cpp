#include <iostream>
#include <conio.h>
using namespace std;

int simpleMenu() {
	int option = 0;
	cout << "Menu" << endl;
	cout << "[1] Option 1" << endl;
	cout << "[2] Option 2" << endl;
	cout << "[3] Option 3" << endl;
	cout << "[0] Quit" << endl;
	cin >> option;
	return option;
}

void main() {
	int choice;
	do {
		choice = simpleMenu();
		cout << "Your Choice: " << choice << endl << endl;
	} while (choice != 0);
	cout << "Done";
	getch();
}
