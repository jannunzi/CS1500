#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	string name;
	Employee(){}
	Employee(string name){ this->name = name; }
	void display(){
		cout << "Employee: " << endl;
		cout << "Name: " << name << endl;
	}
	// pure virtual
	virtual double getWeeklyPayCheck() = 0;
};

class CommisionEmployee : public Employee
{
public:
	int quantity, unitCommision;
	CommisionEmployee(string name, int q, int u)
		: Employee(name)
	{
		quantity = q;
		unitCommision = u;
	}
	double getWeeklyPayCheck() {
		return quantity * unitCommision;
	}
};

class HourlyEmployee : public Employee
{
public:
	double hours, rate;
	HourlyEmployee(){}
	HourlyEmployee(string n, double h, double r)
		: Employee(n)
	{
		name = n;
		cout << this->name << endl;
		rate = r; hours = h;
	}
	void display()
	{
		cout << "HourlyEmployee:" << endl;
		Employee::display();
		cout << "Rate: " << rate << endl;
		cout << "Hours: " << hours << endl;
		cout << "============" << endl;
	}
	double getWeeklyPayCheck()
	{
		cout << "HourlyEmployee.getWeeklyPayCheck()" << endl;
		return hours * rate;
	}
};

class FullTimeEmployee : public Employee
{
public:
	double salary;
	FullTimeEmployee(){}
	FullTimeEmployee(string name, double salary)
		: Employee(name)
	{
		this->salary = salary;
	}
	void display()
	{
		cout << "FullTimeEmployee" << endl;
		Employee::display();
		cout << "Salary: " << salary << endl;
		cout << "============" << endl;
	}
	double getWeeklyPayCheck()
	{
		cout << "FullTimeEmployee.getWeeklyPayCheck()" << endl;
		return salary / 52.0;
	}
};

int main()
{
	HourlyEmployee* alice = new HourlyEmployee("Alice", 40, 100);
	alice->display();
	cout << alice->getWeeklyPayCheck() << endl;

	FullTimeEmployee* bob = new FullTimeEmployee("Bob", 120000);
	bob->display();
	cout << bob->getWeeklyPayCheck() << endl;

	Employee* employee = alice;
	employee->display();
	employee = bob;
	employee->display();

	cout << employee->getWeeklyPayCheck() << endl;

	CommisionEmployee* charlie = new CommisionEmployee("Charlie", 123, 234);

	Employee* payroll[] = {alice, bob, charlie};
	double total = 0.0;
	for (int i = 0; i < 3; i++)
	{
		employee = payroll[i];
		total += employee->getWeeklyPayCheck();
	}
	cout << total << endl;
}
