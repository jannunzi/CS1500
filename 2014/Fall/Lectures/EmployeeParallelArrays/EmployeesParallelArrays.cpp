#include <iostream>
#include <string>
using namespace std;

void displayEmployee(int index, int ids[], string first[], double salaries[]) {
	if (index == -1) {
		cout << "Not Found" << endl;
		return;
	}
	cout << ids[index] << " " << first[index] << " $" << salaries[index] <<  endl;
}

void displayAllEmployees(int ids[], string first[], double salaries[], int count) {
	for (int i = 0; i < count; i++) {
		displayEmployee(i, ids, first, salaries);
	}
}

int searchEmployeesByFirstName(string needle, string first[], int count) {
	for (int i = 0; i < count; i++)
	{
		if (needle == first[i])
		{
			return i;
		}
	}
	return -1;
}

int searchEmployeesById(int needle, int ids[], int count) {
	for (int i = 0; i < count; i++)
	{
		if (needle == ids[i])
		{
			return i;
		}
	}
	return -1;
}

const int EMPLOYEE_COUNT = 4;

int main() {
	int ids[] = { 123, 234, 345, 456 };
	string first[] = { "Alice", "Bob", "Charlie", "Dan" };
	double salaries[] = { 765.67, 654.65, 543.45, 432.34 };

	displayEmployee(2, ids, first, salaries);
	cout << "\nDisplay All Employees" << endl;
	displayAllEmployees(ids, first, salaries, EMPLOYEE_COUNT);

	cout << "\nLinear Search By Id" << endl;
	int foundIndex = searchEmployeesById(2346, ids, EMPLOYEE_COUNT);
	if (foundIndex != -1) {
		displayEmployee(foundIndex, ids, first, salaries);
	}
	else {
		cout << "Not Found" << endl;
	}

	cout << "\nLinear Search By First Name" << endl;
	foundIndex = searchEmployeesByFirstName("Ben", first, EMPLOYEE_COUNT);
	displayEmployee(foundIndex, ids, first, salaries);
}
