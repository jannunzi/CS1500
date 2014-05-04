#include <iostream>	// for cout, cin, endl
#include <string>	// for string datatype
#include <conio.h>	// for getch()
using namespace std;// for std::

void main() {
	string username;
	string password1;
	string password2;
	string choice;

	cout << "Username: ";
	cin >> username;

	do {
		cout << "Password: ";
		cin >> password1;
		cout << "Verify password: ";
		cin >> password2;
		if (password1 != password2) {
			cout << "Passwords must match." << endl;
		}
	} while (password1 != password2);
	cout << "Registration complete" << endl;
	getch();
}
