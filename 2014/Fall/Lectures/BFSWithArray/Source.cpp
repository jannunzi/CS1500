#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node * left = NULL;
	Node * right = NULL;
	Node(){}
	Node(int data) { this->data = data; }
	void display() {
		cout << data << endl;
	}
};

class Queue {
private:
	int front = 0;
	int back = 0;
	int size = 0;
	int count = 0;
	Node* *nodes;
public:
	Queue(){}
	Queue(int size) {
		this->size = size;
		nodes = new Node*[size];
	}
	bool isFull() {
		return count == size;
	}
	bool isEmpty() {
		return count == 0;
	}
	void enqueue(Node* node) {
		if (isFull() || node == NULL)
			return;
		nodes[back] = node;
		back = (back + 1) % size;
		count++;
	}
	Node* dequeue() {
		if (isEmpty())
			return NULL;
		Node * node = nodes[front];
		front = (front + 1) % size;
		count--;
		return node;
	}
	void display() {
		cout << "===========" << endl;
		int index = front;
		for (int i = 0; i < count; i++)
		{
			cout << nodes[index]->data << endl;
			index = (index + 1) % size;
		}
	}
};

class Tree {
private:
	Node * root = NULL;
public:
	Tree(){};
	Tree(Node * root) {
		this->root = root;
	}
	void displayInOrder(){
		cout << "--------------" << endl;
		displayInOrder(root);
	}
	void displayInOrder(Node * root){
		if (root == NULL)
			return;
		displayInOrder(root->left);
		root->display();
		displayInOrder(root->right);
	}
	Node * breadthFirstSearch(int needle) {
		if (root == NULL)
			return NULL;
		Queue * queue = new Queue(10);
		queue->enqueue(root);
		while (!queue->isEmpty()) {
			Node * node = queue->dequeue();
			if (node->data == needle)
				return node;
			queue->enqueue(node->left);
			queue->enqueue(node->right);
		}
		return NULL;
	}
};

int main() {
	Queue * q = new Queue(5);

	Node * n1 = new Node(1);
	Node * n2 = new Node(2);
	Node * n3 = new Node(3);
	Node * n4 = new Node(4);
	Node * n5 = new Node(5);
	Node * n6 = new Node(6);
	Node * n7 = new Node(7);
	Node * n8 = new Node(8);

	n2->left = n1;
	n2->right = n3;

	n6->left = n5;
	n6->right = n7;

	n7->right = n8;

	n4->left = n2;
	n4->right = n6;

	Tree * tree = new Tree(n4);
	tree->displayInOrder();

	Node * found = tree->breadthFirstSearch(8);
	if (found == NULL) {
		cout << "Not found" << endl;
	}
	else {
		cout << "Found it" << endl;
		found->display();
	}

	q->enqueue(n1);
	q->display();
	q->enqueue(n2);
	q->enqueue(n3);
	q->display();
	q->enqueue(n4);
	q->enqueue(n5);
	q->enqueue(n6);
	q->display();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->display();
	q->enqueue(n7);
	q->enqueue(n8);
	q->display();
	q->dequeue();
	q->dequeue();
	q->display();
}
