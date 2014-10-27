#include <iostream>
using namespace std;

struct BigInteger {
	int size;
	int * value;
	BigInteger(){}
	BigInteger(int * value, int size) {
		this->value = value;
		this->size = size;
	}
	BigInteger plus(BigInteger other) {
		BigInteger result;
		result.size = this->size > other.size ? this->size : other.size;
		result.value = new int[result.size + 1];

//		012345
//		123456
//		  7890
//		  0123
		return result;
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << value[i];
		}
		cout << endl;
	}
};

int main() {
	int decimalA[] = { 1, 2, 3, 4, 5, 6 };
	int decimalB[] =       { 2, 3, 4, 5 };
	BigInteger a(decimalA, 6);
	BigInteger b(decimalB, 4);
	a.display();	// 123456
	b.display();	//   2345
	BigInteger c = a.plus(b);
	c.display();	// 125801

//	 999999
//	 999999
//	1999998
}
