#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string firstName;
	string lastName;
	float salary;
};

struct Company {
	int size;
	int count;
	Employee* employees;
};

void displayEmployee(Employee employee)
{
	cout << employee.firstName << " " << employee.lastName << " $" << employee.salary << endl;
}

void giveRaise(Employee &employee, float percent)
{
	employee.salary = employee.salary * (1 + percent);
	displayEmployee(employee);
}

void giveRaise2(Employee* employee, float percent)
{
	cout << employee << endl;
	(*employee).salary = (*employee).salary * (1 + percent);
}

void giveRaise3(Employee* employee, float percent)
{
	employee->salary = employee->salary * (1 + percent);
}

Employee createEmployee()
{
	Employee newEmployee;
	cout << "Create Employee: " << endl;
	cout << "First Name: ";
	cin >> newEmployee.firstName;
	cout << "Last Name: ";
	cin >> newEmployee.lastName;
	cout << "Salary: ";
	cin >> newEmployee.salary;
	return newEmployee;
}

void displayEmployees(Employee employees[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << employees[i].firstName << endl;
	}
}

void fireEmployee(Employee employees[], int unluckyEmployeeIndex, int size)
{
	for (int i = unluckyEmployeeIndex; i < size - 1; i++)
	{
		employees[i] = employees[i + 1];
	}
}

void hireEmployee(Employee newEmployee, Employee employees[], int count, int size)
{
	if (count < size)
		employees[count] = newEmployee;
}

Employee* growCompany(Employee company[], int oldSize, float percentGrowth)
{
	int newSize = oldSize * (1 + percentGrowth);
	Employee* newCompany = new Employee[newSize];
	for (int i = 0; i < oldSize; i++)
	{
		newCompany[i] = company[i];
	}
	return newCompany;
}

int main()
{
	int count = 123;
	Employee alice = {"Alice", "Wonderland", 321123};
	alice.salary = 100000;
	cout << alice.firstName << endl;
	displayEmployee(alice);

	giveRaise(alice, 0.05);
	displayEmployee(alice);

	giveRaise2(&alice, 0.05);
	displayEmployee(alice);

	giveRaise3(&alice, 0.05);
	displayEmployee(alice);

	Employee bob = {"Bob"};
	bob.lastName = "Marley";
	bob.salary = 1234432;

//	Employee e = createEmployee();
//	displayEmployee(e);

//	giveRaise3(&e, 0.10);
//	displayEmployee(e);

	Employee charlie = {"Charlie", "Garcia", 321123};

	Employee employees[] = { alice, bob, {"asd", "dsa", 123}, charlie };
	displayEmployees(employees, 4);

	fireEmployee(employees, 2, 4);
	displayEmployees(employees, 3);

	Employee dan = { "Daniel", "Craig", 123123 };
	hireEmployee(dan, employees, 3, 4);
	displayEmployees(employees, 4);

	int size;
	count = 4;
	cout << "Size of company: ";
	cin >> size;

	Employee* company = new Employee[size];
	company[0] = alice;
	company[1] = bob;
	company[2] = charlie;
	company[3] = dan;
	displayEmployees(company, size);

	company = growCompany(company, size, 0.10);

	displayEmployees(company, size);

	company[4] = { "Edward", "Norton", 123123 };
	company[5] = { "Frank", "Herbert", 32123};
	displayEmployees(company, 6);


	int* age = new int;
	Employee* newEmployee = new Employee;
	newEmployee->firstName = "New Employee";
	newEmployee->lastName = "Last Name";
	newEmployee->salary = 321123;
	displayEmployee(*newEmployee);

	getchar();
	getchar();
}
