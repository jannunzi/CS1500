#include <iostream>
#include <string>
using namespace std;

struct Book
{
	string title = "";
	string isbn = "";
	float  price;
};

const int MAX = 10;
int top = 0;

void displayStack(Book stack[])
{
	for (int i = MAX-1; i >= 0; i--)
	{
		cout << "["<< i <<"] " << stack[i].title << endl;
	}
	cout << "============" << endl << endl;
}

void push(Book book, Book stack[])
{
	if (top < MAX)
	{
		stack[top] = book;
		top++;
	}
	else
	{
		cout << "Stack is full." << endl;
	}
}

Book pop(Book stack[])
{
	if (top > 0)
	{
		top--;
		return stack[top];
	}
	else
	{
		cout << "Stack is empty." << endl;
	}
	Book bogus;
	return bogus;
}

int main()
{
	Book stack[MAX];

	Book dune;
	dune.title = "Dune";
	dune.isbn = "123123123";
	dune.price = 9.99;

	Book lotr;
	lotr.title = "Lord of the Rings";
	lotr.isbn = "321123321";
	lotr.price = 8.99;

	Book blade;
	blade.title = "Do Robots Dream of Electric Sheep";
	blade.isbn = "234432234";
	blade.price = 7.99;

	displayStack(stack);
	push(dune, stack);
	push(lotr, stack);
	displayStack(stack);

	Book b1 = pop(stack);
	cout << b1.title << endl;
	b1 = pop(stack);
	cout << b1.title << endl;
	b1 = pop(stack);
	cout << b1.title << endl;

	push(blade, stack);
	push(dune, stack);
	push(lotr, stack);
	displayStack(stack);

	getchar();
}