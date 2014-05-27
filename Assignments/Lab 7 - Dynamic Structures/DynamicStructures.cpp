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
};

struct Company {
	Employee president;
	Department* department;
};

void displayEmployee(Employee employee);
void displayDepartment(Department department);
void displayCompany(Company company);
Employee createEmployee();
void addEmployee(Department* department, Employee employee);
void removeEmployee(Department* department, Employee employee);

int main()
{
	Employee ada = {"Ada", "Lovelace", 321123};
	Employee babbage = { "Charlie", "Babbage", 234432 };
	Employee turing = { "Alan", "Turing", 323323 };
	Employee von = { "Von", "Neumann", 432234 };

	Employee employees[] = {ada, babbage, turing};

	Department cs = { "CS", von, employees };

	displayDepartment(cs);

	getchar();
}

void displayEmployee(Employee d) {
	cout << d.firstName << " " << d.lastName << endl;;
}

void displayDepartment(Department department)
{
	cout << department.name << " Department" << endl;
	displayEmployee(department.director);
	int size = sizeof(department.employees) / sizeof(Employee);
	for (int i = 0; i < size; i++)
	{
		displayEmployee(department.employees[i]);
	}
}