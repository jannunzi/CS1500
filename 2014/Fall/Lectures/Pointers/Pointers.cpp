#include <iostream>
using namespace std;

//void giveHimRaise(int him, int amount) {
//	him += amount;
//}
//
//void giveHimRaise(int* him, int amount) {
//	cout << "giveHimRaise()" << endl;
//	cout << him << endl;
//	cout << *him << endl;
//
//	*him += amount;
//}

void giveHimRaise(int &him, int amount) {
	him += amount;
}

int main() {
	int bob = 100;
	int joe = 200;

	int *he = &bob;

	cout << bob << endl;
	cout << he << endl;
	cout << *he << endl;

	*he += 300;
	cout << *he << endl;
	cout << bob << endl;

	he = &joe;

	cout << "Joe: " << joe << endl;
	*he += 600;
	cout << "Joe: " << joe << endl;
	cout << "Joe: " << *he << endl;

	giveHimRaise(joe, 100);
	cout << "Joe: " << joe << endl;

//	giveHimRaise(&joe, 100);
//	cout << "Joe: " << joe << endl;
}
