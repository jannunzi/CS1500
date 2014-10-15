#include <iostream>
using namespace std;

struct A {
	int a;
	int b;
	A() {
		cout << "Hello" << endl;
	}
	A(int q, int w) {
		cout << "Hello 2" << endl;
	}
	~A() {
		cout << "Good Bye" << endl;
	}
};

int main() {
	A a;
	A b = { 12, 23 };
	A c(23,34);
	A * d = new A();
	A * e = new A(34,45);
}
