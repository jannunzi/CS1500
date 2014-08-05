#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string flavor = "New Donut";
	float price = 0.0;
	int* stale = NULL;
	Donut* next = NULL;
	Donut* prev = NULL;
	Donut(){
		cout << "Default Constructor" << endl;
	}
	Donut(string flavor, float price) {
		cout << "All Arguments Constructor" << endl;
		this->flavor = flavor;
		this->price = price;
	}
	Donut(const Donut* other) {
		cout << "Copy Constructor By Pointer" << endl;
		this->flavor = other->flavor;
		this->price = other->price;
		int* newStale = new int;
		*newStale = *(other->stale);
		this->stale = newStale;
	}
	Donut(const Donut& other) {
		cout << "Copy Constructor By Reference" << endl;
		cout << "Copying from: " << other.flavor << endl;
		this->flavor = other.flavor;
		this->price = other.price;
		int* newStale = new int;
		*newStale = *(other.stale);
		this->stale = newStale;
	}
	void display() {
		cout << flavor << " $" << price << endl;
	}
};

struct DonutTray {
	Donut* head = NULL;
	Donut* tail = NULL;
	DonutTray(){}
//	/*
	DonutTray(const DonutTray& other) {
		cout << "Donut Tray Copy Constructor !!!!" << endl;

		Donut* current = other.head;
		while (current != NULL) {

			Donut* nd = new Donut(current->flavor, current->price);
			append(nd);

			current = current->next;
		}
//		this->head = other.head;
//		this->tail = other.tail;
	}
//	*/
	void append(Donut* newDonut) {
		if (head == NULL) {
			head = newDonut;
			tail = newDonut;
			return;
		}
		tail->next = newDonut;
		tail = newDonut;
	}
	void display() {
		Donut* current = head;
		while (current != NULL) {
			current->display();
			current = current->next;
		}
	}
};

void display(Donut *d) {
	cout << d->price;
}

int main() {
	Donut d1;
	int s = 4;
	d1.stale = &s;
	d1.display();
	Donut d2("Chocolate", 12.23);
	d2.stale = &s;
	d2.display();
	Donut d3 = d2;
	d3.display();

	*(d2.stale) = 5;
	d2.display();
	d3.display();

	Donut* d4 = new Donut();
	Donut d5 = d4;

	Donut* a = new Donut("A", 1);
	Donut* b = new Donut("B", 2);
	Donut* c = new Donut("C", 3);
	Donut* d = new Donut("D", 4);

	DonutTray dt1;
	dt1.append(a);
	dt1.append(b);
	dt1.append(c);
	dt1.append(d);

	cout << "DT1" << endl;
	dt1.display();

	cout << "DT2" << endl;
	DonutTray dt2 = dt1;
	dt2.display();

	dt1.head->flavor = "AA";
	cout << "DT1" << endl;
	dt1.display();

	cout << "DT2" << endl;
	dt2.display();
}
