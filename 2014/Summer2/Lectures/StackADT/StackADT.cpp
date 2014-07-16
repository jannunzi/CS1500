#include <iostream>
using namespace std;

const int SIZE = 10;

void push(int data, int stack[], int & top) {
	stack[top] = data;
	top++;
}

int pop(int stack[], int & top) {
	top--;
	int data = stack[top];
	return data;
}

int main() {
	int top = 0;
	int stack[SIZE];
	push(123, stack, top);
	push(234, stack, top);

	int data = pop(stack, top);
	cout << data << endl;
	data = pop(stack, top);
	cout << data << endl;
}