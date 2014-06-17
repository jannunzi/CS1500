#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
	string name;
	string ssn;
public:
	virtual double getPaycheck() = 0;
//	virtual double getPaycheck() {
//		cout << "Employee getPaycheck()" << endl;
//		return 0.0;
//	}
	Employee(){}
	Employee(string name)
	{
		setName(name);
	}
	void setName(string)
	{
		this->name = name;
	}
	string Employee::getName()
	{
		return name;
	}
	void display()
	{
		cout << "Employee:" << endl;
		cout << name << endl;
	}
};

class FulltimeEmployee : public Employee
{
protected:
	double salary;
public:
	double getPaycheck()
	{
		cout << "FTE getPaycheck()" << endl;
		return salary / 52.0;
	}
	FulltimeEmployee(string name, double salary)
		: Employee(name)
	{
		setSalary(salary);
	}
	void setSalary(double s)
	{
		salary = s;
	}
	void display()
	{
		cout << "FulltimeEmployee" << endl;
		Employee::display();
		cout << "salary: " << salary << endl;
		cout << "================" << endl;
	}
};

class HourlyEmployee : public Employee
{
protected:
	double hours;
	double rate;
public:
	HourlyEmployee(string name, double hours, double rate)
		: Employee(name)
	{
		this->name = name;
		setHours(hours);
		setRate(rate);
	}
	void setRate(double rate){ this->rate = rate; }
	void setHours(double hours) {
		//		cout << "setHours(double)" << endl;
		this->hours = hours;
	}
	void display()
	{
		cout << "Hourly Employee" << endl;
		Employee::display();
		cout << this->rate << endl;
		cout << hours << endl;
		cout << "================" << endl;
	}
	double getPaycheck()
	{
		cout << "HE getPaycheck()" << endl;
		return rate * hours;
	}
};

int main()
{
	HourlyEmployee* he = new HourlyEmployee("Alice", 12.23, 34.45);
	FulltimeEmployee* fe = new FulltimeEmployee("Bob", 123321);
	he->display();
	fe->display();

	Employee* e = he;
	cout << e->getPaycheck() << endl;
	e = fe;
	cout << e->getPaycheck() << endl;

	Employee* es[] = { he, fe };
	es[0]->display();
	es[1]->display();
	/*
	*/
}