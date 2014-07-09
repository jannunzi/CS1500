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
	cout << n << endl;
	if (n == 0)
		return 1;
	int f = n * factorial(n - 1);
	cout << n << endl;
	return f;
}

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int fibIter(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int f0 = 0;
	int f1 = 1;
	int fn = 0;
	for (int i = 0; i < n-1; i++) {
		fn = f0 + f1;
		f0 = f1;
		f1 = fn;
	}
	return fn;
}

int main() {
//	func(10);
//	cout << factorial(5) << endl;
	for (int n = 0; n < 10; n++)
	{
		cout << fib(n) << "\t" << fibIter(n) << endl;
	}
}