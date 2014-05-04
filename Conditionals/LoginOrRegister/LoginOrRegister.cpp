#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void main() {

	int choice;
	bool loggedIn = false;
	string username;
	string password;
	string password1;
	string password2;
	do {
		cout << "[1] Login" << endl;
		cout << "[2] Register" << endl;
		cout << "[0] Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Username: ";
			cin  >> username;
			cout << "Password: ";
			cin  >> password;
			if (username != "admin" || password != "admin") {
				cout << "Username or password is invalid. Try again." << endl;
			}
			else {
				loggedIn = true;
			}
		case 2:
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password1;
			cout << "Verify Password: ";
			cin >> password2;
			if (password1 != password2) {
				cout << "Passwords must match" << endl;
			}
		}
	} while (choice != 0 && loggedIn == false);
	cout << "Welcome admin";
	getch();
}