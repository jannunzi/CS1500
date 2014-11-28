#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Node {
protected:
	string name;
public:
	Node(){}
	Node(string name)
	{
		this->name = name;
	}
	virtual double evaluate() = 0;
};
class NumberDataNode : public Node {
protected:
	double data;
public:
	NumberDataNode(){}
	NumberDataNode(string name, double data) : Node(name) {
		this->data = data;
	}
	void setData(double data) {
		this->data = data;
	}
	double getData() {
		return this->data;
	}
	double evaluate() {
		return data;
	}
};
class UnaryOperationNode : public Node {
protected:
	Node * param = NULL;
public:
	UnaryOperationNode() {}
	UnaryOperationNode(string name, Node * param)
		: Node(name)
	{
		this->param = param;
	}
};
class BinaryOperationNode : public Node {
protected:
	Node * param1 = NULL;
	Node * param2 = NULL;
public:
	BinaryOperationNode(){}
	BinaryOperationNode(string name, Node * param1, Node * param2)
		: Node(name)
	{
		this->param1 = param1;
		this->param2 = param2;
	}
};
class NegationOperationNode : public UnaryOperationNode {
public:
	NegationOperationNode() {}
	NegationOperationNode(string name, Node * param)
		: UnaryOperationNode(name, param)
	{}
	double evaluate() {
		return param->evaluate() * -1;
	}
};
class InverseOperationNode : public UnaryOperationNode{
public:
	InverseOperationNode() {}
	InverseOperationNode(string name, Node * param)
		: UnaryOperationNode(name, param)
	{}
	double evaluate() {
		return 1.0 / param->evaluate();
	}
};
class MultiplicationOperationNode : public BinaryOperationNode {
public:
	MultiplicationOperationNode(){}
	MultiplicationOperationNode(string name, Node * param1, Node * param2)
		: BinaryOperationNode(name, param1, param2)
	{}
	double evaluate() {
		return param1->evaluate() * param2->evaluate();
	}
};
class DivisionOperationNode : public BinaryOperationNode {
public:
	DivisionOperationNode(){}
	DivisionOperationNode(string name, Node * param1, Node * param2)
		: BinaryOperationNode(name, param1, param2)
	{}
	double evaluate() {
		return param1->evaluate() / param2->evaluate();
	}
};

int main() {

	NumberDataNode * two = new NumberDataNode("2", 2);

	NumberDataNode * x2 = new NumberDataNode("X2", 100);
	NumberDataNode * y2 = new NumberDataNode("Y2", 100);

	NumberDataNode * x1 = new NumberDataNode("X1", 50);
	NumberDataNode * y1 = new NumberDataNode("Y1", 50);

	SubtractionOperationNode * x2MinusX1 = new SubtractionOperationNode("X2 - X1", x2, x1);
	SubtractionOperationNode * y2MinusY1 = new SubtractionOperationNode("Y2 - Y1", y2, y1);

	PowerOperationNode * x2MinusX1Squared = new PowerOperationNode("(X2 - X1)^2", x2MinusX1, two);
	PowerOperationNode * y2MinusY1Squared = new PowerOperationNode("(Y2 - Y1)^2", y2MinusY1, two);
	
	AdditionOperationNode * sumOfSquares = new AdditionOperationNode("(X2 - X1)^2 + (Y2 - Y1)^2", x2MinusX1Squared, y2MinusY1Squared);
	
	SquareRootOperationNode * squareOfSums = new SquareRootOperationNode("Result", sumOfSquares);
	
	cout << squareOfSums->evaluate() << endl;
}
