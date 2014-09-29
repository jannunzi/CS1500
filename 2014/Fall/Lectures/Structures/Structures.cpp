#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

struct Date {
	int month;
	int day;
	int year;
};

struct Employee {
	string first;
	string last;
	double salary;
	Date dob;
};

struct Company {
	string name;
	int size;
	Employee* employees;
};

void displayEmployee(Employee employee) {
	cout << showpoint << setprecision(2) << fixed << employee.first << " " << employee.last << " $" << employee.salary << " " << employee.dob.month << "/" << employee.dob.day << "/" << employee.dob.year << endl;
}

void displayAllEmployees(Employee employees[], int size) {
	cout << "All Employees" << endl;
	for (int i = 0; i < size; i++) {
		displayEmployee(employees[i]);
	}
}

void displayCompany(Company company) {
	cout << company.name << endl;
	displayAllEmployees(company.employees, company.size);
}

void giveRaiseToEmployee(Employee &employee, double raise) {
	displayEmployee(employee);
	employee.salary *= 1 + raise / 100.0;
	displayEmployee(employee);
}

int main() {
	Date aDob = {1,2,1970};

	Employee alice;
	alice.first = "Alice";
	alice.last = "Wonderland";
	alice.salary = 100000.00;
	alice.dob = aDob;

	Employee bob = { "Bob", "Marley", 234432.34, {3,4,1958} };

	displayEmployee(alice);
	giveRaiseToEmployee(alice, 10);
	displayEmployee(alice);

	Employee employees[] = {alice, bob};

	displayAllEmployees(employees, 2);

	Company acme = {"Acme", 2, employees};
	displayCompany(acme);
}
