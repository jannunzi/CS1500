#include <iostream>
using namespace std;

struct Queue {
	int head;
	int tail;
	int size;
	int count;
	int * data;
};

void initQueue(Queue & q, int size) {
	q.size = size;
	q.count = 0;
	q.head = 0;
	q.tail = 0;
	q.data = new int[size];
}

void printQueue(Queue & q) {
	cout << "------" << endl;
	int j = q.head;
	for (int i = 0; i < q.count; i++)
	{
		cout << "["<<j<<"] " << q.data[j] << endl;
		j = (j+1) % q.size;
	}
}

void enqueue(Queue & q, int data) {
	if (q.count < q.size) {
		q.data[q.tail] = data;
		q.count++;
		q.tail = (q.tail + 1) % q.size;
	}
	else {
		cout << "Sorry, queue is full" << endl;
	}
}

int dequeue(Queue & q) {
	int data = q.data[q.head];
	q.count--;
	q.head = (q.head + 1) % q.size;
	return data;
}

int main()
{
	Queue q1;
	initQueue(q1, 5);
	enqueue(q1, 123);
	enqueue(q1, 234);
	printQueue(q1);
	int data = dequeue(q1);
	cout << data << endl;
	printQueue(q1);

	enqueue(q1, 345);
	enqueue(q1, 456);
	enqueue(q1, 567);
	enqueue(q1, 678);

	printQueue(q1);
	data = dequeue(q1);
	cout << data << endl;
	printQueue(q1);

	enqueue(q1, 789);
	printQueue(q1);
	enqueue(q1, 890);
	printQueue(q1);
	enqueue(q1, 990);
	printQueue(q1);
}
