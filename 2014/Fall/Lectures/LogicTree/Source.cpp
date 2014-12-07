#include <iostream>
#include <string>
using namespace std;

class Node {
protected:
	string name;
public:
	Node(){}
	Node(string name) {
		this->name = name;
	}
	virtual bool evaluate() = 0;
};

class DataNode : public Node {
protected:
	bool data;
public:
	DataNode(){}
	DataNode(string name, bool data)
		: Node(name)
	{
		this->data = data;
	}
	bool evaluate()
	{
		return data;
	}
};

class UnaryOperatorNode : public Node {
protected:
	Node * param = NULL;
public:
	UnaryOperatorNode(){}
	UnaryOperatorNode(string name, Node * param)
		: Node(name)
	{
		this->param = param;
	}
};

class NotOperator : public UnaryOperatorNode
{
public:
	NotOperator(){}
	NotOperator(string name, Node * param)
		: UnaryOperatorNode(name, param)
	{}
	bool evaluate() {
		return !param->evaluate();
	}
};

class BinaryOperator : public Node
{
protected:
	Node * param1;
	Node * param2;
public:
	BinaryOperator(){}
	BinaryOperator(string name, Node* p1, Node* p2)
		: Node(name)
	{
		param1 = p1;
		param2 = p2;
	}
};

class AndOperator : public BinaryOperator {
public:
	AndOperator(){}
	AndOperator(string name, Node*p1, Node*p2)
		: BinaryOperator(name, p1, p2){}
	bool evaluate() {
		return param1->evaluate() && param2->evaluate();
	}
};

class OrOperator : public BinaryOperator {
public:
	OrOperator(){}
	OrOperator(string name, Node*p1, Node*p2)
		: BinaryOperator(name, p1, p2){}
	bool evaluate() {
		return param1->evaluate() || param2->evaluate();
	}
};

int main() {
	DataNode * A = new DataNode("A", false);
	DataNode * B = new DataNode("B", false);
	NotOperator * NotA = new NotOperator("Not A", A);
	cout << "A: " << A->evaluate() << endl;
	cout << "B: " << B->evaluate() << endl;
	cout << "Not A: " << NotA->evaluate() << endl;

	AndOperator * AandB = new AndOperator("A && B", A, B);
	cout << "A And B: " << AandB->evaluate() << endl;

	OrOperator * AorB = new OrOperator("A || B", A, B);
	cout << "A Or B: " << AorB->evaluate() << endl;

	DataNode * C = new DataNode("C", false);

	NotOperator * NotC = new NotOperator("Not C", C);

	AndOperator * Result = new AndOperator("Result", AorB, NotC);

	cout << "Result: " << Result->evaluate() << endl;
}
