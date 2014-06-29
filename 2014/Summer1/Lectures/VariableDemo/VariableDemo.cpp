#include <iostream>		// for cout and cin
#include <conio.h>		// for getch()
using namespace std;	// for cout and cin

#define PI 3.14159

int main() {

	/*
	 *	Numerical Data Type Example
	 */

	cout << "Numerical Data Type Example" << endl;

	double	principalAmount = 1234.56;
	double	annualInterestRate = 12.5;
	int		timesCompoundedPerYear = 12;
	int		numberOfYears = 20;
	double	compoundInterest = 13456.78;

	cout	<< "Principal: $";
	cin		>> principalAmount;

	cout	<< "Interest: %";
	cin		>>	annualInterestRate;
	annualInterestRate = annualInterestRate / 100;

	cout	<< "Years: ";
	cin		>>	numberOfYears;

	cout	<< "Times compounded per year: ";
	cin		>>	timesCompoundedPerYear;

	// ... calculate compound interest ...

	cout	<< "Compound Interest: $";
	cout	<<	compoundInterest << endl;

	getch();
//	return 0;

	/*
	 *	Floating Point and Integers
	 */
	cout	<< "Floating Point and Integers" << endl;
	double	doubleNumber	= 1234.5678;
	float	floatNumber		= 2345.6789;
	int		integerNumber	= doubleNumber;
	
	cout	<< "doubleNumber: " << doubleNumber << endl;
	cout	<< "integerNumber: " << integerNumber << endl;

	integerNumber	= floatNumber;
	cout	<< "floatNumber: " << floatNumber << endl;
	cout	<< "integerNumber: " << integerNumber << endl;
	getch();
	// return 0;

	/*
	 *	E Notation
	 */
	cout	<< "E Notation" << endl;
	float	distance	= 1.4054234543E11;
	double	mass		= 1.3234E30;

	cout	<< "The Sun is " << distance << " away\n";
	cout	<< "The Sun's mass is " << mass << " Kg\n";
	getch();
	// return 0;

	/*
	 *	Named Constants
	 */
	cout << "Named Constants" << endl;
	const int	DEPOSIT_TRANSACTION = 1;
	const int	WITHDRAW_TRANSACTION = 2;
	int			transactionChoice;

	cout	<< "Transaction: " << endl;
	cout	<< "[1] Deposit: " << endl;
	cout	<< "[2] Withdraw: " << endl;
	cin		>> transactionChoice;
	if(transactionChoice == DEPOSIT_TRANSACTION)
		cout << "You chose Deposit Transaction" << endl;
	if(transactionChoice == WITHDRAW_TRANSACTION)
		cout << "You chose Withdraw Transaction" << endl;

	getch();
//	return 0;

	/*
	 *	Define Directive
	 */
	cout << "Define Directive" << endl;
	cout << "#define PI = " << PI;
	getch();
	return 0;
}