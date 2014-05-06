#include <iostream>
#include <conio.h>
using namespace std;

int main() {

	const int YELLOW_SELECTED = 1;
	const int BLUE_SELECTED = 2;
	const int RED_SELECTED = 3;

	int selection;
	int yellowCount = 0;
	int blueCount = 0;
	int redCount = 0;

	do {
		cout << "What is your favorite color?" << endl;
		cout << "[1] Yellow" << endl;
		cout << "[2] Blue" << endl;
		cout << "[3] Red" << endl;
		cout << "[0] Quit" << endl;

		cin >> selection;

		switch (selection) {
		case 0:
			break;
		case YELLOW_SELECTED:
			yellowCount++;
			break;
		case BLUE_SELECTED:
			blueCount++;
			break;
		case RED_SELECTED:
			redCount++;
			break;
		default:
			cout << "Invalid Option" << endl;
			break;
		}

	} while (selection != 0);

	cout << endl;
	cout << "Yellow: " << yellowCount << endl;
	cout << "Blue: " << blueCount << endl;
	cout << "Red: " << redCount << endl << endl;

	getch();
}
