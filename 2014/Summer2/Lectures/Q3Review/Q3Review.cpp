#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
	int number;
	double balance;
public:
	Account* next = NULL;
	Account(){}
	Account(int number, double balance) {
		setNumber(number);
		setBalance(balance);
	}
	Account(const Account& other) {
		setBalance(other.balance);
		setNumber(other.number);
	}
	virtual void display() {
		cout << number << " $" << balance;
	}
	int getNumber() { return number; }
	void setNumber(int number) { this->number = number; }
	double getBalance() { return balance; }
	void setBalance(double balance) { this->balance = balance; }
};

class SavingsAccount : public Account {
private:
	float interest;
public:
	SavingsAccount(){}
	SavingsAccount(int number, double balance, float interest)
		: Account(number, balance)
	{
		setInterest(interest);
	}
	SavingsAccount(const SavingsAccount& other) : Account(other) {
		setInterest(other.interest);
	}
	void display() {
		Account::display();
		cout << " " << interest << "%" << endl;
	}
	void setInterest(float i) { interest = i; }
	float getInterest() { return interest; }
};

class CheckingAccount : public Account {
private:
	float monthlyFee;
public:
	CheckingAccount(int number, double balance, float monthlyFee)
		: Account(number, balance) {
		setMonthlyFee(monthlyFee);
	}
	CheckingAccount(const CheckingAccount& other) : Account(other) {
		setMonthlyFee(other.monthlyFee);
	}
	void display() {
		Account::display();
		cout << " $" << monthlyFee << endl;
	}
	void setMonthlyFee(float monthlyFee) { this->monthlyFee = monthlyFee; }
	float getMonthlyFee() { return monthlyFee; }
};

void display(Account* head) {
	Account* current = head;
	while (current != NULL) {
		current->display();
		current = current->next;
	}
}

int main() {
	CheckingAccount* c1 = new CheckingAccount(1234, 2345, 50);
	CheckingAccount* c2 = new CheckingAccount(2345, 5423, 51);
	CheckingAccount* c3 = new CheckingAccount(3456, 6543, 52);

	SavingsAccount* s1 = new SavingsAccount(4567, 7654, 10);
	SavingsAccount* s2 = new SavingsAccount(5423, 8765, 11);
	SavingsAccount* s3 = new SavingsAccount(6543, 9876, 12);

	c1->next = c2;
	c2->next = c3;
	c3->next = s1;
	s1->next = s2;
	s2->next = s3;

	display(c1);
}
