#include <iostream>
using namespace std;

struct Stack {
private:
	int size;
	int top;
	int* data;
public:
	Stack(int size) {
		top = -1;
		size = 0;
		if (size > 0)
		{
			this->size = size;
			data = new int[size];
		}
	}
	void push(int item) {

	}
	int pop() {
		return 0;
	}
	void display() {

	}
	bool isFull() {
		if (top == size-1)
			return true;
		return false;
	}
	bool isEmpty() {
		if (top < 0)
			return true;
		return false;
	}
};

int main() {
	Stack stack(10);
	stack.push(123);
	stack.push(234);

	cout << stack.pop() << endl;

	stack.display();
	if (!stack.isFull()) {
		stack.push(345);
	}
	cout << stack.isEmpty() << endl;
}
