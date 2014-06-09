#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string firstName, lastName;
	float salary;
};

struct Department {
	string name;
	Employee director;
	Employee* employees;
	int currentSize;
	int maxSize;
};

void displayEmployee(Employee employee);
void displayDepartment(Department* department);
Employee createEmployee();
void addEmployee(Department* department, Employee employee);

int main()
{
	// create some employees
	Employee ada     = { "Ada", "Lovelace", 325123};
	Employee babbage = { "Charlie", "Babbage", 234432 };
	Employee turing  = { "Alan", "Turing", 323323 };
	Employee von     = { "John", "von Neumann", 432234 };

	displayEmployee(ada);

	// create an array of employees
	Employee* employees = new Employee[10];
	employees[0] = ada;
	employees[1] = babbage;
	employees[2] = turing;
	employees[3] = von;

	// create a "CS" department,
	// employee von is the directory,
	// the employees are the employees listed above,
	// currently has 4 employees,
	// with a max of 10 employees
	Department cs = { "CS", von, employees, 4, 10 };

	displayDepartment(&cs);
	Employee newEmployee = createEmployee();
	addEmployee(&cs, newEmployee);
	displayDepartment(&cs);

	getchar();
	getchar();
}

void addEmployee(Department* department, Employee newEmployee)
{
	if (department->currentSize < department->maxSize)
	{
		department->employees[department->currentSize] = newEmployee;
		department->currentSize++;
	}
}

Employee createEmployee()
{
	Employee newEmployee;
	cout << "\nNew Employee:" << endl;
	cout << "First Name: ";
	cin >> newEmployee.firstName;
	cout << "Last Name: ";
	cin >> newEmployee.lastName;
	cout << "Salary: ";
	cin >> newEmployee.salary;
	return newEmployee;
}

void displayEmployee(Employee d)
{
	cout << d.firstName << " " << d.lastName << " $" << d.salary << endl;
}

void displayDepartment(Department* department)
{
	cout << endl;
	cout << department->name << " Department" << endl;
	cout << "Director: ";
	displayEmployee(department->director);
	for (int i = 0; i < department->currentSize; i++)
	{
		displayEmployee(department->employees[i]);
	}
}
