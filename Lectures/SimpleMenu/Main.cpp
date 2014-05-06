#include <iostream>
#include <conio.h>
using namespace std;

int main() {
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

		if (selection == 1)
			yellowCount = yellowCount + 1;
		else if (selection == 2)
			blueCount = blueCount + 1;
		else if (selection == 3)
			redCount++;
		else if (selection == 0)
			;
		else
			cout << "Invalid Option" << endl;

	} while (selection != 0);

	cout << endl;
	cout << "Yellow: " << yellowCount << endl;
	cout << "Blue: " << blueCount << endl;
	cout << "Red: " << redCount << endl << endl;

	getch();
}
