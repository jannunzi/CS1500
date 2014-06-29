#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
	string name;
	int xMin, yMin, xMax, yMax;
	int xCenter, yCenter;
public:
	Shape(){}
	Shape(string name)
	{
		setName(name);
	}
	void setName(string name)
	{
		this->name = name;
	}
	void display()
	{
		cout << "Shape: " << name << endl;
	}
};

class Rectangle : Shape
{
private:
	int xMax, yMax, xMin, yMin;
public:
	Rectangle(string name) : Shape(name) {}
	Rectangle(string name, int x1, int y1, int x2, int y2)
		: Rectangle(name) {
	}
	void setXMax(int x) { xMax = x; }
	void setYMax(int y) { yMax = y; }
	void setXMin(int x) { xMin = x; }
	void setYMin(int y) { yMin = y; }
	double length() { return xMax - xMin; }
	double height() { return yMax - yMin; }
	double area() {
		return length() * height();
	}
	void display()
	{
		Shape::display();
		cout << "Rectangle: " << xMax << endl;
	}
};

class Square : Rectangle {
private:
	int top, left, length;
public:
	Square(string name):Rectangle(name) {}
	Square(string name, int top, int left, int length)
		: Rectangle(name, top, left, top + length, length + length)
	{}
	double area()
	{
		return length * length;
	}
};
