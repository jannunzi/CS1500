#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "Hello World!";
	cout << str << endl;

	cout << str.substr(2, 3) << endl;

	cout << str.substr(2) << endl;

	cout << str.find('e') << endl;
	cout << str.find('o') << endl;
	cout << str.find('o', 5) << endl;
	cout << str.find("Hello") << endl;
	cout << str.find("World") << endl;

	str = str + " Good Bye!";
	cout << str << endl;

	str += " Ciao";
	cout << str << endl;

	string bye = str.substr(str.find("Good Bye"));
	cout << bye << endl;

	bye = "321";
	str = "123";

	bool same = bye == str;

	cout << same << endl;

	cout << bye.compare(str) << endl;
}
