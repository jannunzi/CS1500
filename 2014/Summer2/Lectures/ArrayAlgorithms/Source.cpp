#include <iostream>
#include <string>
using namespace std;

int sum(int array[], int length) {
	int total = 0;
	for (int i = 0; i < length; i++) {
		total += array[i];
	}
	return total;
}

int product(int array[], int length) {
	int total = 1;
	for (int i = 0; i < length; i++) {
		total *= array[i];
	}
	return total;
}

int search(int needle, int haystack[], int length) {
	for (int i = 0; i < length; i++) {
		if (needle == haystack[i])
			return i;
	}
}

int minumum(int array[], int length) {
	int min = 100;
	for (int i = 0; i < length; i++) {
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

int maximum(int array[], int length) {
	int max = -1;
	for (int i = 0; i < length; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	cout << sum(a, 5) << endl;
	cout << product(a, 5) << endl;
	cout << search(4, a, 5) << endl;
	cout << minumum(a, 5) << endl;
	cout << maximum(a, 5) << endl;
}
