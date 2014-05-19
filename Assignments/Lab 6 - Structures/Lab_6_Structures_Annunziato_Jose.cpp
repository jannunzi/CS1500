#include <iostream>
using namespace std;

struct Complex {
	float real;
	float imaginary;
};

void displayComplex(Complex n);
Complex addComplex(Complex a, Complex b);
Complex subtractComplex(Complex a, Complex b);
Complex multiplyComplex(Complex a, Complex b);
void tryToSetComplexByValue(Complex a, float real, float imaginary);
void setComplexByReference(Complex &a, float real, float imaginary);
void setComplexByPointer(Complex *a, float real, float imaginary);

int main()
{
	Complex x = { 3, 2 };
	Complex y = { 1, 4 };
	displayComplex(x);
	displayComplex(y);

	Complex sum = addComplex(x, y);
	displayComplex(sum);

	Complex diff = subtractComplex(x, y);
	displayComplex(diff);

	Complex product = multiplyComplex(x, y);
	displayComplex(product);

	tryToSetComplexByValue(x, 4, 5);
	displayComplex(x);

	setComplexByReference(x, 4, 5);
	displayComplex(x);

	setComplexByPointer(&x, 5, 6);
	displayComplex(x);

	getchar();
}

void displayComplex(Complex n)
{
	if (n.imaginary > 0)
	{
		cout << n.real << " + i" << n.imaginary << endl;
	}
	else
	{
		cout << n.real << " - i" << (-n.imaginary) << endl;
	}
}

Complex addComplex(Complex a, Complex b)
{
	Complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return c;
}

Complex subtractComplex(Complex a, Complex b)
{
	Complex c;
	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;
	return c;
}

Complex multiplyComplex(Complex a, Complex b)
{
	Complex c;
	c.real = a.real * b.real - a.imaginary * b.imaginary;
	c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return c;
}

void tryToSetComplexByValue(Complex a, float real, float imaginary)
{
	a.real = real;
	a.imaginary = imaginary;
}

void setComplexByReference(Complex &a, float real, float imaginary)
{
	a.real = real;
	a.imaginary = imaginary;
}

void setComplexByPointer(Complex *a, float real, float imaginary)
{
	a->real = real;
	a->imaginary = imaginary;
}
