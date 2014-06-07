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
		cout << this << " Donut:" << endl;
		cout << &name << " Name:  " << name << endl;
		cout << &price << " Price: " << price << endl;
		cout << &age << " Age:   " << age << endl;
		cout << &next << " Next:  " << next << endl;
		cout << "===========================" << endl << endl;
	}
};

struct DonutList
{
	Donut* head;
	string name;
	int length;
	DonutList(){
		head = NULL;
		length = 0;
		name = "New Donut List";
	}
	DonutList(string name)
	{
		head = NULL;
		length = 0;
		this->name = name;
	}
	int size()
	{
		this->length = 0;

		Donut* current = head;
		while (current != NULL)
		{
			length++;
			current = current->next;
		}

		return length;
	}
	void display()
	{
		Donut* current = head;
		int counter = 0;
		while (current != NULL)
		{
			cout << "["<<counter<<"]" << endl;
			current->display();
			current = current->next;
			counter++;
		}
	}
	void append(Donut* newDonut)
	{
		if (head == NULL)
		{
			head = newDonut;
			return;
		}
		Donut* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newDonut;
	}
	void prepend(Donut* donut)
	{
		donut->next = head;
		head = donut;
	}
	Donut* findByName(string name)
	{
		Donut* current = head;
		while (current != NULL)
		{
			if (current->name == name)
			{
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	Donut* findByIndex(int index)
	{
		int counter = 0;
		Donut* current = head;
		while (current != NULL)
		{
			if (counter == index)
			{
				return current;
			}
			current = current->next;
			counter++;
		}
		return NULL;
	}
	void insertAfterIndex(Donut* newDonut, int index)
	{
		if (head == NULL)
		{
			head = newDonut;
			return;
		}
		int counter = 0;
		Donut* current = head;
		while (current != NULL)
		{
			if (counter == index)
			{
				newDonut->next = current->next;
				current->next = newDonut;
			}
			current = current->next;
			counter++;
		}
	}
	void insertBeforeIndex(Donut* newDonut, int index)
	{
		if (index == 0)
		{
			prepend(newDonut);
			return;
		}
		insertAfterIndex(newDonut, index - 1);
	}
	void deleteByIndex(int index)
	{
		if (head == NULL)
		{
			return;
		}
		if (index == 0)
		{
			Donut* tmp = head;
			head = head->next;
			delete tmp;
			return;
		}

		Donut* current = head;
		int counter = 0;
		while (current != NULL) {
			if (counter == index - 1)
			{
				if (current->next == NULL)
				{
					return;
				}
				Donut* tmp = current->next;
				current->next = current->next->next;
				delete tmp;
				return;
			}
			current = current->next;
			counter++;
		}
	}

	void concatenate(DonutList* anotherList)
	{

	}

	void enqueue(Donut* donut) {

	}

	Donut* dequeue()
	{

	}

	void push(Donut* donut)
	{

	}

	Donut* pop()
	{

	}
};

int main()
{
	Donut* chocolate = new Donut("Chocolate", 0.59, 2);
	Donut* bostonCrm = new Donut("Boston Crm", 0.69, 2);
	Donut* jelly = new Donut("Jelly", 0.49, 3);

	DonutList* list = new DonutList("World Runs on Dunkin");

//	cout << list->size() << endl;

	list->append(chocolate);
	list->append(bostonCrm);
//	list->display();

	list->prepend(jelly);

//	list->display();

//	cout << list->size() << endl;

//	Donut* found = list->findByName("Vanilla");
	Donut* found = list->findByIndex(4);
	if (found != NULL)
	{
//		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}



	Donut* glazed = new Donut("Glazed", 1.22, 21);
//	list->display();
	list->insertAfterIndex(glazed, 0);
//	list->display();

	Donut* cherry = new Donut("Cherry", 2.33, 12);
	list->insertBeforeIndex(cherry, 2);
//	list->display();

	list->deleteByIndex(4);
	list->display();

	getchar();
}