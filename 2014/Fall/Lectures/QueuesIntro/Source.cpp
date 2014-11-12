#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	string title;
	string isbn;
	Book * rest = NULL;
	Book() : Book("Unknown Title", "Unknown ISBN") {

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

class QueueOfBooks {
public:
	Book * front = NULL;
	Book * back = NULL;
	Book * dequeue() {
		if (front == NULL) {
			return NULL;
		}
		Book * book = front;
		front = front->rest;
		return book;
	}
	void enqueue(Book * newBook) {
		if (front == NULL) {
			front = newBook;
			back = newBook;
			return;
		}
		back->rest = newBook;
		back = newBook;
	}
	void display() {
		cout << "---" << endl;
		Book * current = front;
		while (current != NULL) {
			current->display();
			current = current->rest;
		}
		cout << "---" << endl;
	}
};

int main() {
	Book * lotr = new Book("Lord of The Rings", "123");
	Book * dune = new Book("Dune", "234");
	Book * ender = new Book("Ender's Game", "345");

	QueueOfBooks * queue = new QueueOfBooks();
	queue->enqueue(lotr);
	queue->enqueue(dune);
	queue->enqueue(ender);
	queue->display();

	Book * b = queue->dequeue();
	b->display();
	queue->display();

	b = queue->dequeue();
	b->display();
	queue->display();
}
