#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	string first;
	string last;
	Employee* left = NULL;
	Employee* right = NULL;
	Employee();
	Employee(string first, string last) {
		this->first = first;
		this->last = last;
	}
	void display() {
		cout << last << " " << first << endl;
	}
};

class EmployeeBinSearchTree {
public:
	Employee* root = NULL;
	EmployeeBinSearchTree(){}
	EmployeeBinSearchTree(Employee* root) {
		this->root = root;
	}
	void displayInOrder() {
		displayInOrder(root);
	}
	void displayInOrder(Employee* root) {
		if (root == NULL)
			return;
		displayInOrder(root->left);
		root->display();
		displayInOrder(root->right);
	}
	void insertInOrder(Employee* newEmployee) {
		insertInOrder(&root, newEmployee);
	}
	void insertInOrder(Employee** root, Employee* newEmployee) {
		if (*root == NULL) {
			*root = newEmployee;
		}
		if (newEmployee->last > root->last) {
			insertInOrder(root->right, newEmployee);
		}
		else if (newEmployee->last < root->last) {
			insertInOrder(root->left, newEmployee);
		}
		else {

		}
	}
};

int main() {
	Employee* d = new Employee("Jack", "Daniel");
	Employee* b = new Employee("Alice", "B");
	Employee* c = new Employee("Bob", "C");
	Employee* a = new Employee("A", "A");
	Employee* e = new Employee("E", "E");
	Employee* f = new Employee("F", "F");
	Employee* g = new Employee("G", "G");

	b->left = a;	b->right = c;
	f->left = e;	f->right = g;
	d->left = b;	d->right = f;

	EmployeeBinSearchTree* tree = new EmployeeBinSearchTree(d);
	tree->displayInOrder();

	Employee* m = new Employee("M", "M");

	tree->insertInOrder(m);
	tree->displayInOrder();
}
