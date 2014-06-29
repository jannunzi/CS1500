#include <iostream>
using namespace std;

struct Donut {
	int flavor;
	float price;
	Donut() {
		cout << "constructor 1" << endl;
		flavor = 321;
		price = 0.69f;
		cout << "default price: " << price << endl;
	}
	Donut(int f, float p)
	{
		cout << "constructor 2" << endl;
		cout << "f: " << f << endl;
		cout << "p: " << p << endl;
		flavor = f;
		if (p > 0)
			price = p;
		else
			price = 0.79;
	}
	Donut(const Donut &d)
	{
		cout << "copying constructor" << endl;
		flavor = d.flavor;
		price = d.price;
	}
};

void displayDonut(Donut d)
{
	cout << "Display Donut: " << endl;
	cout << d.price << endl;
	d.price = 123.32;
}

void main123()
{/*
	const int CHOCOLATE = 123;

	Donut donut1;
	cout << donut1.price << endl;
	Donut donut2;
	donut2 = donut1;
	cout << donut2.price << endl;
	donut2.price = 1.99;

	cout << donut1.price << endl;
	cout << donut2.price << endl;

	donut1.price = 2.99;

	cout << donut1.price << endl;
	cout << donut2.price << endl;

	int x;

	Donut* donut3 = new Donut;
	cout << donut3 << endl;
	Donut* donut4;
	donut4 = donut3;
	cout << donut4 << endl;

	donut3->flavor = 321;
	donut3->price = 0.99;
	cout << donut3->price << endl;
	cout << donut4->price << endl;

	donut4->price = 1.99;
	cout << donut4->price << endl;
	cout << donut3->price << endl;

	donut4 = new Donut;
	donut4->price = donut3->price;
	donut4->flavor = donut3->flavor;
	cout << donut3->price << endl;
	cout << donut4->price << endl;

	donut3->price = 3.99;
	cout << donut3->price << endl;
	cout << donut4->price << endl;

	donut4->price = 5.99;
	cout << donut3->price << endl;
	cout << donut4->price << endl;
	*/
	Donut donut5;				// 1st
	Donut donut6(12, 0.123f);	// 2nd
	Donut donut9 = donut6;

	Donut* donut7 = new Donut;	// 1st
	Donut* donut8 = new Donut(32, 0.45f); // 2nd




	cout << donut8->price << endl;

	displayDonut(donut6);

	getchar();
}
