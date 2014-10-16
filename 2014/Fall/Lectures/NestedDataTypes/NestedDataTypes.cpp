#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
};

struct Department{
	string name;
	Employee* employee;
};

struct Company {
	string name;
	Department* department;
};

int main() {
	Employee* alice = new Employee();
	alice->name = "Alice Wonderland";
	Department* sales = new Department();
	sales->name = "Sales";
	Company* acme = new Company();
	acme->name = "Acme Inc.";

	sales->employee = alice;
	acme->department = sales;

	cout << alice->name << endl;
	cout << sales->name << endl;
	cout << acme->name << endl;

	cout << sales->employee->name << endl;
	cout << acme->department->name << endl;
	cout << acme->department->employee->name << endl;
}
