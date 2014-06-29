#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
	string ssn;
	string firstName;
	string lastName;
public:
	Employee(){}
	Employee(string ssn, string firstName, string lastName)
	{
		setSsn(ssn);
		setFirstName(firstName);
		setLastName(lastName);
	}
	void setSsn(string ssn) { this->ssn = ssn; }
	void setFirstName(string fName){ this->firstName = fName; }
	void setLastName(string lName){ this->lastName = lName; }
	string getFirstName(){ return this->firstName; }
	string getLastName(){ return this->lastName; }
	string getSsn() { return this->ssn; }
	void display()
	{
		cout << "===================" << endl;
		cout << "Employee: " << endl;
		cout << ssn << " " << firstName << " " << lastName << endl;
	}
	virtual double getMonthlyCheck() = 0;
//	{
//		return 0.0;
//	}
};

class HourlyEmployee : public Employee
{
private:
	double rate;
	double hours;
public:
	HourlyEmployee(){}
	HourlyEmployee(string ssn, string fName, string lName, double rate, double hours)
		: Employee(ssn, fName, lName)
	{
		setHours(hours);
		setRate(rate);
	}
	void setRate(double rate) { this->rate = rate; }
	double getRate() { return this->rate; }
	void setHours(double hours) { this->hours = hours; }
	double getHours(){ return this->hours; }
	double getMonthlyCheck()
	{
		return rate * hours;
	}
	void display()
	{
		Employee::display();
		cout << "HourlyEmployee::rate: " << rate << endl;
		cout << "HourlyEmployee::hours: " << hours << endl;
		cout << "HourlyEmployee::monthlyCheck: " << getMonthlyCheck() << endl;
	}
};

class FullTimeEmployee : public Employee
{
private:
	double salary;
public:
	FullTimeEmployee(string ssn, string f, string l, double salary)
		: Employee(ssn, f, l)
	{
		setSalary(salary);
	}
	void setSalary(double salary) { this->salary = salary; }
	double getSalary() { return this->salary; }
	double getMonthlyCheck()
	{
		return salary / 12.0;
	}
	void display()
	{
		Employee::display();
		cout << "FullTimeEmployee::salary: " << getSalary() << endl;
		cout << "FullTimeEmployee::monthlyCheck: " << getMonthlyCheck()<< endl;
	}
};

int main()
{
//	Employee alice("123321", "Alice", "Wonderland");
	//alice.display();

	HourlyEmployee bob("234432", "Bob", "Marley", 100, 160);
	cout << bob.getLastName() << endl;
	bob.display();

	FullTimeEmployee charlie("345543", "Charlie", "Garcia", 200000);
	charlie.display();

	Employee* employees[] = {&bob, &charlie};
	for (int i = 0; i < 2; i++)
	{
		cout << employees[i]->getMonthlyCheck() << endl;
	}
}