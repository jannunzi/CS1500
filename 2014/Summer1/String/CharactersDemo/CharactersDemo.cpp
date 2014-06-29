#include <iostream>		// for cout and cin
#include <conio.h>		// for getch()
using namespace std;	// for cout and cin

int main() {

	/*
	 *	Regular Characters
	 */
	cout << "Regular Characters" << endl;
	char A = 'A';
	char B = 'B';
	cout << A << endl;
	cout << B << endl;
	getch();
	return 0;

	/*
	 *	Ascii value of a character. @see http://www.asciitable.com/
	 */
	cout << "Ascii value of a character" << endl;
	int asciiA = (int)A;
	cout << "ASCII of 'A': " << asciiA << endl;
	getch();
	return 0;

	/*
	 *	Characters as integers
	 */
	cout << "Characters as integers" << endl;
	char C = A + 2;
	cout << C << " = 'A' + 2" << endl;
	getch();

	int asciiC = (int)C;
	cout << "ASCII of 'C': " << asciiC << endl;
	getch();
	return 0;

	/*
	 *	Integers as characters
	 */
	cout << "Integers as characters" << endl;
	char charZ = 90;
	cout << "Character for integer 90: " << charZ << endl;
	getch();
	return 0;

	/*
	 *	ASCII Code List
	 */
	cout << endl << "ASCII Code List" << endl;
	char character;
	int ascii;
	for(ascii=0; ascii<255; ascii++) {
		character = ascii;
		cout << ascii << " = " << character << endl;
	}
	getch();
	return 0;


	/*
	 *	Character functions
	 */
	cout << "Character functions" << endl;
	char lowerCaseA = 'a';
	char upperCaseA = 'A';
	char number1 = '1';
	char questionMark = '?';

	cout << "isalpha('a'): " << isalpha(lowerCaseA) << endl;
	cout << "isalpha('1'): " << isalpha(number1) << endl;
	cout << "isalpha('?'): " << isalpha(questionMark) << endl;
	getch();
	cout << "isdigit('a'): " << isdigit(lowerCaseA) << endl;
	cout << "isdigit('1'): " << isdigit(number1) << endl;
	cout << "isdigit('?'): " << isdigit(questionMark) << endl;
	getch();
	cout << "isalnum('a'): " << isalnum(lowerCaseA) << endl;
	cout << "isalnum('1'): " << isalnum(number1) << endl;
	cout << "isalnum('?'): " << isalnum(questionMark) << endl;
	getch();
	cout << "ispunct('a'): " << ispunct(lowerCaseA) << endl;
	cout << "ispunct('1'): " << ispunct(number1) << endl;
	cout << "ispunct('?'): " << ispunct(questionMark) << endl;
	getch();
	cout << "isupper('a'): " << isupper(lowerCaseA) << endl;
	cout << "isupper('A'): " << isupper(upperCaseA) << endl;
	cout << "isupper('1'): " << isupper(number1) << endl;
	cout << "isupper('?'): " << isupper(questionMark) << endl;
	getch();
	cout << "islower('a'): " << islower(lowerCaseA) << endl;
	cout << "islower('A'): " << islower(upperCaseA) << endl;
	cout << "islower('1'): " << islower(number1) << endl;
	cout << "islower('?'): " << islower(questionMark) << endl;
	getch();
	cout << "toupper('a'): " << toupper(lowerCaseA) << endl;
	cout << "toupper('A'): " << toupper(upperCaseA) << endl;
	cout << "tolower('a'): " << tolower(lowerCaseA) << endl;
	cout << "tolower('A'): " << tolower(upperCaseA) << endl;
	getch();
	return 0;
}