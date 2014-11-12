#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	string title;
	string isbn;
	Book * rest = NULL;
	Book() : Book("Unknown Title","Unknown ISBN") {
	
	}
	Book(string title) : Book(title, "Unknown ISBN") {

	}
	Book(string title, string isbn) {
		this->title = title;
		this->isbn = isbn;
	}
	void display() {
		cout << isbn << " " << title << endl;
	}
};

class StackOfBooks {
public:
	Book * top = NULL;
	StackOfBooks() {}
	StackOfBooks(Book * top) {
		this->top = top;
	}
	Book * pop() {
		if (top == NULL)
			return NULL;
		Book * book = top;
		top = top->rest;
		return book;
	}
	void push(Book * newBook) {
		if (top == NULL) {
			top = newBook;
			return;
		}
		newBook->rest = top;
		top = newBook;
	}
	void display() {
		Book * current = top;
		while (current != NULL) {
			current->display();
			current = current->rest;
		}
	}
};

int main() {
	Book * lotr = new Book("Lord of The Rings", "123");
	Book * dune = new Book("Dune", "234");
	Book * ender = new Book("Ender's Game", "345");

	StackOfBooks * stack = new StackOfBooks();
	stack->push(lotr);
	stack->push(dune);
	stack->push(ender);
	stack->display();

	Book * b = stack->pop();
	b->display();
	b = stack->pop();
	b->display();
	b = stack->pop();
	b->display();

	//if (b != NULL)
	//{
	//	b->display();
	//}
	//else
	//{
	//	cout << "Stack is empty" << endl;
	//}
}
