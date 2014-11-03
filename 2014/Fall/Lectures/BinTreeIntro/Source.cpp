#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node * left = NULL;
	Node * right = NULL;
	Node(){}
	Node(int data) {
		this->data = data;
	}
	void display() {
		cout << data << endl;
		cout << left->data << endl;
		cout << right->data << endl;
	}
	void display(Node * root) {
		if (root == NULL)
			return;
		cout << root->data << endl;
		display(root->right);
		display(root->left);
	}
	void displayInOrder(Node * root) {
		if (root == NULL)
			return;
		displayInOrder(root->left);
		cout << root->data << endl;
		displayInOrder(root->right);
	}
	void displayInReverse(Node * root) {
		if (root == NULL)
			return;
		displayInReverse(root->right);
		cout << root->data << endl;
		displayInReverse(root->left);
	}
	void displayPreorder(Node * root) {
		if (root == NULL)
			return;
		cout << root->data << endl;
		displayPreorder(root->left);
		displayPreorder(root->right);
	}
	void displayPostorder(Node * root) {
		if (root == NULL)
			return;
		displayPostorder(root->left);
		displayPostorder(root->right);
		cout << root->data << endl;
	}
};

int main() {
	cout << "Hello Binary Search Trees" << endl;

	Node * node = NULL;
	Node * root = NULL;

	Node * one = new Node(1);
	Node * two = new Node(2);
	Node * three = new Node(3);

	two->left = one;
	two->right = three;

	Node * six = new Node(6);
	Node * five = new Node(5);
	Node * seven = new Node(7);

	six->left = five;
	six->right = seven;

	root = new Node(4);

	root->left = two;
	root->right = six;

//	root->display();
//	three->display();
//	root->display(root);
//	root->displayInOrder(root);
//	root->displayInReverse(root);
//	root->displayPreorder(root);
	root->displayPostorder(root);
}
