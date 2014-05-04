#include <iostream>
using namespace std;

void main() {
	int choice = 0;
	do {
		cout << "[1] Option 1" << endl;
		cout << "[2] Option 2" << endl;
		cout << "[3] Option 3" << endl;
		cout << "[4] Option 4" << endl;
		cout << "[5] Option 5" << endl;
		cout << "[0] Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			cout << "Process Option 1" << endl;
			break;
		case 2:
			cout << "Process Option 2" << endl;
			break;
		case 3:
			cout << "Process Option 3" << endl;
			break;
		case 4:
			cout << "Process Option 4" << endl;
			break;
		case 5:
			cout << "Process Option 5" << endl;
			break;
		default:
			cout << "Unknown Option" << endl;
		}
		cout << endl;
	} while (choice > 0);
	cout << "Done" << endl;
	getchar();
	getchar();
}