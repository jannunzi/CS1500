#include <iostream>		// for cout and cin
#include <conio.h>		// for getch()
using namespace std;	// for cout and cin

// these are function prototypes which are defined later in the source
void tryToChangeX ( int x );
void reallyChangeX ( int &x );
int functionWithLocalVariables ( int localParameter );
void functionAccessingGlobalVariables();

int badGlobalVariable = 100;
const int GOOD_CONSTANT = 234;

int main() {

	functionAccessingGlobalVariables ();
	getch();

	int localVariable = functionWithLocalVariables ( 20 );
	cout << "This localVariable: " << localVariable << " is not the same as the one declared in functionWithLocalVariables()" << endl << endl;
	getch();

	int x = 5;
	tryToChangeX ( x );
	cout << "Nope, x is still: " << x << endl << endl;
	getch();

	reallyChangeX ( x );
	cout << "Yep, x has really changed to: " << x << endl << endl;
	getch();
}

int functionWithLocalVariables ( int localParameter ) {
	int localVariable = 10;
	int localReturnValue = localVariable + localParameter;
	return localReturnValue;
}

void functionAccessingGlobalVariables () {
	int localVariable = badGlobalVariable;
	cout << "Avoid using global variables: " << localVariable << endl;
	badGlobalVariable++;
	cout << "Because ANYONE (who?) can change a global variable: " << badGlobalVariable << endl << endl;
}

void tryToChangeX ( int x ) {
	x = 3;
	cout << "I'm trying to change the value of x to: " << x << endl;
}

void reallyChangeX ( int &x ) {
	x = 3;
	cout << "Now I have really changed the value of x to: " << x << endl;
}
