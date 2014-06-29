#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	double price;
	int    age;
	Donut* next = NULL;
	Donut(string name, double price, int age)
	{
		int ewq;
		this->name = name;
		this->price = price;
		this->age = age;
	}
	void display(){
		cout << "===========================" << endl;
		cout << this   << " Donut:" << endl;
		cout << &name  << " Name:  " << name << endl;
		cout << &price << " Price: " << price << endl;
		cout << &age   << " Age:   " << age << endl;
		cout << &next  << " Next:  " << next << endl;
		cout << "===========================" << endl << endl;
	}
};

int sizeOfList(Donut* head)
{
	int length = 0;

	Donut* current = head;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}

	return length;
}

void displayList(Donut* head)
{
	Donut* current = head;
	while (current != NULL)
	{
		cout << current << endl;
		cout << current->next << endl;
		(*current).display();
//		current->display();
		current = current->next;
	}
}

void appendDonut(Donut* head, Donut* newDonut)
{
	Donut* current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newDonut;
}

void prependDonut(Donut* * head, Donut* donut)
{
	donut->next = *head;
	*head = donut;
}

int main()
{
	Donut* head = NULL;

	Donut* chocolate = new Donut("Chocolate", 0.59, 2);

	head = chocolate;

	Donut* bostonCrm = new Donut("Boston Crm", 0.69, 2);
//	chocolate->display();
//	bostonCrm->display();

	chocolate->next = bostonCrm;
//	chocolate->display();

	Donut* jelly = new Donut("Jelly", 0.49, 3);
//	jelly->display();
	bostonCrm->next = jelly;
//	bostonCrm->display();
//	jelly->next = chocolate;
	
	cout << "Before Append: " << endl;
//	displayList(chocolate);
	cout << "Size of list: " << sizeOfList(chocolate) << endl;

	Donut* vanilla = new Donut("Vanilla", 0.23, 3);
	appendDonut(head, vanilla);
	cout << "After Append: " << endl;
	displayList(head);

	cout << "After Prepend: " << endl;
	Donut* glazed = new Donut("Glazed", 0.34, 4);
	prependDonut(&head, glazed);
	displayList(head);
	displayList(glazed);

	getchar();
}