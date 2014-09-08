#include <iostream>
using namespace std;

int main() {
	cout << "Primitive Data Types" << endl;

	int x = 2;
	cout << "x = " << x << endl;
	x = 2;
	cout << "x = " << x << endl;

	const int c = 6;
	cout << "c = " << c << endl;

	int y = 5, z;

	z = x + y;

	cout << "z = " << z << endl;

	z = y / x;
	cout << "z = " << z << endl;

	float f = y / x;
	cout << "f = " << f << endl;

	f = y / 2.0;
	cout << "f = " << f << endl;

	f = (float) y / 2;
	cout << "f = " << f << endl;
}
