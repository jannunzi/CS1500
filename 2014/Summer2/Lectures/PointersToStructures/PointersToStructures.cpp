#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string first;
	string last;
	float salary;
};

struct Company {
	string name;
	int size;
	int maxSize;
	Employee* employees;
};

void giveEmployeeRaise(Employee * e, float percent) {
	e->salary = e->salary * (1 + percent / 100.0);
}

void displayEmployee(const Employee &e) {
	cout << e.first << " " << e.last << " $" << e.salary << endl;
}

void displayEmployee(const Employee * e) {
	cout << (*e).first << " " << e->last << " $" << e->salary << endl;
}

void displayEmployees(Employee employees[], int size) {
	for (int i = 0; i < size; i++) {
		displayEmployee(&employees[i]);
	}
}

void giveAllBonuses(Employee employees[], int size, float bonus) {
	for (int i = 0; i < size; i++) {
		employees[i].salary += bonus;
	}
}

void displayCompany(Company company) {
	cout << "Name: " << company.name << endl;
	cout << "Size: " << company.size << endl;
	cout << "Max:" << company.maxSize << endl;
	displayEmployees(company.employees, company.size);
}

Employee createEmployee(string first, string last, float salary) {
	Employee e = {first, last, salary};
	return e;
}

Employee * createEmployeeByReference(string f, string l, float s) {
	Employee* e = new Employee();
	e->first = f;
	e->last = l;
	e->salary = s;
	return e;
}

void hireEmployee(Company & company, Employee newEmployee) {
	if (company.size < company.maxSize) {
		company.employees[company.size++] = newEmployee;
	}
}

int main() {

	Employee * p2 = new Employee();
	p2->first = "Charlie";
	p2->last = "Garcia";
	p2->salary = 123.32;
	displayEmployee(p2);

	Employee * p3 = p2;

	p2 = new Employee();

	Employee bob = {"Bob", "Marley", 1233212};
	displayEmployee(bob);

	Employee * ptr = &bob;
	cout << ptr << endl;
	(*ptr).salary = 3213213;
	displayEmployee(bob);
	ptr->first = "Robert";
	displayEmployee(bob);
	displayEmployee(&bob);

	Employee alice;
	alice.first = "Alice";
	alice.last = "Wonderland";
	alice.salary = 100000;

	displayEmployee(alice);

	int x = 123;
	cout << x << endl;

	int * p = &x;
	cout << p << endl;

	*p = 234;
	cout << x << endl;

	giveEmployeeRaise(&alice, 5);
	displayEmployee(alice);

	ptr = &alice;
	giveEmployeeRaise(ptr, 5);
	displayEmployee(alice);

	Employee employees[] = { alice, bob, {"Dan", "Rather", 321.23} };
	employees[0] = alice;
	cout << "employees = " << employees << endl;
	cout << "&alice = " << &alice << endl;
	displayEmployees(employees, 3);
	giveAllBonuses(employees, 3, 5000);
	displayEmployees(employees, 3);

	Company acme = { "Acme", 2, 50 };

	Employee * dynamicEmployees = new Employee[acme.maxSize];
	dynamicEmployees[0] = alice;
	dynamicEmployees[1] = bob;

	acme.employees = dynamicEmployees;
	displayCompany(acme);

	Employee ee = createEmployee("Edward", "Norton", 321123);
	displayEmployee(ee);

	ptr = createEmployeeByReference("Frank", "Herbert", 234432);
	displayEmployee(ptr);
	delete ptr;
	ptr = &bob;

	displayCompany(acme);
	hireEmployee(acme, ee);
	displayCompany(acme);

	displayEmployee(acme.employees[0]);
	displayEmployee(acme.employees[1]);
	displayEmployee(acme.employees[2]);
}
