#include <iostream>
#include <conio.h>
using namespace std;

void passByReference(int &reference) {
	reference++;
}

void passByValue(int value) {
	value++;
}

void main() {
	int x = 1;
	int y = 1;

	passByValue(x);
	cout << x << endl;

	passByReference(y);
	cout << y << endl;

	getch();
}