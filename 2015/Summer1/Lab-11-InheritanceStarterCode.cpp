#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape {
protected:
	string name;
public:
	Shape() : Shape("") {}
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

class Point : public Shape
{
protected:
	int x, y;
public:
	Point(){}
	Point(string name, int x, int y)
		: Shape(name)
	{
		setX(x);
		setY(y);
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void display()
	{
		cout << "Point:" << endl;
		Shape::display();
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
	}
};

class Line : public Shape
{
protected:
	Point* a;
	Point* b;
public:
	Line(){}
	Line(string name, Point* a, Point* b)
		: Shape(name){} // complete this code
	void setPointA(Point* a){} // complete this code
	void setPointB(Point* b){} // complete this code
	Point* getPointA() {} // complete this code
	Point* getPointB(){} // complete this code
	double length() {} // complete this code
	void display()
	{
		cout << "Line: " << endl;
		Shape::display();
		a->display();
		b->display();
		cout << "Length: " << length() << endl;
	}
};

class Rectangle
{
protected:
	Line* top;
	Line* bottom;
	Line* left;
	Line* right;
public:
	Rectangle(){}
	Rectangle(string name, Line* top, Line* right, Line* bottom, Line* left); // complete this code
	void setTopLine(Line* top) { this->top = top; }
	Line* getTopLine() { return this->top; }
	
	// implement rest of setters and getters
	
	double area(){} // complete this code
	double perimeter(){} // complete this code
	void display(){} // complete this code
};

class Square : public Rectangle
{
public:
	Square(){}
	Square(string name, Line* horizontal, Line* vertical)
		: Rectangle(name, horizontal, vertical, horizontal, vertical)
	{
		setHorizontalLine(horizontal);
		setVerticalLine(vertical);
	}
	void setHorizontalLine(Line* horizontal)
	{
		this->top = horizontal;
	}
	void setVerticalLine(Line* vertical)
	{
		this->left = vertical;
	}
	Line* getHorizontalLine() { return top; }
	Line* getVerticalLine() { return left; }
	double area()
	{
		return top->length() * left->length();
	}
	double perimeter()
	{
		return top->length() * 2 + left->length() * 2;
	}
	void display()
	{
		cout << "Square:" << endl;
		Shape::display();
		top->display();
		left->display();
		cout << "Area: " << area() << endl;
		cout << "Perimieter: " << perimeter() << endl;
	}
};

int main()
{
	cout << endl << "Test Point Class" << endl;
	Point* p1 = new Point("P1", 12, 23);
	Point* p2 = new Point("P2", 23, 34);
	p1->display();
	p2->display();

	cout << endl << "Test Line Class" << endl;
	Line* line1 = new Line("Line1", p1, p2);
	line1->display();

	cout << endl << "Test Square Class" << endl;
	Point* p3 = new Point("P3", 34, 45);
	Point* p4 = new Point("P4", 45, 56);
	Line* line2 = new Line("Line2", p3, p4);
	Square* s1 = new Square("S1", line1, line2);
	s1->display();

	cout << endl << "Test Rectangle Class" << endl;
	Point* p5 = new Point("P5", 56, 67);
	Point* p6 = new Point("P6", 67, 78);
	Line* line3 = new Line("Line3", p5, p6);
	Point* p7 = new Point("P7", 78, 89);
	Point* p8 = new Point("P8", 89, 90);
	Line* line4 = new Line("Line4", p7, p8);
	Rectangle* r1 = new Rectangle("R1", line1, line2, line3, line4);
	r1->display();
}

/*	Sample Output

Test Point Class
Point:
Shape: P1
X: 12
Y: 23
Point:
Shape: P2
X: 23
Y: 34

Test Line Class
Line:
Shape: Line1
Point:
Shape: P1
X: 12
Y: 23
Point:
Shape: P2
X: 23
Y: 34
Length: 15.5563

Test Square Class
Square:
Shape: S1
Line:
Shape: Line1
Point:
Shape: P1
X: 12
Y: 23
Point:
Shape: P2
X: 23
Y: 34
Length: 15.5563
Line:
Shape: Line2
Point:
Shape: P3
X: 34
Y: 45
Point:
Shape: P4
X: 45
Y: 56
Length: 15.5563
Area: 242
Perimieter: 62.2254

Test Rectangle Class
Rectangle:
Shape: R1
Line:
Shape: Line1
Point:
Shape: P1
X: 12
Y: 23
Point:
Shape: P2
X: 23
Y: 34
Length: 15.5563
Line:
Shape: Line3
Point:
Shape: P5
X: 56
Y: 67
Point:
Shape: P6
X: 67
Y: 78
Length: 15.5563
Line:
Shape: Line2
Point:
Shape: P3
X: 34
Y: 45
Point:
Shape: P4
X: 45
Y: 56
Length: 15.5563
Line:
Shape: Line4
Point:
Shape: P7
X: 78
Y: 89
Point:
Shape: P8
X: 89
Y: 90
Length: 11.0454
Area: 242
Perimeter: 57.7144

*/
