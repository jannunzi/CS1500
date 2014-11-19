#include <iostream>
using namespace std;

struct Node {
	int data;
	Node * left = NULL;
	Node * right = NULL;
	Node(int data) { this->data = data; }
	Node(){}
	void display() {
		cout << data << endl;
	}
};

struct Queue {
	Node ** nodes;
	int front = 0;
	int back = 0;
	int size;
	Queue(){}
	Queue(int size) {
		this->size = size;
		nodes = new Node*[size];
	}
	bool empty() {
		return front == back;
	}
	void enqueue(Node * node) {
		if (back == size || node == NULL)
			return;
		nodes[back] = node;
		back = (back + 1) % size;
	}
	Node * dequeue() {
		if (front == back)
			return NULL;
		Node * node = nodes[front];
		front = (front + 1) % size;
		return node;
	}
};

struct Tree {
	Node * root = NULL;
	Tree(){}
	Tree(Node*root){ this->root = root; }
	void traverseInOrder() {
		traverseInOrder(root);
	}
	void traverseInOrder(Node * root) {
		if (root == NULL)
			return;
		traverseInOrder(root->left);
		root->display();
		traverseInOrder(root->right);
	}
	Node * breadthFirstSearch(int needle) {
		Queue * queue = new Queue(20);
		queue->enqueue(root);
		while (!queue->empty()) {
			Node * node = queue->dequeue();
			if (node->data == needle)
				return node;
			node->display();
			queue->enqueue(node->left);
			queue->enqueue(node->right);
		}
		return NULL;
	}
};


int main() {
	Node * n1 = new Node(1);
	Node * n2 = new Node(2);
	Node * n3 = new Node(3);
	Node * n4 = new Node(4);
	Node * n5 = new Node(5);
	Node * n6 = new Node(6);
	Node * n7 = new Node(7);

	n2->left = n1;
	n2->right = n3;
	n6->left = n5;
	n6->right = n7;
	n4->left = n2;
	n4->right = n6;

	Tree * tree = new Tree(n4);

	Node * node = tree->breadthFirstSearch(2);
	cout << node->data << endl;
//	tree->traverseInOrder();
}