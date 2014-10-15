#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
	float salary;
};

void displayEmployee(const Employee *e)
{
	cout << e->name << "\t$" << e->salary << endl;
}

void giveRaise(Employee *e, int amount) {
	e->salary += amount;
}

Employee * createEmployee(string name, float salary) {
	Employee* newEmployee = new Employee();
	newEmployee->name = name;
	newEmployee->salary = salary;
	return newEmployee;
}

int main() {
	Employee alice;
	alice.name = "Alice";

	Employee * employee = new Employee();
	employee->name = "Bob";
	delete employee;

	employee = new Employee();
	employee->name = "Charlie";


	//int a = 123;
	//int* intPtr = &a;
	//cout << "a = " << a << endl;
	//cout << intPtr << endl;
	//*intPtr = 234;
	//cout << "a = " << a << endl;

	Employee dan;
	dan.name = "Daniel";
	dan.salary = 10000;
	cout << "$" << dan.salary << endl;

	Employee * e;

	e = &dan;

	dan.salary = 20000;
	cout << "$" << dan.salary << endl;

	(*e).salary = 30000;
	cout << "$" << dan.salary << endl;

	e->salary = -40000;
	cout << "$" << dan.salary << endl;

	int *a = new int[10];

	Employee *es = new Employee[10];

	es[0] = alice;
	es[1] = dan;

	displayEmployee(&dan);
	giveRaise(&dan, 10000);
	displayEmployee(&dan);


	Employee* ee = createEmployee("Edward", 20000);

	displayEmployee(ee);
}
