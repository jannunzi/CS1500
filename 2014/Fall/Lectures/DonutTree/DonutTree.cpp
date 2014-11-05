#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string name;
	int age;
	Donut * left = NULL;
	Donut * right = NULL;
	Donut(){}
	Donut(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void display() {
		cout << name << " " << age << endl;
	}
};

struct DonutTray {
	string name;
	Donut * root;
	DonutTray() {}
	DonutTray(string name, Donut * root) {
		this->name = name;
		this->root = root;
	}
	void insert(Donut * newDonut) {
		insert(newDonut, root);
	}
	void insert(Donut * newDonut, Donut * root) {
		if (root == NULL)
		{
			root = newDonut;
		}
		if (name > root->name)
			return insert(newDonut, root->right);
		else if (name < root->name)
			return insert(newDonut, root->left);
	}
	Donut * search(string name) {
		return search(name, root);
	}
	Donut * search(string name, Donut * root) {
		if (root == NULL)
			return NULL;
		if (name == root->name)
			return root;
		if (name > root->name)
			return search(name, root->right);
		else if (name < root->name)
			return search(name, root->left);
		return NULL;
	}
	void display() {
		cout << endl << name << endl;
		//root->display();
		//root->left->display();
		//root->right->display();
		display(root);
		cout << "--------------" << endl;
	}
	void display(Donut * root) {
		if (root == NULL)
			return;
		display(root->left);
		root->display();
		display(root->right);
	}
};

int main() {
	Donut * d1 = new Donut("Boston Cream", 1);
	Donut * d2 = new Donut("Chocolate", 1);
	Donut * d3 = new Donut("Eclair", 2);
	Donut * d4 = new Donut("Jelly", 3);
	Donut * d5 = new Donut("Powdered", 1);
	Donut * d6 = new Donut("Strawberry", 3);
	Donut * d7 = new Donut("Vanilla", 2);

	d2->left = d1;
	d2->right = d3;

	d6->left = d5;
	d6->right = d7;

	d4->left = d2;
	d4->right = d6;

	DonutTray * t1 = new DonutTray("Tray 1", d4);
	t1->display();

	Donut * found = t1->search("Rocky Roads");
	if (found != NULL)
		found->display();
	else {
		cout << "Not found" << endl;
		Donut * r = new Donut("Rocky Roads", 321);
		t1->insert(r);
	}
}