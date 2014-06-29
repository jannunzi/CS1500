#include <iostream>
#include <conio.h>
using namespace std;

void main() {
	cout << "counting" << endl;
	int i;
	for (i = 0; i < 10; i++) {
		cout << i << endl;
	}
	getch();

	cout << "declaring variable in for statement" << endl;
	for (int j = 0; j < 20; j++) {
		cout << j << endl;
	}
	getch();

	cout << "different starting point" << endl;
	for (int j = 12; j < 20; j++){
		cout << j << endl;
	}
	getch();

	cout << "counting to sentinel inclusive" << endl;
	for (int i = 12; i <= 20; i++) {
		cout << i << endl;
	}
	getch();

	cout << "what are the values of variable after loop ends?" << endl;
	cout << i << endl;
	getch();

	cout << "counting backwards" << endl;
	for (int i = 10; i > 0; i--) {
		cout << i << endl;
	}
	getch();

	cout << "counting by 10s" << endl;
	for (int i = 0; i <= 100; i += 10){
		cout << i << endl;
	}
	getch();
}