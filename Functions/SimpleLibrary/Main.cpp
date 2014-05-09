#include "SimpleMenu.h"

void main() {
	int choice;
	do {
		choice = simpleMenu();
		cout << "Your Choice: " << choice << endl << endl;
	} while (choice != 0);
	cout << "Done";
	getch();
}
