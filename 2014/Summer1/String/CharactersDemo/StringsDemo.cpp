#include <iostream>		// for cout and cin
#include <string>		// for string
#include <sstream>		// for converting to strings
#include <conio.h>		// for getch()
using namespace std;	// for cout and cin

int main() {
	/*
	 *	Concatenating Strings
	 */
	cout	<< "Concatenating Strings" << endl;
	string	hello = "Hello ";
	string	world = "World !";
	string	helloWorld = hello + world;
	cout	<< hello << endl;
	cout	<< world << endl;
	cout	<< helloWorld << endl;
	getch();
	return 0;

	/*
	 *	String Find and Insert
	 */
	cout	<< endl << "String Find and Insert" << endl;
	string balance = "1234.56";
	cout	<< "balance: " << balance << endl;

	int periodIndex = balance.find(".");
	int commaIndex = periodIndex - 3;
	balance.insert(commaIndex, ",");
	balance.insert(0, "$");
	cout	<< "balance: " << balance << endl;
	getch();
	return 0;

	/*
	 *	Length and Size
	 */
	cout	<< endl << "Length and Size" << endl;
	cout	<< "length: " << balance.length() << endl;
	cout	<< "size: " << balance.size() << endl;
	getch();
	return 0;

	/*
	 *	Replace
	 */
	cout	<< endl << "Replace" << endl;
	string	me	= "I say hello";
	string	you	= "You say hello";
	cout	<< me << " and " << you << endl;

	you.replace(8, 5, "goodbye");

	cout	<< me << " and " << you << endl;
	getch();
	return 0;

	/*
	 *	Substring
	 */
	cout	<< endl << "Substring" << endl;
	string	caesar = "Gaius Julius Caesar";
	string	julius = caesar.substr(6, 6);
	cout	<< caesar << endl;
	cout	<< julius << endl;
	getch();
	return 0;

	/*
	 *	Comparing Strings
	 */
	cout	<< endl << "Comparing Strings" << endl;
			caesar	= "Gaius Julius Caesar";
	string	crassus	= "Marcus Licinius Crassus";
	string	pompey	= "Gnaeus Pompeius Magnus";

	cout	<< "caesar.compare(crassus): " << caesar.compare(crassus) << endl;
	cout	<< "pompey.compare(caesar): " << pompey.compare(caesar) << endl;
	getch();

	string	one = "1";
	string	two = "2";
	string	dos = "2";
	string	five = "5";
	string	twentyTwo = "22";

	cout	<< "two.compare(one): " << two.compare(one) << endl;
	cout	<< "two.compare(dos): " << two.compare(dos) << endl;
	cout	<< "two.compare(five): " << two.compare(five) << endl;
	cout	<< "two.compare(twentyTwo): " << two.compare(twentyTwo) << endl;

	getch();
	return 0;
}