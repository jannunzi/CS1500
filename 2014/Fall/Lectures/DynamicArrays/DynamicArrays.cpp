#include <iostream>
#include <string>
using namespace std;

void displayIntegerArray(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "] " << arr[i] << endl;
	}
}

int * readIntegerArray(int size) {
	int * arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << i << "/" << size <<  " Enter value: " << endl;
		cin >> arr[i];
	}
	return arr;
}

float calculateAverage(int * arr, int size) {
	float total = 0;
	for (int i = 0; i < size; i++) {
		total += arr[i];
	}
	return (float)total / size;
}

int * append(int a[], int b[], int size_a, int size_b)
{
	int * c = new int[size_a + size_b];
	for (int i = 0; i < size_a; i++)
	{
		c[i] = a[i];
	}
	for (int i = 0; i < size_b; i++)
	{
		c[i + size_a] = b[i];
	}
	return c;
}

int * merge(int A[], int B[], int sizeA, int sizeB)
{
	int sizeC = sizeA + sizeB;
	int * C = new int[sizeC];
	int a = 0, b = 0, c = 0;
	while (a < sizeA && b < sizeB)
	{
		if (A[a] < B[b]) {
			C[c] = A[a];
			c++;
			a++;
		}
		else if (B[b] < A[a]) {
			C[c] = B[b];
			c++;
			b++;
		}
		else
		{
			C[c] = A[a];
			c++;
			a++;
			C[c] = B[b];
			c++;
			b++;
		}
	}
	while (a < sizeA) {
		C[c] = A[a];
		c++;
		a++;
	}
	while (b < sizeB) {
		C[c] = B[b];
		c++;
		b++;
	}
	return C;
}
// {0, 1, 2, 3, 4, 5, 6, 7, 8}
// start = 2
// count = 4
// result = {2, 3, 4, 5}
int * extract(int k[], int size, int start, int count)
{
	int * q = new int[count];
	for (int i = start; i < start + count; i++)
	{
		q[i - start] = k[i];
	}
	return q;
}

int main() {
	//int size;
	//cout << "Size: " << endl;
	//cin >> size;
	//int * grades = new int[size];
	//int total = 0;
	//for (int i = 0; i < size; i++) {
	//	int grade;
	//	cout << i << " Grade: " << endl;
	//	cin >> grades[i];
	//	total += grades[i];
	//}
	//float avg = (float) total / size;

	//displayIntegerArray(grades, size);
	//cout << "Average: " << avg << endl;

	//int * a = readIntegerArray(4);
	//displayIntegerArray(a, 4);

	//cout << calculateAverage(a, 4) << endl;

	int b[] = { 1, 3, 5, 60, 73 };
	int c[] = {56, 67, 78};
	int * k = append(b, c, 5, 3);

	displayIntegerArray(k, 5 + 3);

	int * m = merge(b, c, 5, 3);
	displayIntegerArray(m, 5 + 3);

	int * s = extract(b, 5, 1, 3);
	displayIntegerArray(s, 3);
}
