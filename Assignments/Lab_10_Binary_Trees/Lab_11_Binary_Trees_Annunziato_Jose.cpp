#include <iostream>
#include <string>
using namespace std;

enum Department {
	HR, ENGINEERING, SALES, MARKETING
};

class Employee {
private:
	string firstName;
	string lastName;
	double salary;
	Department department;
public:
	void display()
	{
		cout << lastName << " " << firstName << " $" << salary << endl;
	}
	Employee(){}
	Employee(string fName, string lName, double salary, Department dept)
	{
		setFirstName(fName);
		setLastName(lName);
		setSalary(salary);
		setDepartment(dept);
	}
	void setFirstName(string fName)
	{
		this->firstName = fName;
	}
	void setLastName(string lName)
	{
		this->lastName = lName;
	}
	void setSalary(double salary)
	{
		if (salary > 0)
		{
			this->salary = salary;
		}
	}
	void setDepartment(Department department)
	{
		this->department = department;
	}
	string getFirstName() { return firstName; }
	string getLastName()  { return lastName; }
	double getSalary()    { return salary; }
	Department getDepartment() { return department; }
};

struct EmployeeNode {
	Employee* employee;
	EmployeeNode* left = NULL;
	EmployeeNode* right = NULL;
	EmployeeNode(){}
	EmployeeNode(Employee* employee){
		this->employee = employee;
	}
};

class EmployeeBinarySearchTree {
private:
	EmployeeNode* root = NULL;
	void insert(EmployeeNode* node, EmployeeNode** root);
	void traverseInOrder(EmployeeNode* root);
public:
	void insert(Employee* employee);
	void remove(string lastName);
	Employee* breathFirstSearch(string lastName);
	Employee* depthFirstSearch(string lastName);
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

void EmployeeBinarySearchTree::traverseInOrder(EmployeeNode* root)
{
	if (root != NULL)
	{
		traverseInOrder(root->left);
		root->employee->display();
		traverseInOrder(root->right);
	}
}

void EmployeeBinarySearchTree::traverseInOrder()
{
	traverseInOrder(root);
}

void EmployeeBinarySearchTree::insert(Employee* employee)
{
	EmployeeNode* node = new EmployeeNode(employee);
	if (root == NULL)
	{
		root = node;
		return;
	}
	insert(node, &root);
}

void EmployeeBinarySearchTree::insert(EmployeeNode* node, EmployeeNode** root)
{
	if (*root == NULL)
	{
		*root = node;
		return;
	}
	if (node->employee->getLastName() >= (*root)->employee->getLastName())
	{
		insert(node, &((*root)->right));
	}
	else if (node->employee->getLastName() < (*root)->employee->getLastName())
	{
		insert(node, &((*root)->left));
	}
}

int main()
{
	Employee* alice = new Employee("Alice", "Wonderland", 3211232, ENGINEERING);
	Employee* bob = new Employee("Bob", "Marley", 3211232, MARKETING);

	EmployeeBinarySearchTree* tree = new EmployeeBinarySearchTree();
	tree->insert(alice);
	tree->insert(bob);

	tree->traverseInOrder();
	tree->traversePreOrder();
	tree->traversePostOrder();
}