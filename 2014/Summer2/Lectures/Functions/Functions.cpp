#include <iostream>
#include <string>
using namespace std;

void sayHello();
void sayGoodbye();
void sayMessage(string message);
int addTwoIntegers(int a, int b);
void increment(int &x);

int main() {
	sayMessage("Hello");
	sayMessage("Goodbye");
	int c = addTwoIntegers(2, 3);
	cout << c << endl;
	cout << addTwoIntegers(3, 4) << endl;
	int q = 5 + addTwoIntegers(4, 5);
	cout << q << endl;

	increment(c);
	cout << "c = " << c << endl;
}

void sayHello() {
	cout << "Hello" << endl;
}
void sayGoodbye() {
	cout << "Goodbye" << endl;
}
void sayMessage(string message) {
	cout << message << endl;
}
int addTwoIntegers(int a, int b) {
	int c = a + b;
	return c;
}
void increment(int &x) {
	x++;
	cout << "x = " << x << endl;
}
