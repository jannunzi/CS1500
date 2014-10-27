#include <iostream>
using namespace std;

struct Fraction {
	float numerator;
	float denominator;
	Fraction() {}
	Fraction(float num, float denom) {
		numerator = num;
		denominator = denom;
	}
	void display() {
		cout << numerator << "/" << denominator << endl;
	}
	Fraction plus(Fraction other) {
		Fraction result;
		if (numerator == other.numerator) {
			result.numerator = numerator + other.numerator;
			result.denominator = denominator;
		}
		return result;
	}
	Fraction times(Fraction other) {
		Fraction result(numerator * other.numerator, denominator * other.denominator);
		return result;
	}
};

int main() {
	Fraction a(1, 2);
	Fraction b(1, 2);
	Fraction c = a.plus(b);
	c.display();
	Fraction d = c.times(a);
	d.display();
}
