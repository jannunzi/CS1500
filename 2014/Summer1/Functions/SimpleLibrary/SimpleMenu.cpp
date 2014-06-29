#include "SimpleMenu.h"

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
