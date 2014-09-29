#include <iostream>
#include <string>
using namespace std;

void displayGrades(int * grades, int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "] " << grades[i] << endl;
	}
}

int main() {
	int size;
	cout << "Size: " << endl;
	cin >> size;
	int * grades = new int[size];
	int total = 0;
	for (int i = 0; i < size; i++) {
		int grade;
		cout << i << " Grade: " << endl;
		cin >> grades[i];
		total += grades[i];
	}
	float avg = (float) total / size;

	displayGrades(grades, size);
	cout << "Average: " << avg << endl;
}
