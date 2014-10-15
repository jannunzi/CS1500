#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
	float salary;
};

Employee createEmployee(string name, float salary) {
	if (salary < 0)
		salary = 16000;

	Employee e = { name, salary };
	return e;
}

void displayEmployee(Employee e)
{
	cout << e.name << " $" << e.salary << endl;
}

//int main() {
//	Employee alice;
//	alice.name = "Alice";
//	alice.salary = -234432;
//
//	Employee bob = {"Bob", -543345};
//
//	displayEmployee(alice);
//	displayEmployee(bob);
//
//	Employee charlie = createEmployee("Charlie", -432234);
//	displayEmployee(charlie);
//}
