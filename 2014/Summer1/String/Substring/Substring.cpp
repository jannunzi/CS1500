#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void main() {
	string quote = "To be or not to be. That is the question.";
	cout << quote << endl;

	// To be
	cout << quote.substr(0, 5) << endl;
	getch();

	// That is the question
	cout << quote.substr(20) << endl;
	getch();

	// not to be
	cout << quote.substr(9, 9) << endl;
	getch();
}
