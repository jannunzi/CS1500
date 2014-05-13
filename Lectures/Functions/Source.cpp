#include <iostream>
using namespace std;

void passValue(int x)
{
	x++;
	cout << x << endl;
}

void increment(int &y)
{
	y++;
	cout << y << endl;
}

void swapIntegers(int &a, int &b)
{
	cout << "Before:" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	int tmp = a;
	a = b;
	b = tmp;

	cout << "After:" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int x = 21;
	passValue(x);
	cout << x << endl;

	int y = 32;
	increment(y);
	cout << y << endl;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	swapIntegers(x, y);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	int mn = min(x, y);
	cout << "Min: " << mn << endl;
	
	int mx = max(x, y);
	cout << "Max: " << mx << endl;

	getchar();
}