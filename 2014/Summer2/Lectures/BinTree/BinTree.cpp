#include <iostream>
#include <string>
using namespace std;

class Donut {
private:
	string flavor;
public:
	Donut* left = NULL;
	Donut* right = NULL;
	Donut(){}
	Donut(string flavor){
		setFlavor(flavor);
	}
	void setFlavor(string flavor) {
		this->flavor = flavor;
	}
	string getFlavor() {
		return flavor;
	}
	void display() {
		cout << flavor << endl;
	}
};

void displayTreeInOrder(Donut* root) {
	if (root == NULL)
		return;
	displayTreeInOrder(root->left);
	root->display();
	displayTreeInOrder(root->right);
}

void displayTreeInReverseOrder(Donut* root) {
	if (root == NULL)
		return;
	displayTreeInOrder(root->right);
	root->display();
	displayTreeInOrder(root->left);
}

void displayTreePreOrder(Donut* root) {
	if (root == NULL)
		return;
	root->display();
	displayTreePreOrder(root->left);
	displayTreePreOrder(root->right);
}

void displayTreePostOrder(Donut* root) {
	if (root == NULL)
		return;
	displayTreePostOrder(root->left);
	displayTreePostOrder(root->right);
	root->display();
}

Donut* depthFirstSearch(Donut* root, string flavor) {
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

Donut* binSearchTree(Donut* root, string flavor) {
	if (root == NULL)
		return NULL;
	if (root->getFlavor() == flavor) {
		return root;
	}
	if (flavor > root->getFlavor()) {
		return binSearchTree(root->right, flavor);
	} else if (flavor < root->getFlavor()) {
		return binSearchTree(root->left, flavor);
	}
	return NULL;
}

void insertBinSearchTree(Donut* *root, Donut* donut) {
	if (*root == NULL) {
		*root = donut;
	}
	if (donut->getFlavor() >(*root)->getFlavor())
		insertBinSearchTree(&((*root)->right), donut);
	else if (donut->getFlavor() < (*root)->getFlavor())
		insertBinSearchTree(&((*root)->left), donut);
}

int main() {
	Donut* da = new Donut("Apple Cider");
	Donut* db = new Donut("Boston Cream");
	Donut* dc = new Donut("Crawler");

	db->left = da;
	db->right = dc;

	cout << "\ndisplayTreeInOrder(db);" << endl;
	displayTreeInOrder(db);
	cout << "\ndisplayTreeInOrder(da);" << endl;
	displayTreeInOrder(da);
	cout << "\ndisplayTreeInOrder(dc);" << endl;
	displayTreeInOrder(dc);
	cout << "\ndisplayTreePreOrder(db);" << endl;
	displayTreePreOrder(db);
	cout << "\ndisplayTreePostOrder(db);" << endl;
	displayTreePostOrder(db);
	cout << "\ndisplayTreeInReverseOrder(db);" << endl;
	displayTreeInReverseOrder(db);

	Donut* dd = new Donut("Dunkin Donuts");
	Donut* de = new Donut("Eclair");
	Donut* df = new Donut("Frosted");
	Donut* dg = new Donut("Glazed");

	df->left = de;
	df->right = dg;

	dd->left = db;
	dd->right = df;

	cout << "\ndisplayTreeInOrder(dd);" << endl;
	displayTreeInOrder(dd);

	cout << "\nsearchTree(dd);" << endl;
	Donut* found = binSearchTree(NULL, "Jelly");
	if (found == NULL) {
		cout << "Not Found" << endl;
	}
	else {
		found->display();
	}

	cout << "\nInsert" << endl;
	Donut* root = NULL;
	Donut* ptr = new Donut("D");
	insertBinSearchTree(&root, ptr);
	ptr = new Donut("B");
	insertBinSearchTree(&root, ptr);
	ptr = new Donut("A");
	insertBinSearchTree(&root, ptr);
	ptr = new Donut("E");
	insertBinSearchTree(&root, ptr);
	ptr = new Donut("Z");
	insertBinSearchTree(&root, ptr);
	ptr = new Donut("Q");
	insertBinSearchTree(&root, ptr);
	displayTreeInOrder(root);

	cout << "\nDepth First Search" << endl;
	found = depthFirstSearch(root, "Y");
	if (found != NULL) {
		found->display();
	}
	else {
		cout << "Not Found" << endl;
	}
}
