#include <iostream>
using namespace std;

void functionC()
{
	int a = 345;
	cout << "Entering functionC()" << a << endl;
	cout << "Leaving functionC()" << a << endl;
}


void functionB()
{
	int a = 234;
	cout << "Entering functionB()" << a << endl;
	functionC();
	cout << "Leaving functionB()" << a << endl;
}


void functionA()
{
	int a = 123;
	cout << "Entering functionA()" << a << endl;
	functionB();
	cout << "Leaving functionA()" << a << endl;
}

void functionR(int counter)
{
	cout << "Entering functionR() " << counter << endl;
	if (counter>0)
		functionR(counter-1);
	cout << "Leaving functionR()" << counter << endl;
}

int main()
{
	functionA();
//	functionR(2);
	getchar();
}