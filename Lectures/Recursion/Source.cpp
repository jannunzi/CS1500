#include <iostream>
using namespace std;

void t(int i)
{
	cout << i << endl;
}

int f(int i)
{
	if (i < 0)
		return i;
	cout << i << endl;
	i = f(i - 1);
	cout << i << endl;
	return i;
}




void sayHello()
{
	cout << "Hello" << endl;
}

void sayGoodbye()
{
	sayHello();
	cout << "Goodbye" << endl;
}

int fact(int n)
{
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int binSearch(int haystack[], int needle,
				int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middle = (start + end) / 2;
	if (needle == haystack[middle])
	{
		return middle;
	}
	else if (needle > haystack[middle])
	{
		return binSearch(haystack, needle, middle + 1, end);
	}
	else if (needle < haystack[middle])
	{
		return binSearch(haystack, needle, start, middle - 1);
	}
	return -1;
}

int main()
{
	int values[] = { 12, 23, 34, 45, 56, 67, 78 };
	int foundIndex = binSearch(values, 67, 0, 6);
	cout << "Found at " << foundIndex << endl;


	int x = 13;
	int v = fib(x);
	cout << "Fibonacci of " << x << " is" << v << endl;

	int n = 5;
	int value = fact(n);
	cout << "factorial of " << n << " is " << value << endl;

	sayHello();
	sayGoodbye();

	cout << "calling f()" << endl;
	int i = 5;
	cout << i << endl;
	f(i);
	cout << i << endl;
	getchar();
}