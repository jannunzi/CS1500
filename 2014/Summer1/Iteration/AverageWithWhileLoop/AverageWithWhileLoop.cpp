#include <iostream>
using namespace std;

void main() {
	int total = 0;
	int input = 0;
	float average = 0;
	int count = 0;
	while (input >= 0) {
		cout << "Number: ";
		cin >> input;
		if (input >= 0) {
			total += input;
			count++;
		}
	}
	average = (float)total / count;
	cout << "Average: " << average << endl;

	total = 0;
	count = 0;
	do {
		cout << "Number: ";
		cin >> input;
		if (input >= 0) {
			total += input;
			count++;
		}
	} while (input >= 0);
	average = (float)total / count;
	cout << "Average: " << average << endl;

	getchar();
	getchar();
}
