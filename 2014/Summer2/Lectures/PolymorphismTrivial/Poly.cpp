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
		Base::methodB();
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
//	b1.methodC();

	Derived d1;
	d1.methodA();
	d1.methodB();
	d1.methodC();

//	Base* b = &b1;
//	b->methodA();
//	b->methodB();

	Base* b = &d1;
	b->methodA();
	b->methodB();

//	Base* collection[] = { &b1, &d1 };
	Base* collection[] = { &d1 };
	collection[0]->methodA();
	collection[0]->methodB();
	collection[0]->methodC();
//	collection[1]->methodB();
}
