#include <iostream>
#include <string>
using namespace std;

struct Donut
{
	string flavor;
	float price;
};

struct Queue
{
	Donut* tray;
	int trayCapacity;
	int front;
	int back;
};

Donut* makeDonut(int flavor, int filling);
void enqueueDonut(Queue* queue, Donut* donut);
Donut* dequeueDonut(Queue* queue);
void displayDonutQueue(Queue* queue);

void main321()
{
	Queue* donutQueue = new Queue;
	donutQueue->trayCapacity = 10;
	donutQueue->tray = new Donut[10];
	
}

void displayDonutQueue(Queue* queue)
{
	for (int i = queue->trayCapacity; i >= 0; i--)
	{
		cout << "[" << i << "]" << endl;// << queue->tray[i]->flavor << endl;
	}
}
