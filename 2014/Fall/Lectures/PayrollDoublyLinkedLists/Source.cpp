#include <iostream>
#include <string>
using namespace std;

struct Employee {
	int id;
	string first;
	string last;
	float salary;
	Employee * next = NULL;
	Employee * prev = NULL;

	//Employee(const Employee & other) {

	//	cout << "Copying" << endl;

	//	this->id = 333;// other.id;
	//	this->first = "John";// other.first;
	//	this->last = "Doe";// other.last;
	//	this->salary = other.salary;
	//	this->next = other.next;
	//	this->prev = other.next;
	//}

	Employee(string first, string last, float salary);
	Employee(int id, string first, string last, float salary);
	void display();
};
struct Company {
	Employee * head = NULL;
	Employee * tail = NULL;

	string name;

	Company();
	Company(string name);
	Company(const Company & otherCompany) {

		cout << "Cloning Company" << endl;

		this->name = otherCompany.name;
		
		Employee * current = otherCompany.head;
		while (current != NULL) {
			cout << "Cloning Employee " << current->first << endl;
			Employee * e = new Employee(current->id, current->first, current->last, current->salary);

			this->hire(e);

			current = current->next;
		}

		cout << "\n\n" << endl;
	}

	void insertAtPosition(int position, Employee * employee);
	void hire(Employee * employee);
	void fireById(int id);
	void display();
};

int main() {

	Employee a(123, "Charlie", "Garcia", 22222);
	a.display();

	Employee b = a;
	b.display();
	b.first = "Dan";
	b.display();
	a.display();

	Company c("Acme");
	c.hire(&a);
	c.hire(&b);
	c.display();

	Company d = c;
	d.name = "ABC";
	d.display();

	Employee x(321, "Malcom", "X", 321123);
	d.hire(&x);
	d.display();
	c.display();

	Employee * e = new Employee(123, "Ada", "Lovelace", 321123);

	e->display();

	Company * babadge = new Company("Babadge");
	babadge->hire(e);
	e = new Employee(234, "John", "Von Neuman", 234432);
	babadge->hire(e);
	e = new Employee(345, "Alan", "Turin", 123321);
	babadge->hire(e);

	babadge->display();

	Company * copy;

	copy = babadge;
	copy->display();
	e = new Employee(456, "Stephen", "Hawkin", 65445665);
	copy->hire(e);
	copy->display();

	babadge->display();
}

void Employee::display() {
	cout << id << " " << first << " " << last << " $" << salary << endl;
}

Employee::Employee(string first, string last, float salary) {
	this->first = first;
	this->last = last;
	this->salary = salary;
}

Employee::Employee(int id, string first, string last, float salary) {
	this->id = id;
	this->first = first;
	this->last = last;
	this->salary = salary;
}

void Company::insertAtPosition(int position, Employee * employee) {
	int counter = 0;
	Employee * current = head;
	while (current != NULL) {
		if (counter == position) {
			current->prev->next = employee;
			employee->prev = current->prev;

			current->prev = employee;
			employee->next = current;
		}
		counter++;
		current = current->next;
	}
}

void Company::hire(Employee * employee) {
	if (head == NULL && tail == NULL) {
		head = employee;
		tail = employee;
		return;
	}
	tail->next = employee;
	employee->prev = tail;
	tail = employee;
}

void Company::fireById(int id) {
	if (head == NULL && tail == NULL) {
		cout << "No Employees" << endl;
		return;
	}

	Employee * current = head;
	while (current != NULL) {
		if (current->id == id) {
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			return;
		}
	}
}

Company::Company(){}
Company::Company(string name) {
	this->name = name;
}

void Company::display() {

	cout << "\n\n" << name << endl;

	Employee * c = head;
	while (c != NULL) {
		c->display();
		c = c->next;
	}

	cout << "\n\n" << endl;
}
