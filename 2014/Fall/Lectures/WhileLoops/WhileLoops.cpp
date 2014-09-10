#include <iostream>
using namespace std;

int main() {

	const int OPTION_1 = 1;
	const int OPTION_2 = 2;
	const int OPTION_3 = 3;

	cout << "While Loops" << endl;

	int option = 0;
	cout << "[1] Option 1" << endl;
	cout << "[2] Option 2" << endl;
	cout << "[3] Option 3" << endl;
	cout << "[0] Quit" << endl;
	cin >> option;
	while (option != 0) {
		if (option == OPTION_1){
			cout << "Option 1" << endl;
		}
		else if (option == OPTION_2) {
			cout << "Option 2" << endl;
		}
		else if (option == OPTION_3) {
			cout << "Option 3" << endl;
		}
		else {
			cout << "Unknown Option" << endl;
		}
		cout << "[1] Option 1" << endl;
		cout << "[2] Option 2" << endl;
		cout << "[3] Option 3" << endl;
		cout << "[0] Quit" << endl;
		cin >> option;
	}


	int i = 0;
	while (i <= 10) {
		cout << i << endl;
		i++;
	}
	cout << i << endl;
	cout << "Done Looping" << endl;

	int j = 10;
	while (j > 0) {
		cout << j << endl;
		j--;
	}
	cout << "Done Looping Backwards" << endl;

	for (int c = 0; c < 10; c++) {
		cout << c << endl;
	}
	cout << "Done For Loop" << endl;

	int total = 0;
	int grade = 0;
	int count = 0;
	float average = 0.0;
	cin >> grade;
	while (grade >= 0) {
		count++;
		total += grade;
		cin >> grade;
	}
	average = (float) total / count;
	cout << average << endl;
}
