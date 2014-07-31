#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	float price;
	Donut* next;
	Donut() {}
	Donut(string name, float price) {
		this->name = name;
		this->price = price;
		next = NULL;
	}
};

struct DonutList {
	Donut* head = NULL;
	Donut* tail = NULL;
	int length = 0;
	string name;
	DonutList() {
		head = NULL;
		tail = NULL;
		length = 0;
	};
	DonutList(string name) : DonutList() {
		this->name = name;
	};
	void append(Donut* newDonut) {
		if (head == NULL) {
			head = newDonut;
			tail = newDonut;
			return;
		}
		tail->next = newDonut;
		tail = newDonut;
		length++;
	}
	void prepend(Donut* newDonut) {
		if (head == NULL) {
			head = newDonut;
			tail = newDonut;
			return;
		}
		newDonut->next = head;
		head = newDonut;
	}
	void display() {
		Donut* current = NULL;
		int index = 0;
		cout << "\n" << name << endl;
		for (current = head; current != NULL; current = current->next) {
			cout << "[" << index << "] " << current->name << " $" << current->price << endl;
			index++;
		}
	}
	void concatenateBad(DonutList* otherList) {
		this->tail->next = otherList->head;
		this->tail = otherList->tail;
	}

	DonutList* concatenate(DonutList* otherList) {
		DonutList* newList = new DonutList("Concatenated List");
		Donut* current = this->head;
		while (current != NULL) {
			newList->append(current);
			current = current->next;
		}
		current = otherList->head;
		while (current != NULL) {
			newList->append(current);
			current = current->next;
		}
		return newList;
	}
};

int main() {

	DonutList* tray1 = new DonutList("Tray 1");

	Donut* ptr = new Donut("Chocolate", 1.2);
	tray1->append(ptr);
	ptr = new Donut("Vanilla", 1.2);
	tray1->append(ptr);
	ptr = new Donut("Jelly", 1.2);
	tray1->append(ptr);
	ptr = new Donut("Glazed", 1.2);
	tray1->append(ptr);
	ptr = new Donut("Cream", 1.2);
	tray1->append(ptr);
	tray1->display();

	ptr = new Donut("Rocky", 1.3);
	tray1->prepend(ptr);
	tray1->display();

	DonutList* tray2 = new DonutList("Tray 2");
	ptr = new Donut("A", 1.2);
	tray2->append(ptr);
	ptr = new Donut("B", 1.2);
	tray2->append(ptr);
	ptr = new Donut("C", 1.2);
	tray2->append(ptr);
	ptr = new Donut("D", 1.2);
	tray2->append(ptr);
	tray2->display();

	DonutList* tray3 = tray1->concatenate(tray2);
	tray3->display();


	tray1->display();

	/*

	ptr = new Donut("X", 1.2);
	tray1->append(ptr);
	ptr = new Donut("Y", 1.2);
	tray1->append(ptr);
	ptr = new Donut("Z", 1.2);
	tray1->append(ptr);
	tray1->display();
	tray2->display();

	ptr = new Donut("R", 1.2);
	tray2->append(ptr);
	ptr = new Donut("S", 1.2);
	tray2->append(ptr);
	ptr = new Donut("T", 1.2);
	tray2->append(ptr);
	tray1->display();
	tray2->display();
	*/
}
