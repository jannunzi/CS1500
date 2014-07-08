#include <iostream>
using namespace std;

void func(int b) {
	int a = 123;
	a++;
	b--;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	if (b <= 0)
		return;

	func(b);
}

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int main() {
	func(10);
	cout << factorial(5) << endl;
}