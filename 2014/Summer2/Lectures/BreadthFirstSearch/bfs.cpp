#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int key;
	Node* left = NULL;
	Node* right = NULL;
	Node(){}
	Node(int key) {
		this->key = key;
	}
	void display() {
		cout << key << endl;
	}
};

class Tree {
public:
	Node* root;
	Node* queue[100];
	int head = 0;
	int tail = 0;
	Tree(Node* root) {
		this->root = root;
		enqueue(root);
	}
	Node* bfs(int needle) {
		if (isEmpty())
			return NULL;
		Node* node = dequeue();
		if (node->key == needle)
			return node;
		node->display();
		if (node->left != NULL)
			enqueue(node->left);
		if (node->right != NULL)
			enqueue(node->right);
		return bfs(needle);
	}
	void enqueue(Node* node) {
		queue[tail] = node;
		tail++;
	}
	Node* dequeue() {
		Node* node = queue[head];
		head++;
		return node;
	}
	bool isEmpty() {
		return head == tail;
	}
};

int main() {
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

}