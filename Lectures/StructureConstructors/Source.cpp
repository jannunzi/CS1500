#include <iostream>
using namespace std;

struct Employee
{
	int ssn;
	float salary;
	Employee() {
		cout << "[1]" << endl;
	}
	Employee(int s, float sl)
	{
		cout << "[2]" << endl;
		ssn = s;
		salary = sl;
	}
	Employee(const Employee &otherEmployee)
	{
		cout << "[3]" << endl;
		ssn = otherEmployee.ssn;
		salary = otherEmployee.salary;
	}
};

struct Company
{
	int size;
	int count = 0;
	Employee ** employees;
	Company(int s)
	{
		size = s;
		employees = new Employee*[size];
	}
	Company(){}
};

void  displayEmployee(const Employee* e)
{
	cout << "$" << e->salary << endl;
}

void addEmployee(Company* c, Employee* e)
{
	int index = c->count;
	c->employees[index] = e;
	c->count++;
}

void giveRaise(Employee* e, float percent)
{
//	e.salary = e.salary * (1 + percent);
	e->salary *= (1 + percent);
}

int main()
{
	Employee bob;
	Employee alice = { 1234, 321123.0 };
	displayEmployee(&alice);
	giveRaise(&alice, 0.10);
	displayEmployee(&alice);

	bob = alice;
	displayEmployee(&bob);

	int ewq;
	cin >> ewq;
	Company* acme = new Company(ewq);

	addEmployee(acme, &alice);

	getchar();
}