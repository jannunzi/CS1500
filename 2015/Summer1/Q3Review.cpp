//
//  main.cpp
//  Q3Review
//
//  Created by Jose Annunziato on 6/24/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string first;
    string last;
public:
    void setFirst(string f) {first = f;}
    string getFirst() { return first; }
    Employee(){}
    Employee(string f, string l)
    {
        setFirst(f);
        // etc...
    }
};

class FullTime : public Employee
{
private:
    float yearlySalary;
public:
    void setYearlySalary(float s)
    {
        this->yearlySalary = s;
    }
    FullTime(){}
    FullTime(string first, string last, float sa)
    : Employee(first, last)
    {
        setYearlySalary(sa);
    }
};

class Department
{
private:
    string name;
    Employee* employees;
public:
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setEmployees(Employee* employees) {
        this->employees = employees;
    }
    Employee* getEmployees() {
        return employees;
    }
    Department(){}
    Department(string name, Employee* employees)
    {
        setName(name);
        setEmployees(employees);
    }
};

class Company
{
private:
    string name;
    Department* departments = NULL; // dynamic array
public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    Company(){
        departments = NULL;
    }
    Company(string name)
    {
        this->setName(name);
    }
    ~Company() {
        cout << "Good bye" << endl;
    }
};

int main(int argc, const char * argv[]) {
    Company acme;
    Company abc("ABC");
}
