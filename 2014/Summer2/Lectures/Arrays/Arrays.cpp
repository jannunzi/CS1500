#include <iostream>
#include <string>
using namespace std;

void printArray(int a[], int length, string name) {
	for (int i = 0; i < length; i++) {
		cout << name << "[" << i << "] = " << a[i] << endl;
	}
}

void incVariable(int &v) {
	v++;
}

void incArray(int a[], int length) {
	for (int i = 0; i < length; i++) {
		a[i]++;
	}
}

int main() {
	int a[10];
	a[0] = 2;
	a[5] = 12;
	a[9] = 32;
	int c = a[0] * 2 + a[5];
	cout << c << endl;
	cout << a[9] << endl;
//	for (int i = 0; i < 10; i++) {
//		cout << "a[" << i << "] = " << a[i] << endl;
//	}
	printArray(a, 10, "a");

	int b[10] = {6,5,3,4,5};
	printArray(b, 10, "b");

	int d[] = {456,567,678,987,765,654,453};
	printArray(d, 7, "d");

	cout << sizeof(int) << endl;
	cout << sizeof(a) << endl;
	int lengthOfA = sizeof(a) / sizeof(int);
	cout << lengthOfA << endl;

	int q = 6;
	cout << "q = " << q << endl;
	incVariable(q);
	cout << "q = " << q << endl;

	printArray(b, 10, "b");
	incArray(b, 10);
	printArray(b, 10, "b");

	cout << b << endl;
	cout << b + 1 << endl;
	cout << b + 2 << endl;

	cout << *b << " == " << b[0] << endl;
	cout << *(b + 1) << " == " << b[1] << endl;
	cout << *(b + 2) << " == " << b[2] << endl;
}
