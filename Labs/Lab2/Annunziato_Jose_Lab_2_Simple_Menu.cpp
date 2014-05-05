#include <iostream>
#include <conio.h>
using namespace std;

void main() {
	int choice = 0;
	do {
		cout << "[1] Create an Application" << endl;
		cout << "[2] List all Applications" << endl;
		cout << "[3] Find Applications" << endl;
		cout << "[4] Create a Page" << endl;
		cout << "[5] List all Pages" << endl;
		cout << "[6] Find Pages" << endl;
		cout << "[0] Quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Create an Application" << endl;
			break;
		case 2:
			cout << "List all Applications" << endl;
			break;
		case 3:
			cout << "Find Applications" << endl;
			break;
		case 4:
			cout << "Create a Page" << endl;
			break;
		case 5:
			cout << "List all Pages" << endl;
			break;
		case 6:
			cout << "Find Pages" << endl;
			break;
		default:
			break;
		}
		if (choice == 0)
			break;
	} while (true);
}
