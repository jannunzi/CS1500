#include <iostream>
using namespace std;

int addComplex(int real1, int imaginary1, int real2, int imaginary2) {
	int real3;
	int imaginary3;
	real3 = real1 + real2;
	imaginary3 = imaginary1 + imaginary2;
	return real3;
}

struct Complex {
	int real;
	int imaginary;
};

// overloading: same function name, different parameters
Complex addComplex(const Complex & c1, const Complex & c2) {
	Complex c3 = {0,0};

	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;

	return c3;
}

Complex subtractComplex(const Complex & c1, const Complex & c2) {
	Complex c3 = { c1.real - c2.real, c1.imaginary - c2.imaginary };
	return c3;
}

void printComplex(const Complex & c) {
	cout << c.real << " + i" << c.imaginary << endl;
}

void incrementComplex(Complex & c) {
	c.real++;
	c.imaginary++;
	cout << "While Incrementing" << endl;
	printComplex(c);
}

void incrementInteger(int& i) {
	i++;
}

int main() {

	Complex complex1 = {12,23};
	Complex complex2;
	complex2.real = 2;
	complex2.imaginary = 3;
	Complex complex3;

	complex3 = addComplex(complex1, complex2);
	printComplex(complex3);

	complex3 = subtractComplex(complex1, complex2);
	printComplex(complex3);

	cout << "Before Increment" << endl;
	printComplex(complex3);
	incrementComplex(complex3);
	cout << "After Increment" << endl;
	printComplex(complex3);

	int real1;
	int imaginary1;
	int real2;
	int imaginary2;
	int real3;
	int imaginary3;

	real1 = 12;
	imaginary1 = 23;
	real2 = 2;
	imaginary2 = 3;

	real3 = real1 + real2;
	imaginary3 = imaginary1 + imaginary2;

	cout << real3 << " + i" << imaginary3 << endl;

	addComplex(real1, imaginary1, real2, imaginary2);
}