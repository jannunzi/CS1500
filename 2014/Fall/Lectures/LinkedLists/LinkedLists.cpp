#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
	double salary;
	Employee(string name, double salary) {
		this->name = name;
		this->salary = salary;
		this->next = NULL;
	}
	void display() {
		cout << this->name << " $" << this->salary << endl;
	}
	// etc...

	Employee * next = NULL;
};

void displayList(Employee * head) {
	Employee * current = head;
	while (current != NULL) {
		current->display();
		current = current->next;
	}
}

void prepend(Employee * *head, string name, double salary) {
	Employee * ne = new Employee(name, salary);
	ne->next = *head;
	*head = ne;

}

int main() {
	Employee * alice = new Employee("Alice", 321321.32);
	Employee * bob = new Employee("Bob", 211212.221);
	Employee * charlie = new Employee("Charlie", 111212.221);

	alice->next = bob;
	bob->next = charlie;

	alice->display();
	bob->display();
	charlie->display();

	alice->next->display();
	alice->next->next->display();

	// prepending to a list
	Employee * head = alice;

	Employee * emp = new Employee("Emp A", 123);
	emp->next = head;
	head = emp;

	emp = new Employee("Empl B", 42234);
	emp->next = head;
	head = emp;

	emp = new Employee("Emp C", 432233);
	emp->next = head;
	head = emp;

	// Appending to a list
	Employee * tail = charlie;

	emp = new Employee("D", 333);
	tail->next = emp;
	tail = emp;

	emp = new Employee("E", 222);
//	emp->next = NULL;
	tail->next = emp;
	tail = emp;

	// 
	cout << "Iterate over a list" << endl;
	Employee * current = head;
	current->display();

	current = current->next;
	current->display();

	current = current->next;
	current->display();

	current = current->next;
	current->display();

	cout << "\nDisplay the whole list" << endl;
	displayList(head);
	//current = head;
	//while (current != NULL) {
	//	current->display();
	//	current = current->next;
	//}


	prepend(&head, "XYZ", 32112);
	cout << "\nAfter Prepend" << endl;
	displayList(head);
}
