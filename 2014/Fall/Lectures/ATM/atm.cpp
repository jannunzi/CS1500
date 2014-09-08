#include <iostream>
using namespace std;

int main() {

	int pin = 0;
	int transaction = 0;
	float amount = 0.0;
	float balance = 1000.0;
	const int DEPOSIT = 1;
	const int WITHDRAW = 2;

	cout << "ATM Booting Up" << endl;

	cout << "Enter PIN #" << endl;
	cin >> pin;

	cout << pin << endl;

	if (pin == 1234)
	{
		cout << "Hello Dave" << endl;

		cout << "Choose a transaction from below" << endl;
		cout << "[1] Deposit" << endl;
		cout << "[2] Withdraw" << endl;
		cin >> transaction;

		cout << "Amount" << endl;
		cin >> amount;

		if (transaction == DEPOSIT)
		{
			balance += amount;
		}
		else if (transaction == WITHDRAW)
		{
			balance -= amount;
		}
		else
		{
			cout << "Unknown Operation" << endl;
		}
		
		cout << "New Balance $" << balance << endl;

	}
	else
	{
		cout << "Good Bye!" << endl;
	}
}
