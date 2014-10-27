#include <iostream>
#include <string>
using namespace std;

struct Employee {
	int id;
	string first;
	string last;
	float salary;
	Employee * next = NULL;
	Employee(string first, string last, float salary) {
		this->first = first;
		this->last = last;
		this->salary = salary;
	}
	Employee(int id, string first, string last, float salary) {
		this->id = id;
		this->first = first;
		this->last = last;
		this->salary = salary;
	}
	void display() {
		cout << id << " " << first << " " << last << " $" << salary << endl;
	}
};

struct Company {
	Employee * head = NULL;
	Employee * tail = NULL;

	// appends new employee to bottom of list
	void hire(Employee * employee) {
		if (head == NULL && tail == NULL) {
			head = employee;
			tail = employee;
			return;
		}

		tail->next = employee;
		tail = employee;
	}
	void fireById(int id) {
		if (head == NULL && tail == NULL) {
			cout << "No Employees" << endl;
			return;
		}

		Employee * current = head;
		Employee * previous = current;
		while (current != NULL) {
			if (id == current->id) {
				//previous->display();
				//current->display();

				if (current == head) {
					head = current->next;
					delete current;
					return;
				}

				if (current == tail) {
					tail = previous;
					tail->next = NULL;
					delete current;
					return;
				}

				previous->next = current->next;
				delete current;

				return;
			}
			previous = current;
			current = current->next;
		}
		cout << "Employee not in company" << endl;
	}
	void display() {
		Employee * current = head;
		while (current != NULL) {
			current->display();
			current = current->next;
		}
	}
};

int main() {

	Company * acme = new Company();

	acme->fireById(123);

	Employee * ne = new Employee(123, "Frank", "Herbert", 3333);
	acme->hire(ne);
	ne = new Employee(234, "Gregory", "Peck", 3333);
	acme->hire(ne);
	ne = new Employee(345, "Humpfrey", "Bogart", 3333);
	acme->hire(ne);
	acme->display();

	cout << "=========" << endl;

	acme->fireById(345);
	acme->display();

	cout << "=========" << endl;


	Employee * emp = new Employee("Alice", "Wonderland", 321123.32);
	Employee * head = emp;
	Employee * tail = emp;

	// prepending

	emp = new Employee("Bob", "Marley", 234432.43);
	emp->next = head;
	head = emp;

	emp = new Employee("Charley", "Garcia", 123321.34);
	emp->next = head;
	head = emp;

	// appending

	emp = new Employee("Daniel", "Craig", 3333);
	tail->next = emp;
	tail = emp;

	emp = new Employee("Edward", "Norton", 444);
	tail->next = emp;
	tail = emp;

	float payroll = 0;
	Employee * current = head;
	cout << current->salary << endl;
	cout << current->next->salary << endl;

	while (current != NULL) {
		payroll += current->salary;
		current = current->next;
	}

	cout << payroll << endl;
}
