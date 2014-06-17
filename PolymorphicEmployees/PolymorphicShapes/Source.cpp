#include <iostream>
#include <string>
using namespace std;

const int PI = 3.1415;

class Shape {
public:
	string name;
	Shape(){};
	Shape(string name) { this->name = name; }
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
	double length, height;
	Rectangle(){}
	Rectangle(string name, double l, double h)
		: Shape(name)
	{
		length = l;
		height = h;
	}
	double getArea() { return length*height; }
	double getPerimeter() { return length * 2 + height * 2; }
	void draw(){
		cout << "Rectangle" << endl;
		cout << name << endl;
		cout << getArea() << endl;
		cout << getPerimeter() << endl;
	}
};

class Circle : public Shape
{
public:
	double radius;
	Circle(){}
	Circle(string name, double r)
		: Shape(name)
	{
		radius = r;
	}
	double getArea() { return PI * radius * radius; }
	double getPerimeter() { return 2 * PI * radius; }
	void draw()
	{
		cout << "Circle" << endl;
		cout << name << endl;
		cout << getArea() << endl;
		cout << getPerimeter() << endl;
	}
};

int main()
{
	Rectangle* r1 = new Rectangle("R1", 12,23);
	Circle* c1 = new Circle("C1", 34);

//	r1->draw();
	//c1->draw();

	Shape* shapes[] = {r1, c1};

	for (int i = 0; i < 2; i++)
	{
		shapes[i]->draw();
	}
}
