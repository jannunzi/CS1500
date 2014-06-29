#include <iostream>
#include <string>
using namespace std;

class Component {
protected:
	string name;
	double price;
public:
	Component* left = NULL;
	Component* right = NULL;
	Component(){}
	Component(string name, double price){
		setName(name);
		setPrice(price);
	}
	void setName(string name) { this->name = name; }
	void setPrice(double price) { this->price = price; }
	string getName() { return name; }
	double getPrice(){ return price; }
	virtual void display() = 0;
};

class Resistor : public Component {
protected:
	double impedance;
public:
	Resistor(){}
	Resistor(string name, double price, double impedance)
		: Component(name, price)
	{
		setImpedance(impedance);
	}
	void setImpedance(double impedance) { this->impedance = impedance; }
	double getImpedance() { return impedance; }
	void display() {
		cout << name << " " << impedance << " Ohms" << endl;
	}
};

class Capacitor : public Component {
private:
	double capacitance;
public:
	Capacitor(){}
	Capacitor(string name, double price, double capacitance)
		: Component(name, price)
	{
		setCapacitance(capacitance);
	}
	void setCapacitance(double capacitance) {
		this->capacitance = capacitance;
	}
	double getCapacitance() { return capacitance; }
	void display() {
		cout << name << " " << capacitance << " Farads" << endl;
	}
};

void inOrder(Component* root) {
	if (root != NULL) {
		inOrder(root->left);
		root->display();
		inOrder(root->right);
	}
}

void postOrder(Component* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		root->display();
	}
}

void preOrder(Component* root) {
	if (root != NULL) {
		root->display();
		preOrder(root->left);
		preOrder(root->right);
	}
}

double total(Component* root) {
	if (root == NULL) {
		return 0;
	} else {
		return total(root->left) + root->getPrice() + total(root->right);
	}
}

double count(Component* root) {
	if (root == NULL) {
		return 0;
	} else {
		return count(root->left) + 1 + count(root->right);
	}
}

double average(Component* root) {
	return total(root) / count(root);
}

int main() {
	Resistor* r1 = new Resistor("R1", 1.0, 23.34);
	Resistor* r2 = new Resistor("R2", 2.0, 34.45);
	Resistor* r3 = new Resistor("R3", 3.0, 45.56);
	r2->left  = r1;
	r2->right = r3;

	Capacitor* c1 = new Capacitor("C1", 4.0, 32.43);
	Capacitor* c2 = new Capacitor("C2", 5.0, 43.54);
	Capacitor* c3 = new Capacitor("C3", 6.0, 54.65);
	c2->left  = c1;
	c2->right = c3;

	Capacitor* c4 = new Capacitor("C4", 7.0, 65.76);
	c4->left  = r2;
	c4->right = c2;

	cout << "In Order" << endl;
	inOrder(c4);
	cout << "Pre Order" << endl;
	preOrder(c4);
	cout << "Post Order" << endl;
	postOrder(c4);

	cout << "Total Price: $"   << total(c4)   << endl;
	cout << "Count: "   << count(c4)   << endl;
	cout << "Average Price: $" << average(c4) << endl;
}

/*
	Output

	In Order
	R1 23.34 Ohms
	R2 34.45 Ohms
	R3 45.56 Ohms
	C4 65.76 Farads
	C1 32.43 Farads
	C2 43.54 Farads
	C3 54.65 Farads
	Pre Order
	C4 65.76 Farads
	R2 34.45 Ohms
	R1 23.34 Ohms
	R3 45.56 Ohms
	C2 43.54 Farads
	C1 32.43 Farads
	C3 54.65 Farads
	Post Order
	R1 23.34 Ohms
	R3 45.56 Ohms
	R2 34.45 Ohms
	C1 32.43 Farads
	C3 54.65 Farads
	C2 43.54 Farads
	C4 65.76 Farads
	Total Price: $28
	Count: 7
	Average Price: $4
*/