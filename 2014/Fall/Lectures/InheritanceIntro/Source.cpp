#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
	string firstName;
	string lastName;
	string ssn;
public:
	void setFirstName(string);
	string getFirstName() {
		return firstName;
	}
	void setLastName(string last) {
		lastName = last;
	}
	string getLastName() {
		return lastName;
	}
	void display() {
		cout << firstName << " " << lastName << endl;
	}
	Employee() {}
	Employee(string ssn, string first, string last) {
		this->ssn = ssn;
		firstName = first;
		lastName = last;
	}
};

void Employee::setFirstName(string first)
{
	this->firstName = first;
}

class FullTimeEmployee : public Employee {
protected:
	double salary;
public:
	FullTimeEmployee(){}
	FullTimeEmployee(string ssn, string first, string last, double salary)
		: Employee(ssn, first, last)
	{
		this->salary = salary;
	}
	void setSalary(double newSalary) {
		this->salary = newSalary;
	}
	double getSalary(){
		return this->salary;
	}
	void display() {
		Employee::display();
		cout << "Salary: $" << salary << endl;
	}
};

class HourlyEmployee : public Employee {
protected:
	double hours;
	double rate;
public:
	HourlyEmployee(){}
	HourlyEmployee(string ssn, string first, string last, double hours, double rate)
		: Employee(ssn, first, last)
	{
		//this->ssn = ssn;
		//this->firstName = first;
		//this->lastName = last;
		this->rate = rate;
		this->hours = hours;
	}
	void display() {
		Employee::display();
		//cout << firstName << " " << lastName << endl;
		cout << "Hours: " << hours << " Rate: " << rate << endl;
	}
};

int main() {
	Employee * alice = new Employee("321123321", "Alice", "Wonderland");
	alice->display();
	HourlyEmployee * he = new HourlyEmployee("234432234", "Bob", "Marley", 40.0, 100.0);
	cout << he->getFirstName() << endl;
	he->display();
	FullTimeEmployee * charlie = new FullTimeEmployee("345543345", "Charlie", "Garcia", 123123);
	charlie->display();
}
