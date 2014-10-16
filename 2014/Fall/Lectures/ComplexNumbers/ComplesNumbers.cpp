#include <iostream>
#include <string>
using namespace std;

struct Complex {
	string name = "";
	float real = 0;
	float imaginary = 0;
	// default constructor (no arguments)
	Complex() {
		//real = 0;
		//imaginary = 0;
	}
	Complex(float real, float imaginary, string name) {
		this->real = real;
		this->imaginary = imaginary;
		this->name = name;
	}
	// all argument constructor
	Complex(float real, float imaginary)
		: Complex(real, imaginary, "")
	{
	}
	void display() {
		if (name == "")
			cout << real << " + i" << imaginary << endl;
		else
			cout << name << " = " << real << " + i" << imaginary << endl;
	}
	void set(float real, float imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}
	Complex plus(Complex other) {
		Complex result;
		result.real      = this->real + other.real;
		result.imaginary = this->imaginary + other.imaginary;
		return result;
	}
	Complex minus(Complex other) {
		Complex result(this->real - other.real, this->imaginary - other.imaginary);
		return result;
	}
};

// functional programming
void displayComplex(Complex c) {
	cout << c.real << " + i" << c.imaginary << endl;
}

int main() {
	Complex A;
	Complex B = {12,23};
	Complex C(20,30);

	displayComplex(B);

	B.display();
	B.set(10, 20);
	B.display();

	A = B.plus(C); // A = B + C
	A.display();
	B = A.minus(C);
	B.display();

	Complex* D = new Complex(11,22,"D");
	Complex* E = new Complex(22,33,"E");
	D->display();
	E->display();
}
