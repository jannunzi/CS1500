#include <iostream>		// for cout and cin
#include <conio.h>		// for getch()
#include <string>		// for string class
using namespace std;	// for cout and cin

class Position {
  private:
    double x, y;
    double rotation;
  public:
    Position(double x, double y, double rotation);
    void print();
    void setX(double newX) { x = newX; }
    
    double getX() { return x; }
    double getY() { return y; }
    double getRotation() { return rotation; }
};

Position::Position(double x, double y, double rotation) {
    this->x = x;
    this->y = y;
    this->rotation = rotation;
}

void Position::print() {
     cout << "(" << x << ", " << y << ") <" << rotation << endl;
}

class Rectangle {
  private:
    string name;
    double height, length;
    Position* position;
  public:
    Rectangle(string name, double height, double length, Position* position);
    void print();
    void setName(string newName) {
         name = newName;
    }
    void setLength(double newLength) {
         length = newLength;
    }
    Position* getPosition() {
             return position;
    }
//    /*
    Rectangle(Rectangle& other) {
        this->name = other.name;
        this->height = other.height;
        this->length = other.length;
        Position* otherPosition = other.position;
        Position* thisPosition = new Position(otherPosition->getX(), otherPosition->getY(), otherPosition->getRotation());
        this->position = thisPosition;
    }
//    */
    double getArea() {
        return length * height;
    }
    
    double getPerimeter() {
        return length * 2 + height * 2;
    }
};

Rectangle::Rectangle(string name, double height, double length, Position* position) {
    this->name = name;
    this->height = height;
    this->length = length;
    this->position = position;
}

void Rectangle::print() {
    cout << "Rectangle: " << name << endl;
    cout << "Height: " << height << endl;
    cout << "Length: " << length << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
    position->print();
    cout << "=========" << endl;
}

int main() {
    Position p1(21.32,32.43, 45.0);
    Rectangle r1("R1", 12.23, 23.34, &p1);
    r1.print();
    
    Rectangle r2 = r1;
    r2.setName("R2");
    r2.setLength(432.34);
    r2.print();
    
    Position* r2p = r2.getPosition();
    r2p->print();
    
    r2p->setX(321.123);
    r2p->print();

    r2.print();
    r1.print();
    
    getch();
}
