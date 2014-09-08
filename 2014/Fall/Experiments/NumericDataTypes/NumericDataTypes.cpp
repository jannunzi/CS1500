#include <iostream>
using namespace std;

int main() {
	cout << "Integer Variables" << endl;
	int x;
	x = 3;
	int y = 5;
	int z = x + y;
	cout << "x = " << x << endl;
	cout << "z = x + y = " << z << endl;

	cout << "\nInteger Division" << endl;
	int a, b, c;
	a = 12;
	b = 3;

	c = a / b;
	cout << "c = " << c << endl;

	c = a / 5;
	cout << "c = " << c << endl;

	cout << "\nFloating Point Division" << endl;
	float f;

	f = a / 5;
	cout << "f = " << f << endl;

	f = a / 5.0;
	cout << "f = " << f << endl;

	f = (float) a / 5;
	cout << "f = " << f << endl;

	f = a / b;
	cout << "f = " << f << endl;

	f = a / 3.0;
	cout << "f = " << f << endl;

	cout << "\nDouble Precision Division" << endl;
	double d;

	d = a / b;
	cout << "d = " << d << endl;

	d = a / 5;
	cout << "d = " << d << endl;

	d = a / 5.0;
	cout << "d = " << d << endl;

	d = (double) a / 5;
	cout << "d = " << d << endl;


}
