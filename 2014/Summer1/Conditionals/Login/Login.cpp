#include <iostream>
#include <string>
using namespace std;

void main() {
	string username;
	string password;
	do {
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
	} while (username != "admin" || password != "admin");
	cout << "Welcome !" << endl;
	getchar();
	getchar();
}
