#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string first;
	string last;
	Employee() { // default constructor
		first = "First";
		last = "Last";
		salary = 10.0;
		cout << "Constructor" << endl;
	}
	Employee(string f, string l, float s) {
		first = f;
		last = l;
		setSalary(s);
	}
	Employee(string first, string last) {
		this->first = first;
		this->last = last;
		salary = 10.0;
	}
	~Employee() {
		cout << first << " says Good Bye" << endl;
	}
	void setSalary(float s) {
		if (s >= 10.0) {
			salary = s;
		}
		else {
			salary = 10.0;
		}
	}
	float getSalary() {
		return salary;
	}
	void display() {
		cout << first << " " << last << " $" << salary << endl;
	}
private:
	float salary;
};

void displayEmployee(Employee e) {

}

int main() {
	Employee alice = {"Alice", "Wonderland", -123.32f};
	alice.display();

	alice.setSalary(-125.32);
	alice.display();

	Employee bob("Bob", "Marley", 21.2);
	bob.display();

	Employee charlie("Chalie", "Garcia");
	charlie.display();

	cout << bob.getSalary() << endl;

	Employee* ptr = &alice;
	ptr = &bob;
	ptr = &charlie;

	ptr->setSalary(123.32);
	ptr->display();

	ptr = &bob;
	ptr->display();

	ptr = new Employee("Dan", "Akroid", 234.43);
	ptr->display();
	
	delete ptr;

	ptr = &alice;
	ptr->display();
}
