#include <iostream>
using namespace std;

void printArray(int a[], int size) {
	cout << "----" << endl;
	for (int i = 0; i < size; i++) {
		cout << a[i] << endl;
	}
}

int* copyArray(int a[], int size) {
	int* copy = new int[size];
	for (int i = 0; i < size; i++) {
		copy[i] = a[i];
	}
	return copy;
}

int frequency(int a[], int size, int sample) {
	int total = 0;

	for (int i = 0; i < size; i++) {
		if (a[i] == sample)
			total++;
	}

	return total;
}

float classAverage(int grades[], int size) {
	float total = 0;

	for (int i = 0; i < size; i++) {
		total += grades[i];
	}

	return total / size;
}

int* getPassingGrades(int grades[], int size) {
	int passingSize = 0;
	for (int i = 0; i < size; i++) {
		if (grades[i] > 65)
			passingSize++;
	}

	int* passingArray = new int[passingSize];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (grades[i] > 65) {
			passingArray[j] = grades[i];
			j++;
		}
	}
	printArray(passingArray, passingSize);

	return passingArray;
}

int* concatenate(int a[], int b[], int la, int lb) {
	int newSize = la + lb;
	int* c = new int[newSize];

	cout << "Concatenate" << endl;
	printArray(a, la);
	printArray(b, lb);

	// copy first array to new array
	for (int i = 0; i < la; i++) {
		c[i] = a[i];
	}

	for (int j = 0; j < lb; j++) {
		c[j + la] = b[j];
	}

	printArray(c, newSize);

	return c;
}

int* merge(int A[], int B[], int la, int lb) {
	int lc = la + lb;
	int* C = new int[lc];

	int a = 0, b = 0, c = 0;

	cout << "A[]" << endl;
	printArray(A, la);
	cout << "B[]" << endl;
	printArray(B, lb);

	while (a < la && b < lb) {
		if (A[a] <= B[b]) {
			C[c] = A[a];
			a++;
			c++;
		}
		else if (B[b] <= A[a]) {
			C[c] = B[b];
			b++;
			c++;
		}
	}

	while (a < la) {
		C[c] = A[a];
		a++;
		c++;
	}

	while (b < lb) {
		C[c] = B[b];
		b++;
		c++;
	}

	cout << "C[]" << endl;
	printArray(C, lc);

	return C;
}

int main() {

	int q[] = { 12, 23, 34 };
	int w[] = { 16, 25, 30, 56, 70 };
	int* m = merge(q, w, 3, 4);
	int* e = concatenate(q, w, 3, 4);

	int classSize;
	cout << "Class Size: ";
	cin >> classSize;
	int* grades = new int[classSize];
	for (int i = 0; i < classSize; i++) {
		cout << "Grade " << i << ": ";
		cin >> grades[i];
	}
	printArray(grades, classSize);
	float average = classAverage(grades, classSize);
	cout << "Class Average: " << average << endl;

	int frequencyOfFails = frequency(grades, classSize, 65);
	cout << "Frequency of fails: " << frequencyOfFails << endl;

	int* passedCourse = getPassingGrades(grades, classSize);

	int a[] = { 12, 23, 34, 45 };

	int b;
	cin >> b;
	int* c = new int[b];
	c[0] = 12;
	c[1] = 23;
	printArray(c, b);
	int* d = copyArray(c, b);
	printArray(d, b);
}