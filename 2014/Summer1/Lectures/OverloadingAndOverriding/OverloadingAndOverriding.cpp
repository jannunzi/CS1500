#include <iostream>
#include <string>
using namespace std;

enum EmployeeType {FULLTIME, HOURLY};

// base class
class Employee
{
protected:
	string name;
	string ssn;
	EmployeeType type;
public:
	virtual double getPaycheck() {
		return 0.0;
	}
	double getPaycheck() {
		return 0.0;
	}
	Employee(){}
	Employee(string name)
	{
		setName(name);
	}
	void setName(string);
	// overloading of setName()
	void setName(string title, string name);
	string getName();
	void display()
	{
		cout << "Employee:" << endl;
		cout << name << endl;
	}
};

void Employee::setName(string title, string name)
{
	this->name = title + " " + name;
}

// Employee's setName()
void Employee::setName(string name)
{
//	cout << "Employee's setName() " << name << endl;
	this->name = name;
}

// global setName()
void setName(string name)
{
	cout << "Global setName() " << name << endl;
//	this->name = name;
}

string Employee::getName()
{
	return name;
}


class FulltimeEmployee : public Employee
{
protected:
	double salary;
public:
	double getPaycheck()
	{
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

// derived class
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
	// overloading
	// bob.display("Bob's Info:");
	// bob.display();
	void display(string title)
	{
		cout << title << endl;
		display();
	}
	// overriding parent's display()
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
		return rate * hours;
	}
};

int main()
{
	/*
	HourlyEmployee bob("Bob", 40, 100);
	bob.setHours((float)60);

	setName("ewq");

	Employee alice("Alice");
	alice.setName("Wonderland");
	alice.setName("Dr.", "Alice");

	cout << alice.getName() << endl;

	cout << "Inherited display()" << endl;
	alice.display();
	bob.display("Bob's Info:");
	bob.display();

	Employee e[] = {bob, alice};

	double total = 0.0;
	for (int i = 0; i < 2; i++)
	{
		total += e[i].getPaycheck();
	}

	cout << "Total: " << endl;
	cout << total << endl;
*/
	HourlyEmployee* he = new HourlyEmployee("Alice", 12.23, 34.45);
	FulltimeEmployee* fe = new FulltimeEmployee("Bob", 123321);
	he->display();
	fe->display();

	Employee* e = he;
	e->display();

	Employee* es[] = { he, fe };
	es[0]->display();
	es[1]->display();

	getchar();
}
