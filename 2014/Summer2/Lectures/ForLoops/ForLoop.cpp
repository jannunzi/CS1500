#include <iostream>
#include <string>
using namespace std;

int main() {

	string num;
	int a;
	int i;
	int total = 0;
	int sum = 0;
	int factorial = 1;
	float average = 0;
	int numberCount = 0;

//	cout << "How many: ";
//	getline(cin, num);
//	numberCount = atoi(num.c_str());

	cout << "start" << endl;

	for (i = 0; true; i++)
	{
		numberCount = i;
		cout << i << ") Number: ";
		getline(cin, num);
		a = atoi(num.c_str());

		if (a < 0)
		{
			break;
		}

		total += a;

		sum += i;
		factorial *= (i+1);
	}

	average = (float) total / numberCount;

	cout << "end" << endl;
	cout << "i = " << i << endl;
	cout << "sum = " << sum << endl;
	cout << "factorial = " << factorial << endl;
	cout << "total = " << total << endl;
	cout << "average = " << average << endl;

}