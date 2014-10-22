#include <iostream>
#include <string>
using namespace std;

void changeInteger(int * integer, int newValue)
{
	cout << "changeInteger" << endl;
	cout << *integer << endl;
	*integer = newValue;
	cout << *integer << endl;
}

struct Employee
{
	// member variables (properties/attributes)
	string name;
	float salary;

	// Default Constructor (No Arguments)
	Employee()
	{
		cout << "Default Employee() Constructor" << endl;
	}
	// All Argument Constructor
	Employee(string name, float salary) {
		cout << "All Argument Constructor " << name << endl;
		this->name = name;
		this->salary = salary;
	}
	~Employee(){} // no destructors for tomorrow
	// member functions (methods)
	void display() {
		cout << name << " $" << salary << endl;
	}
	void giveRaise(float percentage) {
		salary *= 1 + percentage;
	}
};

struct MyInteger {
	MyInteger add(MyInteger otherInteger) {
		MyInteger result;
		return result;
	}
};
struct MyFloat {
	MyFloat add(MyFloat otherInteger) {
		MyFloat result;
		return result;
	}
};
// functional programming
MyInteger addMyIntegers(MyInteger integer1, MyInteger integer2) {
	MyInteger i;
	return i;
}
MyFloat addMyFloats(MyFloat integer1, MyFloat integer2) {
	MyFloat f;
	return f;
}


struct Polynomial
{
	int order;
	float * coefficients;
	Polynomial() {}
	Polynomial(int order, float * coeffs) {
		this->order = order;
		this->coefficients = coeffs;
	}
	Polynomial plus(Polynomial other) {
		Polynomial result;

		result.coefficients = new float[order + 1];
		result.order = order;

		for (int i = 0; i <= order; i++) {
			result.coefficients[i] = coefficients[i] + other.coefficients[i];
		}

		return result;
	}
	void display() {
		for (int i = 0; i <= order; i++) {
			cout << coefficients[i] << "X^" << i << " + ";
		}
		cout << endl;
	}
};


int main()
{
	cout << "\nPolynomials" << endl;

	float c1[] = { 12, 23, 34, 45 };
	float c2[] = { 21, 32, 43, 54, 67,78 };

	Polynomial p1(3, c1);
	Polynomial p2(3, c2);

	p1.display();
	p2.display();

	Polynomial p3 = p1.plus(p2);

	p3.display();

	cout << "\nStructures" << endl;

	Employee * charlie = new Employee(); // default constructor
	charlie->name = "Charlie";
	charlie->salary = 22222;
	charlie->display();

	Employee * dan = new Employee("Dan", 321123); // all argument constructor
	dan->display();

	Employee bob("Bob", 321123);

	Employee alice;
	alice.name = "Alice";
	alice.salary = 100000;

	alice.display();
	alice.giveRaise(0.05);
	alice.display();


	MyInteger int1;
	MyInteger int2;
	MyInteger int3 = addMyIntegers(int1, int2);

	int3 = int1.add(int2);

	MyFloat float1;
	MyFloat float2;
	MyFloat float3 = addMyFloats(float1, float2);

	float3 = float1.add(float2);

	if (1 == 1) exit(0);

	cout << "\nDynamic Arrays" << endl;

	int arr1[] = { 1, 2, 3, 4 };
	for (int i = 0; i < 4; i++){
		cout << arr1[i] << endl;
	}

	int size;
	cout << "Size: ";
	cin >> size;

	int * arr2 = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < size; i++) {
		cout << arr2[i] << endl;
	}

	cout << "\nPointers" << endl;

	int a = 123;
	int aa = 234;
	char b = 'Q';

	cout << a << endl;
	cout << aa << endl;
	cout << b << endl;

	int * p = &a;

	cout << p << endl;
	cout << *p << endl;

	*p = 321;

	cout << *p << endl;
	cout << a << endl;

	p = &aa;

	cout << p << endl;
	cout << *p << endl;
	cout << aa << endl;
	changeInteger(&aa, 432);
	cout << aa << endl;

}