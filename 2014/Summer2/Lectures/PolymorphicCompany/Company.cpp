#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
	string first;
	string last;
	int type;
public:
	Employee* left = NULL;
	Employee* right = NULL;
	Employee(){}
	Employee(string f, string l) {
		this->first = f;
		this->last = l;
	}
	virtual void display() {
		cout << "Base" << endl;
		cout << first << " " << last << endl;
	}
};

class HourlyEmployee : public Employee {
protected:
	float hours, rate;
public:
	HourlyEmployee(){}
	HourlyEmployee(string f, string l, float h, float r)
		: Employee(f, l) {
		hours = h;
		rate = r;
		type = 1;
	}
	void display() {
		cout << "Hourly Employee" << endl;
		Employee::display();
		cout << "Hours: " << hours << "\tRate: $" << rate << endl;
	}
};

class FullTimeEmployee : public Employee {
protected:
	float salary;
public:
	FullTimeEmployee(){}
	FullTimeEmployee(string f, string l, float s)
		: Employee(f, l) {
		salary = s;
		type = 2;
	} 
	void display() {
		cout << "Fulltime Employee" << endl;
		Employee::display();
		cout << salary << endl;
	}
};

class Company {
protected:
	Employee* root = NULL;
private:
	void displayByLastName(Employee* root) {
		if (root == NULL) return;
		displayByLastName(root->left);
		root->display();
		displayByLastName(root->right);
	}
	void insertBinTree(Employee** root, Employee* newEmployee) {

	}
public:
	Company(){}
	Company(Employee* root) {
		this->root = root;
	}
	void displayByLastName() {
		displayByLastName(root);
	}
	void hire(Employee* newEmployee) {
		insertBinTree(&root, newEmployee);
	}
	void fire(Employee* poorEmployee) {

	}
};

int main() {
	FullTimeEmployee* f1 = new FullTimeEmployee("F1", "L1", 1234);
	FullTimeEmployee* f2 = new FullTimeEmployee("F2", "L2", 2234);
	FullTimeEmployee* f3 = new FullTimeEmployee("F3", "L3", 3234);

	FullTimeEmployee* f4 = new FullTimeEmployee("F4", "L4", 4234);

	HourlyEmployee* h5 = new HourlyEmployee("F5", "L5", 12, 23);
	HourlyEmployee* h6 = new HourlyEmployee("F6", "L6", 22, 23);
	HourlyEmployee* h7 = new HourlyEmployee("F7", "L7", 32, 23);

	Employee* e1 = new Employee("F8","L8");

	f2->left = f1;	f2->right = f3;
	h6->left = h5;	h6->right = h7;
	f4->left = f2;	f4->right = h6;

	h7->right = e1;

	Company* acme = new Company(f4);

	acme->displayByLastName();
}
