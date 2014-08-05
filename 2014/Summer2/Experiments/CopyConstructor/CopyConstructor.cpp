#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name = "";
	float price = 0;
	Donut* next = NULL;
	Donut(){}
	Donut(const Donut& other) {
		cout << "Donut Copy Constructor by Reference" << endl;
		this->name = other.name;
		this->price = other.price;
	}
	Donut(const Donut* other) {
		cout << "Donut Copy Constructor by Pointer" << endl;
		this->name = other->name;
		this->price = other->price;
	}
	Donut(string name, float price) {
		this->name = name;
		this->price = price;
	}
	void display() {
		cout << name << " $" << price << endl;
	}
};

struct DonutTray {
	Donut* head = NULL;
	Donut* tail = NULL;
	DonutTray(const DonutTray& other) {
		cout << "DonutTray Copy Constructor" << endl;
		//this->head = other.head;
		Donut* current = other.head;
		while (current != NULL) {
			Donut* copyDonut = new Donut(current->name, current->price);
			append(copyDonut);
			current = current->next;
		}
	}
	void append(Donut* donut) {
		if (head == NULL) {
			head = donut;
			tail = donut;
			return;
		}
		tail->next = donut;
		tail = donut;
		donut->next = NULL;
	}
	DonutTray(){};
	void display() {
		Donut* current = head;
		while (current != NULL) {
			current->display();
			current = current->next;
		}
	}
	void copy() {

	}
};

int main() {
	cout << "Copy Object to Object" << endl;
	Donut d1("Chocolate", 12.23);
	Donut d2 = d1;
	d1.display();
	d2.display();

	cout << "Copy Reference to Reference" << endl;
	Donut* d3 = new Donut("Vanilla", 23.34);
	Donut* d4 = d3;
	d3->display();
	d4->display();

	cout << "Copy Reference to Object" << endl;
	Donut d5 = d3;
	d5.display();

	cout << "Build List" << endl;
	d1.next = &d2;
	d2.next = d3;
	d3->next = d4;
	d4->next = &d5;

	cout << "Donut Tray 1" << endl;
	DonutTray tray1;
	tray1.head = &d1;
	tray1.display();

	cout << "Copy Tray 1 to Tray 2" << endl;
	DonutTray tray2 = tray1;
	cout << "Donut Tray 2" << endl;
	tray2.display();

	tray1.head->price = 444.44;
	cout << tray2.head->price << endl;
}
