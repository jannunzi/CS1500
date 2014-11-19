#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	string name;
	Shape(){}
	Shape(string name) {
		this->name = name;
	}
	virtual double area() = 0;
};

class Circle : public Shape {
public:
	double radius;
	Circle(string name, double radius)
		: Shape(name)
	{
		this->radius = radius;
	}
	double area() {
		return radius * radius * 3.1415;
	}
};

class Rectangle : public Shape
{
public:
	double width, height;
	Rectangle(string name, double width, double height)
		: Shape(name)
	{
		this->width = width;
		this->height = height;
	}
	double area() {
		return width * height;
	}
};

int main() {
	Circle * c1 = new Circle("C1", 12.23);
	Rectangle * r1 = new Rectangle("R1", 12.23, 34.45);

	Shape * shapes[] = {c1, r1};

	for (int i = 0; i < 2; i++){
		cout << shapes[i]->area() << endl;
	}
}
