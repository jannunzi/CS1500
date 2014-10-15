#include <iostream>
#include <string>
using namespace std;

struct Employee {
	~Employee() {
		cout << "Goodbye from " << name << endl;
	}
	Employee() {
		cout << "Default Constructor (No Arguments)" << endl;
	}
	Employee(string n, float s) {
		cout << "All Argument Constructor" << endl;
		setName(n);
		//name = n;
		setSalary(s);
		//if (s < 16000)
		//	s = 16000;
		//salary = s;
	}
	void setSalary(float s) {
		if (s < 16000)
			s = 16000;
		salary = s;
	}
	float getSalary() {
		return salary;
	}
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
private:
	string name;
	float salary;
};

int main() {
	Employee alice = {"alice", -123};
	Employee bob;

	cout << alice.getName() << endl;
	cout << alice.getSalary() << endl;

	Employee * charlie = new Employee();
	charlie->setName("Charlie");
	Employee * dan = new Employee("Dan", 234432);
	cout << dan->getName() << " $" << dan->getSalary() << endl;

	//delete charlie;
	//delete dan;

	bob.setSalary(-234);
	bob.setName("Bob");
	cout << bob.getSalary() << endl;
}
