#include <iostream>
#include <string>
using namespace std;

class Base {
public:
	void methodA() {
		cout << "A Base" << endl;
	}
	virtual void methodB() {
		cout << "B Base" << endl;
	}
	virtual void methodC() = 0;
};

class Derived : public Base {
public:
	void methodA() {
		cout << "A Derived" << endl;
	}
	void methodB() {
		cout << "B Derived" << endl;
	}
	void methodC() {
		cout << "C Derived" << endl;
	}
};

int main() {
//	Base b1;
//	b1.methodA();
//	b1.methodB();

	Derived d1;
	d1.methodA();
	d1.methodB();

//	Base* b2 = &b1;
//	b2->methodA();
//	b2->methodB();

	Base* b2 = &d1;
	b2->methodA();
	b2->methodB();
	b2->methodC();
}
