#include <iostream>
#include <string>
using namespace std;

int main() {
	int num = atoi("234");
	cout << num << endl;

	string str = "123";
	num = atoi(str.c_str());
	cout << num << endl;

	getline(cin, str);
	num = atoi(str.c_str());
	cout << num << endl;

	getline(cin, str);
	float flt = atof(str.c_str());
	cout << flt << endl;
}
