#include <iostream>
#include <string>
using namespace std;

struct Book
{
	string title = "";
	string isbn = "";
	float  price;
};

const int MAX = 10;
int top = 0;

int main()
{
	Book* dune = new Book;
	dune->title = "Dune";
	dune->isbn = "123123123";
	dune->price = 9.99;
	cout << dune << endl;

	Book* lotr = new Book;
	lotr->title = "Lord of the Rings";
	lotr->isbn = "321123321";
	lotr->price = 8.99;

	Book* blade = new Book;
	blade->title = "Do Robots Dream of Electric Sheep";
	blade->isbn = "234432234";
	blade->price = 7.99;

	Book* stack[10];

	stack[0] = dune;
	stack[3] = lotr;

	cout << stack[0] << endl;

	cout << dune->title << endl;
	cout << stack[0]->title << endl;

	getchar();
}