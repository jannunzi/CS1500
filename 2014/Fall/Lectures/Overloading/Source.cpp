#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
	string name;
public:
	Base(){}
	Base(string name) {
		this->name = name;
	}
	void display() {
		cout << "Base: " << name << endl;
	}
};

class Derived : public Base {
protected:
	int size;
public:
	Derived(){}
	Derived(string name, int size)
		: Base(name)
	{
		this->size = size;
	}

	void display(string title) {
		cout << "[1] " << title << ": " << name << " " << size << endl;
	}
	void display(string title, int size)
	{
		cout << "[2] " << title << ": " << name << " " << size << endl;
	}
};

int main() {
	Base * b = new Base("b");
	b->display();
	Derived * d = new Derived("d", 123);
	d->display("title 123");
	d->display("title 234", 432);
}