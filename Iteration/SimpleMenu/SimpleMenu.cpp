#include <iostream>
using namespace std;

void main() {
	int option;
	do {
		cout << "[1] Option 1" << endl;
		cout << "[2] Option 2" << endl;
		cout << "[3] Option 3" << endl;
		cout << "[4] Option 4" << endl;
		cout << "[5] Option 5" << endl;
		cout << "[0] Quit" << endl;
		cout << "Choose: ";
		cin >> option;
		cout << "Your choice: " << option;
		cout << endl << endl;
	} while (option >= 1);
	cout << "Done" << endl;
	getchar();
	getchar();
}
