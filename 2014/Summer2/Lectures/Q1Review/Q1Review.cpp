#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(char word[], int length)
{
	int i = 0, j = length-1;
	while (i < j) {
		if (word[i] != word[j])
			return false;
		i++;
		j--;
	}
	return true;
}

float totalTransactions(
	string types[], string descs[], float amounts[],
	string transactionType,
	string description, int size)
{
	float totalAmount = 0;
	for (int i = 0; i < size; i++) {
		if (types[i] == transactionType
			&& descs[i] == description) {
//			totalAmount += amounts[i];
			totalAmount = totalAmount + amounts[i];
		}
	}
	return totalAmount;
}

float getAverageSpending(
	string types[], string descs[], float amounts[],int size)
{
	float totalWithdraws = 0;
	int totalWithdrawCount = 0;
	for (int i = 0; i < size; i++) {
		if (types[i] == "WITHDRAW") {
			totalWithdraws += amounts[i];
			totalWithdrawCount++;
		}
	}
	return totalWithdraws / totalWithdrawCount;
}

const int NAME = 0, SPECIALTY = 1, SALARY = 2, START_DATE = 3;

void select(int fields[], int len, string names[], string specialties[], float salaries[], string dates[], int size) {
	for (int i = 0; i < size; i++) {
		for (int f = 0; f < len; f++) {
			if (fields[f] == NAME) {
				cout << names[i];
			}
			else if (fields[f] == SPECIALTY) {
				cout << specialties[i];
			}
			else if (fields[f] == SALARY) {
				cout << salaries[i];
			}
			else if (fields[f] == START_DATE) {
				cout << dates[i];
			}
			cout << " ";
 		}
		cout << endl;
	}
}

void swap(int & x, int & y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {

	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;

//	char word[] = { 'c', 'i', 'v', 'i', 'c' };
	char word[] = { 'c', 'i', 'v', 'v', 'i', 'c' };
	cout << isPalindrome(word, 6) << endl;

	string dates[] = {"07/11/2012 02:23:34","07/11/2012 02:23:35", "07/12/2012 14:23:36", "07/12/2012 16:23:37", "07/13/2012 06:23:38", "07/13/2012 08:23:39", "08/11/2012 02:23:35"};
	string types[] = { "DEPOSIT", "DEPOSIT", "WITHDRAW", "DEPOSIT", "WITHDRAW", "WITHDRAW", "DEPOSIT" };
	string descs[] = {"opened", "wages", "groceries", "tips", "gifts", "games", "wages"};
	float  amounts[] = {1234.43, 2345.54,3456.76,4567.87,5678.87,6789.98, 7890.09};
	float  balances[] = {4321,5423,6534,7654,8765,986,8765};

	cout << totalTransactions(types, descs, amounts, "DEPOSIT", "wages", 7) << endl;
	cout << getAverageSpending(types, descs, amounts, 7) << endl;

	string names[] = {"Luke", "Han", "Ben", "Leia", "Anakin"};
	string specialties[] = { "jedi", "pirate", "jedi", "princes", "sith" };
	float salaries[] = {1234.43, 2345.54,3465.65,4567.76, 5687.87};
//	string dates[] = {"2013-08-12", "2013-12-23", "2013-07-18", "2013-09-25", "2013-03-09"};

	int fields1[] = { NAME, SALARY };
	int fields2[] = { SPECIALTY, START_DATE };
	int fields3[] = { NAME };
	int fields4[] = { SALARY, NAME, SPECIALTY, START_DATE, SPECIALTY, NAME };

	select(fields1, 2, names, specialties, salaries, dates, 5);
	select(fields2, 2, names, specialties, salaries, dates, 5);
	select(fields3, 1, names, specialties, salaries, dates, 5);
	select(fields4, 6, names, specialties, salaries, dates, 5);
}
