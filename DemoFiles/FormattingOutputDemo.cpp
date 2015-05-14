#include <iostream>	// for cout, cin, endl
#include <iomanip>	// for setw()
#include <conio.h>	// for getch()
using namespace std;

int main() {

	cout << endl << "Set Decimal Precision" << endl;
	getch();
	return 0;

	double a,b,c;
	a = 3.1415926534;
	b = 2006.0;
	c = 1.0e-10;
	double PI = 3.14159;
	int n = -77;

	cout << endl << "Left and Right Justification" << endl;
	cout.width(6); cout << left << n << endl;
	cout.width(6); cout << internal << n << endl;
	cout.width(6); cout << right << n << endl;
	getch();
	return 0;

	cout << endl << "Set Decimal Precision" << endl;
	cout << setprecision(5) << PI << endl;
	cout << setprecision(9) << PI << endl;
	cout << fixed;
	cout << setprecision(5) << PI << endl;
	cout << setprecision(9) << PI << endl;
	getch();
	return 0;

	cout << endl << "Fixed and Scientific Notation" << endl;
	cout.precision(5);
	cout				<< a << '\t' << b << '\t' << c << endl;
	cout << fixed		<< a << '\t' << b << '\t' << c << endl;
	cout << scientific	<< a << '\t' << b << '\t' << c << endl;
	getch();
	return 0;

	cout << endl << "Show No Show Point" << endl;
	a=30.0;
	b=10000.0;
	cout.precision(5);
	cout <<   showpoint << a << '\t' << b << '\t' << PI << endl;
	cout << noshowpoint << a << '\t' << b << '\t' << PI << endl;
	getch();
	return 0;

	cout << "Set Field Width" << endl;
	cout << setw(10);
	cout << 77 << endl;
	getch();
	return 0;

	cout << endl << "Set Field Width Example" << endl;
	cout << setw(12) << "Date";
	cout << setw(12) << "Transaction";
	cout << setw(12) << "Amount";
	cout << setw(12) << "Balance" << endl;
	cout << setw(12) << "1/1/12";
	cout << setw(12) << "Deposit";
	cout << setw(12) << "$1,234.56";
	cout << setw(12) << "$2,345.67" << endl;
	getch();
	return 0;
}
