#include <iostream>
#include <string>
using namespace std;

int main() {
	int i, j;
	char c;
	float f;
	double d;
	string s;

	cout << "i = ";
	cin >> i;
	cout << i << endl;

	cout << "i and j = ";
	cin >> i >> j;
	cout << i << " " << j << endl;

	cout << "c = ";
	cin >> c;
	cout << c << endl;

	cout << "f = ";
	cin >> f;
	cout << "f = " << f << endl;

	cout << "d = ";
	cin >> d;
	cout << "d = " << d << endl;

	/*
	cout << "s = ";
	cin >> s;
	cout << "s = " << s << endl;
	*/

	cout << "s = ";
	getline(cin, s);
	cout << "s = " << s << endl;

	cout << "s = ";
	getline(cin, s);
	cout << "s = " << s << endl;
}
