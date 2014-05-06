#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void main() {
	string quote = "To be or not to be. That is the question.";
	cout << quote << endl;

	cout << "Length: " << quote.length() << endl;
	getch();

	cout << "not: " << quote.find("not") << endl;
	cout << "find_first_of: " << quote.find_first_of("be") << endl;
	cout << "find_last_of: " << quote.find_last_of("be") << endl;
	getch();

}