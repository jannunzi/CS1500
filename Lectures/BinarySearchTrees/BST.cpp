#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	string firstName;
	Employee* left = NULL;
	Employee* right = NULL;
	Employee(){}
	Employee(string fn) { firstName = fn; }
	void display() { cout << firstName << endl; }
};

void displayPreorder(Employee* root)
{
	if (root != NULL)
	{
		root->display();
		displayPreorder(root->right);
		displayPreorder(root->left);
	}
}

void displayPostorder(Employee* root)
{
	if (root != NULL)
	{
		displayPostorder(root->right);
		displayPostorder(root->left);
		root->display();
	}
}

void displayInorder(Employee* root)
{
	if (root != NULL)
	{
		displayInorder(root->left);
		root->display();
		displayInorder(root->right);
	}
}

Employee* search(string firstName, Employee* root)
{
	if (root != NULL)
	{
		if (firstName == root->firstName)
		{
			return root;
		}
		else if (firstName > root->firstName)
		{
			return search(firstName, root->right);
		}
		else if (firstName < root->firstName)
		{
			return search(firstName, root->left);
		}
	}
	return NULL;
}

void insert(Employee* employee, Employee** root)
{
	if (*root == NULL)
	{
		*root = employee;
		return;
	}

	if (employee->firstName < (*root)->firstName)
	{
		insert(employee, &((*root)->left));
	}
	else if (employee->firstName >= (*root)->firstName)
	{
		insert(employee, &(*root)->right);
	}
}

int main()
{
	Employee* rootB = NULL;

	Employee* A = new Employee("A");
	Employee* B = new Employee("B");
	Employee* C = new Employee("C");
	Employee* D = new Employee("D");
	Employee* E = new Employee("E");
	Employee* F = new Employee("F");
	Employee* G = new Employee("G");

	insert(D, &rootB);
	insert(B, &rootB);
	insert(C, &rootB);
	insert(A, &rootB);
	insert(F, &rootB);
	insert(E, &rootB);
	insert(G, &rootB);

	cout << endl << "Display In Order Root B" << endl;
	displayInorder(rootB);
	cout << "Done" << endl;

	Employee* alice = new Employee("Alice");
	Employee* bob = new Employee("Bob");
	Employee* charlie = new Employee("Charlie");

	Employee* root = NULL;

	root = bob;
	bob->left = alice;
	bob->right = charlie;

	// in order display
	root->left->display();
	root->display();
	root->right->display();

	Employee* dan = new Employee("Dan");
	Employee* ed = new Employee("Edward");
	Employee* frank = new Employee("Frank");

	ed->right = frank;
	ed->left = dan;

	charlie->right = ed;

	cout << endl << "Display Preorder Tree" << endl;
	displayPreorder(root);
	cout << endl << "Display Postorder Tree" << endl;
	displayPostorder(root);
	cout << endl << "Display In Order Tree" << endl;
	displayInorder(root);

	cout << endl << "Search for Edward" << endl;
	Employee* found = search("Edward", root);
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not found" << endl;
	}

	getchar();
}