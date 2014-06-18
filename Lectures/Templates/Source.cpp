#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
	T* data;
	Node* next = NULL;
	Node* prev = NULL;
	Node(){}
	Node(T* data){
		setData(T* data);
	}
	void setData(T* data){
		this->data = data;
	}
	T getData(){
		return data;
	}
};

class Employee{
public:
	string name;
	Employee(){}
	Employee(string name){
		this->name = name;
	}
};

int main() {
	Employee* alice = new Employee("Alice");
	Employee* bob = new Employee("Robert");
	Employee* chuck = new Employee("Charles");
	Employee* dan = new Employee("Daniel");
	Employee* ed = new Employee("Edward");

	Node<Employee> *root = new Node<Employee>(alice);
	Node<Employee> *newNode, *current = root;
	
	newNode = new Node<Employee>(bob);
	newNode->prev = current;
	current->next = newNode;
	current = newNode;

	newNode = new Node<Employee>(chuck);
	newNode->prev = current;
	current->next = newNode;
	current = newNode;

	newNode = new Node<Employee>(dan);
	newNode->prev = current;
	current->next = newNode;
	current = newNode;

	newNode = new Node<Employee>(ed);
	newNode->prev = current;
	current->next = newNode;
	current = newNode;
}
