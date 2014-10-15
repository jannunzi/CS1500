#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	float price;
};

struct DonutTray {
	Donut* *donuts;
	int size;
};

void createTray(DonutTray* tray1) {
	for (int i = 0; i < tray1->size; i++) {
		Donut* donut = new Donut();
		cout << "Flavor: ";
		cin >> donut->name;
		tray1->donuts[i] = donut;
	}
}

void displayTray(DonutTray* tray1)
{
	for (int i = 0; i < tray1->size; i++) {
		cout << tray1->donuts[i]->name << endl;
	}
}


int main() {
	DonutTray* tray1 = new DonutTray();
	cout << "Size of tray: ";
	cin >> tray1->size;
	tray1->donuts = new Donut*[tray1->size];

	createTray(tray1);
	displayTray(tray1);
}
