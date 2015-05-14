#include <iostream>	// for cout, cin, endl
#include <conio.h>	// for getch()
using namespace std;

int main() {
	/*
	 *	Simple While Loop
	 */
	cout << endl << "Simple While Loop" << endl;
	int count = 1;
	while ( count <= 10 ) {
		count++;
		cout << count << endl;
	}
	getch();

	/*
	 *	Validating Input
	 */
	cout << endl << "Validating Input" << endl;
	cout << "Please Enter a Number Between 1 and 10" << endl;
	int number;
	cin >> number;
	while ( number < 1 || number > 10 ) {
		cout << "Invalid input, please try again: ";
		cin >> number;
	}
	cout << "Very good, thanks." << endl;
	getch();

	/*
	 *	Simple While Loop Menu
	 */
	cout << endl << "Simple Menu" << endl;
	const int CHOICE_1 = 1;
	const int CHOICE_2 = 2;
	const int QUIT = 3;
	int choice;
	cout << "Please choose one of the following choices:" << endl;
	cout << "[1] Choice 1" << endl;
	cout << "[2] Choice 2" << endl;
	cout << "[3] Quit" << endl;
	cin >> choice;
	while ( choice != QUIT ) {
		switch ( choice ) {
			case CHOICE_1 :
				cout << endl << "Do Choice 1 Stuff" << endl << endl;
				break;
			case CHOICE_2 :
				cout << endl << "Do Choice 2 Stuff" << endl << endl;
				break;
		}
		cout << "[1] Choice 1" << endl;
		cout << "[2] Choice 2" << endl;
		cout << "[3] Quit" << endl;
		cin >> choice;
	}
	cout << "Done" << endl;
	getch();

	/*
	 *	Do While Loop Menu
	 */
	cout << endl << "Do While Loop Menu" << endl;
	do {
		cout << "[1] Choice 1" << endl;
		cout << "[2] Choice 2" << endl;
		cout << "[3] Quit" << endl;
		cin >> choice;
		switch ( choice ) {
			case CHOICE_1 :
				cout << endl << "Do Choice 1 Stuff" << endl << endl;
				break;
			case CHOICE_2 :
				cout << endl << "Do Choice 2 Stuff" << endl << endl;
				break;
		}
	} while ( choice != QUIT );
	cout << "Done" << endl;
	getch();

	/*
	 *	Simple For Loop
	 */
	cout << endl << "Simple For Loop" << endl;
	for ( int i = 0; i <= 10; i++ )
		cout << i << endl;
	getch();

	/*
	 *	Reverse For Loop
	 */
	cout << endl << "Reverse For Loop" << endl;
	for ( int i = 10; i >= 0; i-- )
		cout << i << endl;
	getch();

	/*
	 *	Counting by 10s
	 */
	cout << endl << "Counting by 10s" << endl;
	for ( int i = 0; i <= 100; i += 10 )
		cout << i << endl;
	getch();

	/*
	 *	Breaking From a Loop
	 */
	cout << endl << "Breaking From a Loop" << endl;
	for ( int i = 0; i <= 10; i++ ) {
		if(i == 5)
			break;
		cout << i << endl;
	}
	getch();

	/*
	 *	Skipping An Iteration
	 */
	cout << endl << "Skipping An Iteration" << endl;
	for ( int i = 0; i <= 10; i++ ) {
		if(i == 5)
			continue;
		cout << i << endl;
	}
	getch();
}
