#include <iostream>
#include <string>
using namespace std;

enum DepartmentType
{
	HR, ENGINEERING, SALES, MARKETING
};

class Employee
{
private:
	string firstName;
	string lastName;
	double salary;
	DepartmentType departmentType;
public:
	void display()
	{
		cout << firstName << " " << lastName << " $" << salary << endl;
	}
	Employee(){}
	Employee(string fName, string lName, double salary, DepartmentType dept)
	{
		setFirstName(fName);
		setLastName(lName);
		setSalary(salary);
		setDepartmentType(dept);
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
	void setDepartmentType(DepartmentType departmentType)
	{
		this->departmentType = departmentType;
	}
	string getFirstName() { return firstName; }
	string getLastName()  { return lastName; }
	double getSalary()    { return salary; }
	DepartmentType getDepartmentType() { return departmentType; }
};

struct EmployeeNode
{
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
	void traversePreOrder(EmployeeNode* root);
	void traversePostOrder(EmployeeNode* root);
	Employee* breadthFirstSearch(string firstName, EmployeeNode* root);
	Employee* depthFirstSearch(string firstName, EmployeeNode* root);
public:
	void insert(Employee* employee);
	void remove(string firstName);
	Employee* breadthFirstSearch(string firstName);
	Employee* depthFirstSearch(string firstName);
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

void EmployeeBinarySearchTree::traversePreOrder(EmployeeNode* root)
{
	if (root != NULL)
	{
		root->employee->display();
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}
}

void EmployeeBinarySearchTree::traversePreOrder()
{
	traversePreOrder(root);
}

void EmployeeBinarySearchTree::traversePostOrder(EmployeeNode* root)
{
	if (root != NULL)
	{
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		root->employee->display();
	}
}

void EmployeeBinarySearchTree::traversePostOrder()
{
	traversePostOrder(root);
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
	if (node->employee->getFirstName() >= (*root)->employee->getFirstName())
	{
		insert(node, &((*root)->right));
	}
	else if (node->employee->getFirstName() < (*root)->employee->getFirstName())
	{
		insert(node, &((*root)->left));
	}
}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName, EmployeeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (firstName == root->employee->getFirstName())
	{
		return root->employee;
	}
	else if (firstName > root->employee->getFirstName())
	{
		return depthFirstSearch(firstName, root->right);
	}
	else if (firstName < root->employee->getFirstName())
	{
		return depthFirstSearch(firstName, root->left);
	}
	return NULL;
}
Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName)
{
	return depthFirstSearch(firstName, root);
}

Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName)
{
	return root->right->employee;
}

int main()
{
	Employee* alice		= new Employee("Alice", "Wonderland", 3211232, ENGINEERING);
	Employee* bob		= new Employee("Bob", "Marley", 3211232, MARKETING);
	Employee* charlie	= new Employee("Charlie", "Gargia", 3211232, MARKETING);
	Employee* dan		= new Employee("Daniel", "Craig", 123123, HR);
	Employee* edward	= new Employee("Edward", "Norton", 21211212, ENGINEERING);
	Employee* frank		= new Employee("Frank", "Herbert", 233223, SALES);
	Employee* gregory	= new Employee("Gregory", "Peck", 344334, MARKETING);

	EmployeeBinarySearchTree* tree = new EmployeeBinarySearchTree();

	tree->insert(dan);
	tree->insert(bob);
	tree->insert(alice);
	tree->insert(charlie);
	tree->insert(frank);
	tree->insert(edward);
	tree->insert(gregory);

	/*
		The tree now looks like this:

							Daniel
				Bob						Frank
		Alice		Charlie		Edward		Gregory
	*/

	cout << endl << "In Order: " << endl;
	tree->traverseInOrder();

	cout << endl << "Pre Order: " << endl;
	tree->traversePreOrder();

	cout << endl << "Post Order: " << endl;
	tree->traversePostOrder();

	cout << endl << "Depth First Search: " << endl;
	Employee* found = tree->depthFirstSearch("Bob");
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}

	cout << endl << "Breadth First Search: " << endl;
	found = tree->breadthFirstSearch("Frank");
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}

	getchar();
}
