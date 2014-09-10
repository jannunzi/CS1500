#include <iostream>
using namespace std;

int main() {

	const int QUIT = 0;
	const int OPTION_1 = 1;
	const int OPTION_2 = 2;
	const int OPTION_3 = 3;

	cout << "Switch Case" << endl;

	int option = 0;

	do {
		cout << "[1] Option 1" << endl;
		cout << "[2] Option 2" << endl;
		cout << "[3] Option 3" << endl;
		cout << "[0] Quit" << endl;
		cin >> option;

		switch (option) {
		case OPTION_1:
			cout << "Option 1" << endl;
			break;
		case OPTION_2:
			cout << "Option 2" << endl;
			break;
		case OPTION_3:
			cout << "Option 3" << endl;
			break;
		case QUIT:
			cout << "Good Bye" << endl;
			break;
		default:
			cout << "Unknown Option" << endl;
			break;
		}

	} while (option != 0);

}