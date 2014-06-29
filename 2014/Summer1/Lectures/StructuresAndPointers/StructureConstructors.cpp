#include <iostream>
using namespace std;

struct Employee
{
	int ssn;
	float salary;
};

void  displayEmployee(Employee e)
{
	cout << "$" << e.salary << endl;
}

int main()
{
	Employee alice = {1234, 321123.0};
	displayEmployee(alice);

	getchar();
}