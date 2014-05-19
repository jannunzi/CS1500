#include <iostream>
using namespace std;

void tryIncrement(int x) {
	x++;
}

void incrementByReference(int &x) {
	x++;
}

void incrementByPointer(int *x) {
	cout << x << endl;
	cout << *x << endl;
	cout << (*x)+1 << endl;
	*x = (*x) + 1;
	//	(*x)++;
}

int main() {

	char *c = new char;
	*c = 'A';

	cout << *c << endl;
	(*c)++;
	cout << *c << endl;

	int x = 5;
	cout << x << endl;
	tryIncrement(x);
	cout << x << endl;

	incrementByReference(x);
	cout << x << endl;

	cout << &x << endl;
	incrementByPointer(&x);
	cout << x << endl;

	getchar();
}