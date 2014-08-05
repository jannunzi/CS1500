#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
	string name;
	string color;
	bool border;
public:
	Shape(){}
	Shape(string name, string color, bool border){
		this->name = name;
		this->color = color;
		this->border = border;
	}
	void display() {
		cout << "Name: " << name << "\nColor: " << color << "\nBorder: " << border << endl;
	}
};

class Rectangle : public Shape {
private:
	double length = 0, width = 0;
public:
	void setLength(double length) {
		if (length > 0)
			this->length = length;
	}
	void setWidth(double width) {
		if (width > 0)
			this->width = width;
	}
	double getLength() {
		return length;
	}
	double getWidth() {
		return width;
	}
	Rectangle(){}
	Rectangle(string name, string color, bool border, double length, double width)
		: Shape(name, color, border)
	{
		setLength(length);
		setWidth(width);
	}
	float getArea() {
		return length * width;
	}
	void display() {
		Shape::display();
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
		cout << "Area: " << getArea() << endl;
	}
};

class Square : public Rectangle {
public:
	Square(){}
	Square(string name, string color, bool border, double size)
		: Rectangle(name, color, border, size, size)
	{

	}
	void display() {
		Rectangle::display();
	}
};

int main() {
	Shape s1("S1","Black",true);
	s1.display();

	Rectangle r1 = {"R1", "Yellow", true, 12.23, 34.45};
	r1.display();

	Rectangle r2("R2", "Blue", false, 21.32, 43.54);
	r2.display();
	r2.setLength(12);
	r2.setWidth(12);
	cout << "R2's area: " << r2.getArea() << endl;

	Rectangle r3("R3", "Blue", false, 21.32, -43.54);
	r3.display();

	Square sq1("Square 1", "Red", true, 12.0);
	sq1.display();
}
