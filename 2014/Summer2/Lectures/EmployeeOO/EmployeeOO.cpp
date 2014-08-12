#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
	string first;
	string last;
public:
	Employee(){}
	Employee(string f, string l) {
		first = f;
		last = l;
	}
	void display() {
		cout << first << " " << last << endl;
	}
	virtual float getWeeklyPaycheck() = 0;
};

class HourlyEmployee : public Employee {
protected:
	float rate;
	float hours;
public:
	HourlyEmployee(){}
	HourlyEmployee(string f, string l, float r, float h)
		: Employee(f, l) {
		rate = r;
		hours = h;
	}
	void display() {
		Employee::display();
		cout << "Rate: $" << rate << "/hour" << endl;
		cout << "Hours: " << hours << endl;
		cout << getWeeklyPaycheck() << endl;
	}
	float getWeeklyPaycheck() {
		return rate * hours;
	}
};

class CommissionEmployee : public Employee {

};

class FullTimeEmployee : public Employee {
protected:
	float salary;
public:
	FullTimeEmployee(){}
	FullTimeEmployee(string f, string l, float s)
		: Employee(f, l) {
		salary = s;
	}
	void display() {
		Employee::display();
		cout << "Salary: " << salary << endl;
		cout << getWeeklyPaycheck() << endl;
	}
	float getWeeklyPaycheck() {
		return salary / 52.0;
	}
};

int main() {
//	Employee* alice = new Employee("Alice", "Wonderland");
//	alice->display();

	HourlyEmployee* bob = new HourlyEmployee("Bob", "Dylan", 100.0, 40.0);
	bob->display();

	HourlyEmployee* dan = new HourlyEmployee("Dan", "Akroid", 120.0, 40.0);
	dan->display();

	FullTimeEmployee* charlie = new FullTimeEmployee("Charlie", "Garcia", 200000.0);
	charlie->display();

	FullTimeEmployee* ed = new FullTimeEmployee("Edward", "Norton", 2000000.0);
	ed->display();

	HourlyEmployee* hourly[] = { dan, bob };
	FullTimeEmployee* full[] = { charlie, ed };

	float total = 0;
	for (int h = 0; h < 2; h++) {
		total += hourly[h]->getWeeklyPaycheck();
	}
	for (int f = 0; f < 2; f++) {
		total += full[f]->getWeeklyPaycheck();
	}
	cout << "Total Weekly Pay: " << total << endl;


	total = 0.0;
	Employee* employees[] = {dan, bob, charlie, ed};
	for (int e = 0; e < 4; e++) {
		total += employees[e]->getWeeklyPaycheck();
	}
	cout << "Total Weekly Pay: " << total << endl;
}