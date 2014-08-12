#include <iostream>
#include <string>
using namespace std;

class Donut {
private:
	string flavor;
	float price;
public:
	Donut* left = NULL;
	Donut* right = NULL;
	Donut(){}
	Donut(string flavor){
		setFlavor(flavor);
	}
	Donut(string flavor, float price) {
		setFlavor(flavor);
		this->price = price;
	}
	void setFlavor(string flavor) {
		this->flavor = flavor;
	}
	string getFlavor() {
		return flavor;
	}
	float getPrice() {
		return price;
	}
	void display() {
		cout << flavor << endl;
	}
};

class DonutTree {
private:
	Donut* root = NULL;
	int count = 0;
	float totalPrice = 0.0;
	void displayInOrder(Donut*);
	void displayPreOrder(Donut*);
	void displayPostOrder(Donut*);
	Donut* binSearch(Donut*, string);
	void insertBinSearch(Donut**, Donut*);
	Donut* depthFirstSearch(Donut*, string);
public:
	DonutTree(){}
	DonutTree(Donut* root) {
		this->root = root;
	}
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	Donut* binSearch(string);
	void insertBinSearch(Donut*);
	Donut* depthFirstSearch(string);
	Donut* min();
	Donut* max();
	float averagePrice();
};

float DonutTree::averagePrice() {
	if (count != 0)	{
		return totalPrice / count;
	}
	return 0;
}

Donut* DonutTree::min() {
	if (root == NULL) return NULL;

	Donut* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

Donut* DonutTree::max() {
	if (root == NULL) return NULL;

	Donut* current = root;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

void DonutTree::displayInOrder() {
	displayInOrder(root);
}

void DonutTree::displayPreOrder() {
	displayPreOrder(root);
}

void DonutTree::displayPostOrder() {
	displayPostOrder(root);
}

void DonutTree::displayInOrder(Donut* root) {
	if (root == NULL)
		return;
	displayInOrder(root->left);
	root->display();
	displayInOrder(root->right);
}

void DonutTree::displayPreOrder(Donut* root) {
	if (root == NULL)
		return;
	root->display();
	displayPreOrder(root->left);
	displayPreOrder(root->right);
}

void DonutTree::displayPostOrder(Donut* root) {
	if (root == NULL)
		return;
	displayPostOrder(root->left);
	displayPostOrder(root->right);
	root->display();
}

Donut* DonutTree::binSearch(string flavor) {
	return binSearch(root, flavor);
}

Donut* DonutTree::binSearch(Donut* root, string flavor) {
	if (root == NULL)
		return NULL;
	if (root->getFlavor() == flavor) {
		return root;
	}
	if (flavor > root->getFlavor()) {
		return binSearch(root->right, flavor);
	}
	else if (flavor < root->getFlavor()) {
		return binSearch(root->left, flavor);
	}
	return NULL;
}

Donut* DonutTree::depthFirstSearch(string flavor) {
	return depthFirstSearch(root, flavor);
}

Donut* DonutTree::depthFirstSearch(Donut* root, string flavor) {
	if (root == NULL)
		return NULL;
	if (root->getFlavor() == flavor) {
		return root;
	}
	Donut* found = depthFirstSearch(root->left, flavor);
	if (found != NULL) return found;
	found = depthFirstSearch(root->right, flavor);
	return found;
}

void DonutTree::insertBinSearch(Donut* donut) {
	if (donut == NULL)
		return;
	count++;
	totalPrice += donut->getPrice();
	insertBinSearch(&root, donut);
}

void DonutTree::insertBinSearch(Donut* *root, Donut* donut) {
	if (*root == NULL) {
		*root = donut;
	}
	if (donut->getFlavor() >(*root)->getFlavor())
		insertBinSearch(&((*root)->right), donut);
	else if (donut->getFlavor() < (*root)->getFlavor())
		insertBinSearch(&((*root)->left), donut);
}

int main() {
	Donut* da = new Donut("Apple Cider");
	Donut* db = new Donut("Boston Cream");
	Donut* dc = new Donut("Crawler");

	db->left = da;
	db->right = dc;

	Donut* dd = new Donut("Dunkin Donuts");
	Donut* de = new Donut("Eclair");
	Donut* df = new Donut("Frosted");
	Donut* dg = new Donut("Glazed");

	df->left = de;
	df->right = dg;

	dd->left = db;
	dd->right = df;

	DonutTree* tree = new DonutTree(dd);

	cout << "\ndisplayInOrder();" << endl;
	tree->displayInOrder();

	cout << "\ndisplayPreOrder();" << endl;
	tree->displayPreOrder();

	cout << "\ndisplayPostOrder();" << endl;
	tree->displayPostOrder();

	cout << "\nsearchTree(dd);" << endl;
	Donut* found = tree->binSearch("Eclair");
	if (found == NULL) {
		cout << "Not Found" << endl;
	}
	else {
		found->display();
	}

	cout << "\nInsert" << endl;
	DonutTree* tree2 = new DonutTree();

	Donut* ptr = new Donut("D",12);
	tree2->insertBinSearch(ptr);
	ptr = new Donut("B",23);
	tree2->insertBinSearch(ptr);
	ptr = new Donut("A",34);
	tree2->insertBinSearch(ptr);
	ptr = new Donut("E",45);
	tree2->insertBinSearch(ptr);
	ptr = new Donut("Z",56);
	tree2->insertBinSearch(ptr);
	ptr = new Donut("Q",67);
	tree2->insertBinSearch(ptr);

	tree2->displayInOrder();

	cout << "\nDepth First Search" << endl;
	found = tree2->depthFirstSearch("E");
	if (found != NULL) {
		found->display();
	}
	else {
		cout << "Not Found" << endl;
	}

	Donut* minDonut = tree2->min();
	Donut* maxDonut = tree2->max();
	if (minDonut != NULL)
		minDonut->display();
	else
		cout << "Min not Found";
	if (maxDonut != NULL)
		maxDonut->display();
	else
		cout << "Min not Found";

	float avg = tree2->averagePrice();
	cout << "\nAverage Price of Donut Tree" << endl;
	cout << avg << endl;
}
