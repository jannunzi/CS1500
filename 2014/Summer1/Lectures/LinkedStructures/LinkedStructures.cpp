#include <iostream>
#include <string>
using namespace std;

struct Employee
{
	string firstName;
	string lastName;
	double salary;
	Employee(string firstName, string lastName, double salary)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->salary = salary;
	}
	void display()
	{
		cout << this << " Employee: " << firstName << " " << lastName << " $" << salary << endl;
	}
};

struct Department
{
	string name = "Unknown";
	Employee* employee = NULL;
	Department();
	Department(string name);
	void display();
};

struct Company
{
	string name;
	Department* department = NULL;
	Company(){}
	Company(string name) {
		this->name = name;
	}
	void display() {
		cout << "Company: " << name << endl;
		if (department != NULL)
			department->display();
	}
};

void Department::display()
{
	cout << "Department: " << name << endl;
	if (employee != NULL)
		employee->display();
}
Department::Department() {}
Department::Department(string name)
{
	this->name = name;
}

int main()
{
	Department sales;
	Department hr("Human Resources");

	sales.display();
	hr.display();

	Department* engineering = new Department("Engineering");
	engineering->display();

	Company* acme = new Company("Acme");
	acme->department = engineering;
	acme->display();
	acme->department->display();

	Employee* alice = new Employee("Alice", "Wonderland", 3211233.0);
	engineering->employee = alice;
	alice->display();

	acme->display();

	cout << "===========" << endl;

	Company* abc = new Company("ABC");
	abc->display();
	Department* architects = new Department("Architects");
	abc->department = architects;
	abc->display();
	Employee* ada = new Employee("Ada", "Lovelace", 3211233.0);
	architects->employee = ada;
	abc->display();

	getchar();
}
