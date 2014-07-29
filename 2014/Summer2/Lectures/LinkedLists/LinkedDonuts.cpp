#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	float price;
	Donut* next;
	Donut(){}
	Donut(string name, float price) {
		this->name = name;
		this->price = price;
		next = NULL;
	}
};

void displayList(Donut* head) {
	cout << "Display List" << endl;
	Donut* ptr = head;
	int count = 0;
	while (ptr != NULL) {
		cout << "["<<count<<"] " << ptr->name << " $" << ptr->price << endl;
		count++;
		ptr = ptr->next;
	}
}

void append(Donut* head, Donut* newDonut) {
	Donut* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newDonut;
	displayList(head);
}

void prepend(Donut* head, Donut* newDonut) {
	newDonut->next = head;
	head = newDonut;
}

void setInt(int *var, int val) {
	*var = val;
}

void setPtr(Donut* *var, Donut* val) {
	*var = val;
}

int main() {


	Donut* d1 = new Donut("D1", 1.22);
	Donut* d2 = new Donut("D2", 1.23);
	Donut* d3 = new Donut("D3", 1.24);

	int x = 10;
	cout << x << endl;
	setInt(&x, 20);
	cout << x << endl;

	Donut* p = d1;
	cout << p->name << endl;
	setPtr(&p, d2);
	cout << p->name << endl;



	d1->next = d2;
	d2->next = d3;
	d3->next = NULL;

	cout << d1->name << endl;
	cout << d2->name << endl;

	cout << d1->next->name << endl;
	cout << d1->next->next->name << endl;

	Donut* ptr = d1;
	cout << ptr->name << endl;
	cout << ptr->next->name << endl;
	cout << ptr->next->next->name << endl;

	ptr = d1;
	cout << ptr->name << endl;

	ptr = ptr->next;
	cout << ptr->name << endl;

	ptr = ptr->next;
	cout << ptr->name << endl;

	cout << "Display List" << endl;
	ptr = d1;
	while (ptr != NULL) {
		cout << ptr->name << endl;
		ptr = ptr->next;
	}

	Donut* head = NULL;

	ptr = new Donut("A", 2.33);
	ptr->next = head;
	head = ptr;

	ptr = new Donut("B", 2.34);
	ptr->next = head;
	head = ptr;

	ptr = new Donut("C", 2.35);
	ptr->next = head;
	head = ptr;

	for (int i = 0; i < 10; i++){
		ptr = new Donut("D", 1.23 * i);
		ptr->next = head;
		head = ptr;
	}

	displayList(head);

	ptr = new Donut("Chocolate", 2.33);
	ptr->next = NULL;
	Donut* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = ptr;
	displayList(head);



	ptr = new Donut("Glazed", 2.33);
	ptr->next = NULL;
	current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = ptr;
	displayList(head);

	ptr = new Donut("Vanilla", 2.35);
	append(head, ptr);
	ptr = new Donut("Boston Cream", 2.35);
	append(head, ptr);
	ptr = new Donut("Bear Claw", 2.35);
	append(head, ptr);
	ptr = new Donut("Butter Pecan", 2.35);
	append(head, ptr);

	displayList(head);

	ptr = new Donut("Strawberry", 123.32);
	prepend(head, ptr);
	displayList(head);
}
