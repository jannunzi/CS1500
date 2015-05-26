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
