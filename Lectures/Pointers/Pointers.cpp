#include <iostream>
using namespace std;

int main()
{
	int x = 5;
	cout << "x = " << x << endl;

	int *ptr = new int;
	cout << "ptr = " << ptr << endl;
	*ptr = 6;
	cout << "*ptr = " << *ptr << endl;
	int *ptr2 = ptr;

	ptr = new int;
	cout << "ptr = " << ptr << endl;
	*ptr = 7;
	cout << "*ptr = " << *ptr << endl;

	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;

	cout << "ptr = " << ptr << endl;
	ptr = &x;
	cout << "ptr = " << ptr << endl;
	*ptr = 12;
	cout << x << endl;

	x = 13;
	cout << *ptr << endl;

	getchar();
}