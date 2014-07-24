#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	float price;
	Donut(){}
	Donut(string name, float price) {
		this->name = name;
		this->price = price;
	}
};

struct Tray {
	int size;
	int count;
	int front;
	int back;
	Donut** donuts;
	Tray(int size) {
		count = 0;
		front = 0;
		back = 0;
		this->size = size;
		donuts = new Donut*[size];
	}
};

void enqueue(Tray* tray, Donut* donut) {
	tray->donuts[tray->back] = donut;
	tray->back++;
	tray->count++;
}

Donut* dequeue(Tray* tray) {
	Donut* donut = tray->donuts[tray->front];
	tray->donuts[tray->front] = NULL;
	tray->front++;
	tray->count--;
	return donut;
}

void displayDonut(Donut* donut) {
	if (donut != NULL)
		cout << donut->name << " $" << donut->price << endl;
}

void displayTray(Tray* tray) {
	cout << "Tray: " << endl;
	for (int i = tray->front; i < tray->back; i++) {
		Donut* donut = tray->donuts[i];
		displayDonut(donut);
	}
}

int main() {
	for (int i = 0; i < 100; i++) {
		cout << i << " " << i % 10 << endl;
	}

	Donut* d1 = new Donut("D1", 12.23);
	Donut* d2 = new Donut("D2", 13.23);
	Donut* d3 = new Donut("D3", 14.23);
	Donut* d4 = new Donut("D4", 15.23);
	Donut* d5 = new Donut("D5", 16.23);

	displayDonut(d1);

	Tray* tray = new Tray(10);

	enqueue(tray, d1);
	enqueue(tray, d2);
	enqueue(tray, d3);
	enqueue(tray, d4);
	enqueue(tray, d5);

	displayTray(tray);

	Donut* ptr = dequeue(tray);

	displayTray(tray);
}
