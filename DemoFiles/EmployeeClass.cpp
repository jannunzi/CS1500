//
//  main.cpp
//  EmployeeClass
//
//  Created by Jose Annunziato on 6/15/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// Employee is an abstraction of all Employees
// Employee is a Generalization of all Employees
// Base class
// Parent class
// Super class
class Employee
{
protected: // access modifier
    // public: accessible to all
    // private: accessible only to member functions/methods
    // protected: accessible to member functions and subclasses

    // all common properties of all types of employees:
    string first;
    string last;
    string ssn;
    string dob;
    string doh;
public:
    void setFirst(string first)
    {
        this->first = first;
    }
    void setLast(string last)
    {
        this->last = last;
    }
    void setSsn(string ssn)
    {
        this->ssn = ssn;
    }
    Employee() : Employee("","")//,0)
    {
    }
    Employee(string first, string last)//, float salary)
    {
        this->setFirst(first);
        this->setLast(last);
//        this->setSalary(salary);
    }
    void display()
    {
        cout << "First: " << first << endl;
        cout << "Last: " << last << endl;
    }
};

class HourlyEmployee : public Employee
{
private:
    float hours;
    float rate;
public:
    void setHours(float hours) { this->hours = hours; }
    void setRate(float rate) { this->rate = rate; }
    HourlyEmployee(string first, string last, float hours, float rate)
    : Employee(first, last)
    {
        this->setHours(hours);
        this->setRate(rate);
    }
    float getWeeklyPay()
    {
        return hours * rate;
    }
    void display()
    {
        Employee::display();
        cout << "Hours: " << hours<< endl;
        cout << "Rate: " << rate << endl;
        cout << "Week Pay: " << getWeeklyPay()<< endl;
    }
};

// special case of an Employee
// FullTimeEmployee is a specialization of Employee
// Derived class    Base - Derived
// Child class      Parent - Child
// Sub class        Super - Sub
class FullTimeEmployee : public Employee // is an Employee, inheriting from Employee
{
private:
    float salary;
public:
    // public API (Application Programming Interface)
    void setSalary(float s)
    {
        if(s >= 0)
            salary = s;
    }
    FullTimeEmployee()
    {
    }
    FullTimeEmployee(string first, string last, float salary) : Employee(first, last)
    {
        setSalary(salary);
    }
    float getWeeklyPay()
    {
        return salary / 52;
    }
};

int main(int argc, const char * argv[]) {
    Employee* e = new Employee();
//    e->setSalary(20000);
    e->setFirst("Alice");
    e->setLast("Wonderland");
    e->display();
    
    Employee* b = new Employee("Bob", "Marley");//, -30000);
    b->display();
    
    FullTimeEmployee* charlie = new FullTimeEmployee("Charlie", "Garcia", 4000);
    charlie->setSalary(40000);
    charlie->display();
    
    HourlyEmployee* dan = new HourlyEmployee("Dan", "Akroyd", 40, 1000);
    dan->display();
}
