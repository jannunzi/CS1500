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

	void insertAtPosition(int position, Employee * employee) {
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

	void hire(Employee * employee) {
		if (head == NULL && tail == NULL) {
			head = employee;
			tail = employee;
			return;
		}
		tail->next = employee;
		employee->prev = tail;
		tail = employee;
	}

	void fireById(int id) {
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
};

int main() {

}
