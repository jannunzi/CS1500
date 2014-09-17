#include <iostream>	// for cout, cin, endl
#include <conio.h>	// for getch()
#include <string>	// for string class
#include <sstream>	// for streaming various data types to a string
using namespace std;

int main() {
	/*
	 *	C String to Integer
	 */
	cout << endl << "C String to Integer" << endl;
	int a = atoi( "2" );
	int b = atoi( "3" );
	int c = a + b;
	cout << c << " = " << a << " + " << b << endl;
	getch();

	/*
	 *	C++ String to Integer
	 */
	cout << endl << "C++ String to Integer" << endl;
	string aString = "3";
	string bString = "4";
	a = atoi( aString.c_str() );
	b = atoi( bString.c_str() );
	c = a + b;
	cout << c << " = " << a << " + " << b << endl;
	getch();

	/*
	 *	C++ String to Float
	 */
	cout << endl << "C++ String to Float" << endl;
	string xString = "3.45";
	string yString = "4.56";
	float x = atof( xString.c_str() );
	float y = atof( yString.c_str() );
	float z = x + y;
	cout << z << " = " << x << " + " << y << endl;
	getch();

	/*
	 *	C++ String to Double
	 */
	cout << endl << "C++ String to Double" << endl;
	string rString = "3.4567890";
	string sString = "4.5678909";
	double r = strtod( rString.c_str(), NULL );
	double s = strtod( sString.c_str(), NULL );
	double t = r + s;
	cout << t << " = " << r << " + " << s << endl;
	getch();

	/*
	 *	Numbers to String
	 */
	cout << endl << "Integers to String" << endl;
	a = 7;
	b = 8;
	x = 9.10;
	y = 10.11;
	string seven;
	string eight;

	stringstream conversionStream;

	conversionStream << a;
	seven = conversionStream.str();
	cout << "seven: " << seven << endl;
	conversionStream.str("");

	conversionStream << b;
	eight = conversionStream.str();
	cout << "eight: " << eight << endl;
	conversionStream.str("");

	string sevenAndEight = seven + eight;
	cout << "sevenAndEight: " << sevenAndEight << endl;
	getch();

	cout << endl << "Float to String" << endl;
	conversionStream << x;
	xString = conversionStream.str();
	cout << "xString: " << xString << endl;
	conversionStream.str("");

	conversionStream << y;
	yString = conversionStream.str();
	cout << "yString: " << yString << endl;
	conversionStream.str("");

	string xAndY = xString + yString;
	cout << "xAndY: " << xAndY << endl;

	getch();
}