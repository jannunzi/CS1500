#include <iostream>
using namespace std;

int main() {

	const int QUIT = 0;
	const int OPTION_1 = 1;
	const int OPTION_2 = 2;
	const int OPTION_3 = 3;

	cout << "Do While Loops" << endl;
	
	int option = 0;

	do {
		cout << "[1] Option 1" << endl;
		cout << "[2] Option 2" << endl;
		cout << "[3] Option 3" << endl;
		cout << "[0] Quit" << endl;
		cin >> option;

		if (option == OPTION_1){
			cout << "Option 1" << endl;
		}
		else if (option == OPTION_2) {
			cout << "Option 2" << endl;
		}
		else if (option == OPTION_3) {
			cout << "Option 3" << endl;
		}
		else if (option == QUIT) {
			cout << "Good Bye" << endl;
		}
		else {
			cout << "Unknown Option" << endl;
		}
	} while (option != 0);

}