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

//	createTray(tray1);
//	displayTray(tray1);

	Donut a, b, c, d, e;
	Donut t1[5];
	t1[0] = a;
	t1[1] = b; // etc...

	Donut t2[] = { a, b, c };
	
	cout << t1[2].name << endl;
	cout << t2[1].price << endl;

	Donut* t3[3];
	t3[0] = &a;
	t3[1] = &b;
	t3[2] = &c;

	cout << (*t3[0]).price << endl;
	cout << t3[1]->price << endl;

	Donut* t4[] = { &a, &b, &c, &d };

	int n;
	cin >> n;
	Donut* *t5 = new Donut*[n];

	int  *dynamic = new int[n];
}
