#include <iostream>
using namespace std;

void main() {
	float average = 0.0;
	float total = 0.0;
	int size = 20;
	for (int i = 0; i < size; i++) {
		total += i;
		cout << i << ") " << total << endl;
	}
	cout << "total: " << total << endl;
	cout << "size: " << size << endl;
	average = total / size;
	cout << "average: " << average << endl;
	getchar();
}
