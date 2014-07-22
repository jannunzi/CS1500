#include <iostream>
using namespace std;

void incrementIntegerByReference(int &x) {
	x++;
}

void incrementIntegerByReference(int * x) {
	(*x)++;
}

void incrementInteger(int x) {
	cout << "x = " << x << endl;
	x++;
	cout << "x = " << x << endl;
}

void incrementIntegerByPointerReference(int * x) {
	(*x)++;
}

int main() {
	float f = 123.321;
	incrementInteger(f); // inplicit cast
	int a, x = 23, y;
	a = 10;
	cout << "a = " << a << endl;
	incrementInteger(a);
	cout << "a = " << a << endl;
	incrementIntegerByReference(a);
	cout << "a = " << a << endl;
	incrementIntegerByReference(&a);
	cout << "a = " << a << endl;

	int* b = &a;
	cout << "b = " << b << endl;
	cout << "*b = " << *b << endl;
	(*b)++;
	cout << "b = " << b << endl;
	cout << "a = " << a << endl;

	incrementInteger((int)b); // explicit cast

	cout << "a = " << a << endl;
	incrementIntegerByPointerReference(b);
	cout << "a = " << a << endl;
	incrementIntegerByPointerReference(&a);
	cout << "a = " << a << endl;

	int * c = &a;
	incrementIntegerByPointerReference(c);
	cout << "a = " << a << endl;
	(*c)++;
	cout << "a = " << a << endl;

	cout << "c = " << c << endl;
	cout << "b = " << b << endl;
	cout << "&c = " << &c << endl;
	cout << "&b = " << &b << endl;

	cout << "x = " << x << endl;
	b = &x;
	*b = 34;
	cout << "x = " << x << endl;
	
//	cin >> x;
//	for (int i = 0; i < x; i++)

	b = new int;
	*b = 234;
	cout << b << endl;
	cout << *b << endl;
	delete b;

//	c = b;

	b = new int;
	*b = 456;
	cout << b << endl;
	cout << *b << endl;

	cout << c << endl;
	cout << *c << endl;
}
