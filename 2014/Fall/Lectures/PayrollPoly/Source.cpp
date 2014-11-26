#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
	string name;
public:
	Employee(){}
	Employee(string name){
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return this->name;
	}
	void display() {
		cout << "Name: " << name << endl;
	}
	virtual double getWeeklyPay() = 0;
};

class FullTimeEmployee : public Employee {
protected:
	double yearlySalary;
public:
	FullTimeEmployee(){}
	FullTimeEmployee(string name, double salary)
		: Employee(name)
	{
		setYearlySalary(salary);
	}
	void setYearlySalary(double salary)
	{
		this->yearlySalary = salary;
	}
	double getYearlySalary()
	{
		return this->yearlySalary;
	}
	double getWeeklyPay()
	{
		return yearlySalary / 52.0;
	}
	void display() {
		Employee::display();
		cout << "Salary: " << yearlySalary << endl;
		cout << "Wk Pay: " << getWeeklyPay() << endl;
		cout << "---" << endl;
	}
};

class HourlyEmployee : public Employee
{
protected:
	double hours;
	double rate;
public:
	HourlyEmployee(){}
	HourlyEmployee(string name, double h, double r)
		: Employee(name)
	{
		setHours(h);
		setRate(r);
	}
	void setHours(double h)
	{
		hours = h;
	}
	void setRate(double r)
	{
		rate = r;
	}
	double getHours(){ return hours; }
	double getRate(){ return rate; }
	double getWeeklyPay() {
		return rate * hours;
	}
	void display() {
		Employee::display();
		cout << "Hours: " << hours << endl;
		cout << "Rate: " << rate << endl;
		cout << "Wk Pay:" << getWeeklyPay() << endl;
		cout << "---" << endl;
	}
};

int main() {
	HourlyEmployee * h1 = new HourlyEmployee("HE1", 40.0, 20.0);
	HourlyEmployee * h2 = new HourlyEmployee("HE2", 40.0, 40.0);
	HourlyEmployee * h3 = new HourlyEmployee("HE3", 40.0, 80.0);

	HourlyEmployee * hs[] = { h1, h2, h3 };
	//for (int h = 0; h < 3; h++)
	//{
	//	hs[h]->display();
	//}

	FullTimeEmployee * f1 = new FullTimeEmployee("FT1", 50000);
	FullTimeEmployee * f2 = new FullTimeEmployee("FT2", 75000);
	FullTimeEmployee * f3 = new FullTimeEmployee("FT3", 100000);
	FullTimeEmployee * f4 = new FullTimeEmployee("FT4", 125000);
	FullTimeEmployee * f5 = new FullTimeEmployee("FT5", 250000);

	FullTimeEmployee * fs[] = {f1, f2, f3, f4, f5};

	//for (int f = 0; f < 5; f++)
	//{
	//	fs[f]->display();
	//}

	//h1->display();
	//Employee * e = h1;
	//e->display();

	//f1->display();
	//e = f1;
	//e->display();

	Employee * es[] = {h1, h2, h3, f1, f2, f3, f4, f5};
	for (int e = 0; e < 8; e++)
	{
//		es[e]->display();
		cout << es[e]->getWeeklyPay() << endl;
	}
}
