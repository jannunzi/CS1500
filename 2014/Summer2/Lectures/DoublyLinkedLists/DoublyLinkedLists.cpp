#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	float price;
	Donut* next;
	Donut* prev;
	Donut();
	Donut(string name, float price);
	void display();
};

void Donut::display() {
	cout << name << " $" << price;
}

struct DonutList {
	string name;
	Donut* head;
	Donut* tail;
	int length;
	DonutList();
	DonutList(string name);
	void append(Donut* newDonut);
	void prepend(Donut* newDonut);
	Donut* findByPrice(float price);
	void removeByPrice(float price);
	void insertAtIndex(Donut* newDonut, int index);
	void display();
	void displayReverse();
};

Donut::Donut() {
	next = NULL;
	prev = NULL;
}
Donut::Donut(string name, float price)
	: Donut()
{
	this->name = name;
	this->price = price;
}

DonutList::DonutList(){
	head = NULL;
	tail = NULL;
	length = 0;
	name = "New Donut List";
}
DonutList::DonutList(string name)
	: DonutList()
{
	this->name = name;
}
void DonutList::append(Donut* newDonut){
	if (head == NULL && tail == NULL){
		length = 1;
		head = newDonut;
		tail = newDonut;
		return;
	}
	newDonut->prev = tail;
	tail->next = newDonut;
	tail = newDonut;
	length++;
}
void DonutList::prepend(Donut* newDonut){
	if (head == NULL && tail == NULL){
		length = 1;
		head = newDonut;
		tail = newDonut;
		return;
	}
	newDonut->next = head;
	head->prev = newDonut;
	head = newDonut;
	length++;
}
// returns the first donut with price parameter
Donut* DonutList::findByPrice(float price){
	Donut* current = head;
	while (current != NULL) {
		if (current->price == price) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}
void DonutList::removeByPrice(float price){
	Donut* removeMe = NULL;
	if (head == NULL || tail == NULL){
		length = 0;
		return;
	}
	if (head == tail) {
		length = 0;
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	if (head->price == price) {
		length--;
		head = head->next;
		delete head->prev;
		head->prev = NULL;
		return;
	}

	removeMe = findByPrice(price);

	if (removeMe == NULL)
		return;

	if (removeMe == tail) {
		length--;
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
		return;
	}

	removeMe->prev->next = removeMe->next;
	removeMe->next->prev = removeMe->prev;
	length--;

	delete removeMe;
}
void DonutList::insertAtIndex(Donut* newDonut, int index){
	if (head == NULL && tail == NULL) {
		if (index == 0) {
			head = newDonut;
			tail = newDonut;
			length = 1;
		}
		return;
	}
	if (index == 0) {
		newDonut->next = head;
		head->prev = newDonut;
		length++;
		return;
	}
	int counter = 1;
	Donut* current = head;
	while (current != NULL) {
		if (counter == index) {
			current->next->prev = newDonut;
			newDonut->next = current->next;
			current->next = newDonut;
			newDonut->prev = current;
		}
		current = current->next;
		counter++;
	}
}
void DonutList::display() {
	Donut* current = head;
	int counter = 0;
	while (current != NULL) {
		cout << "["<<counter<<"]\t";
		current->display();
		cout << endl;
		current = current->next;
		counter++;
	}
	cout << endl;
}
void DonutList::displayReverse() {
	Donut* current = tail;
	int counter = length - 1;
	while (current != NULL) {
		cout << "[" << counter << "]\t";
		current->display();
		cout << endl;
		current = current->prev;
		counter--;
	}
	cout << endl;
}

int main()
{
	DonutList* tray1 = new DonutList("Tray 1");

	Donut* ptr = new Donut("Chocolate", 1.23);
	tray1->append(ptr);
	tray1->display();

	ptr = new Donut("Vanilla", 1.24);
	tray1->append(ptr);
	tray1->display();

	ptr = new Donut("Jelly", 1.25);
	tray1->prepend(ptr);
	tray1->display();

	tray1->displayReverse();

	ptr = tray1->findByPrice(1.26);
	if (ptr != NULL) {
		ptr->display();
		cout << endl;
	}
	else {
		cout << "Donut not found" << endl;
	}

	tray1->removeByPrice(1.27);
	tray1->display();
}
