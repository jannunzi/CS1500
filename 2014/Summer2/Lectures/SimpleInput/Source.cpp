#include <iostream>
#include <string>
using namespace std;

int main() {
	int a = 12;
	int b = 23;
	int c = 34;
	float avg = ( a + b + c ) / 3;

	cout << "Average: " << avg << endl;

	float d = 5 / 2.0;
	cout << "d = " << d << endl;

	string num = "123";
	a = atoi(num.c_str()) + 234;
	cout << "num = " << num << endl;
	cout << "a = " << a << endl;

//	getline(cin, num);
	//cout << "num = " << num << endl;

	cout << "A = ";
	getline(cin, num);
	a = atoi(num.c_str());

	cout << "B = ";
	getline(cin, num);
	b = atoi(num.c_str());

	cout << "C = ";
	getline(cin, num);
	c = atoi(num.c_str());
	
	avg = (a + b + c) / 3.0;
	cout << avg << endl;
}
