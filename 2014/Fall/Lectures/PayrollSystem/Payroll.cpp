#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string first;
	string last;
	double salary;
};

struct Payroll {
	Employee * employees;
	int size;
};

Employee * promptForNewEmployee() {
	cout << "Create Employee" << endl;
	Employee * newEmployee = new Employee();
	cout << "First Name: ";
	cin >> newEmployee->first;
	cout << "Last Name: ";
	cin >> newEmployee->last;
	cout << "Salary: $";
	cin >> newEmployee->salary;

	return newEmployee;
}

void displayEmployee(Employee * e) {
	cout << "Employee: " << e->first << " " << e->last <<  " $" << e->salary << endl;
}

void addEmployeeToPayroll(Employee * employee, Payroll * payroll, int id) {
	payroll->employees[id] = *employee;
}

void displayPayroll(Payroll * payroll) {
	for (int i = 0; i < payroll->size; i++)
	{
		displayEmployee(&payroll->employees[i]);
	}
}

void givePayrollRaise(Payroll * payroll, float percentage) {
	percentage = percentage / 100.0;
	for (int i = 0; i < payroll->size; i++) {
		Employee *employee = &payroll->employees[i];
		employee->salary *= 1 + percentage;
		cout << employee->salary << endl;
	}
}

float calculatePayout(Payroll * payroll) {
	float total = 0;
	for (int i = 0; i < payroll->size; i++) {
		total += payroll->employees[i].salary;
	}
	return total;
}

int main() {

	int size;
	cout << "Size of company: ";
	cin >> size;

	Payroll * payroll = new Payroll();
	payroll->employees = new Employee[size];
	payroll->size = size;

	for (int e = 0; e < size; e++) {
		Employee * employee = promptForNewEmployee();
		addEmployeeToPayroll(employee, payroll, e);
	}
	displayPayroll(payroll);
	givePayrollRaise(payroll, 5.0);
	displayPayroll(payroll);
	float total = calculatePayout(payroll);
	cout << "Total: " << total << endl;
}
