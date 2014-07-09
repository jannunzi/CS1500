#include <iostream>
using namespace std;

const int SIZE = 14;

void printArray(int a[]) {
	for (int i = 0; i < SIZE; i++){
		cout << "[" << i << "]\t" << a[i] << endl;
	}
}

void selectionSort(int a[]) {
	int cost = 0;
	for (int start = 0; start < SIZE; start++) {
		int smallest = start;
		for (int i = start; i < SIZE; i++) {
			cost++;
			if (a[i] < a[smallest]) {
				smallest = i;
			}
		}
		if (smallest != start) {
			int temp = a[smallest];
			a[smallest] = a[start];
			a[start] = temp;
		}
	}
	cout << "Selection Sort Cost = " << cost << endl;
}

void bubbleSort(int a[]) {
	int cost = 0;
	bool swap = true;
	while (swap) {
		swap = false;
		for (int i = 0; i < SIZE - 1; i++) {
			cost++;
			if (a[i] > a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swap = true;
			}
		}
	}
	cout << "Bubble Sort Cost = " << cost << endl;
}

int qCost = 0;

int partition(int a[], int bottom, int top) {
	int pivot = bottom;
	int pivotValue = a[pivot];
	for (int i = bottom + 1; i <= top; i++) {
		qCost++;
		if (a[i] < pivotValue) {
			pivot++;
			int temp = a[i];
			a[i] = a[pivot];
			a[pivot] = temp;
		}
	}
	int temp = a[bottom];
	a[bottom] = a[pivot];
	a[pivot] = temp;

	return pivot;
}

void quickSort(int a[], int bottom, int top) {
	if (bottom < top) {
		int pivot = partition(a, bottom, top);
		quickSort(a, bottom, pivot - 1);
		quickSort(a, pivot + 1, top);
	}
}

int main()
{
	int a[] = { 12, 89, 23, 90, 34, 78, 45, 56, 21, 54, 98, 32, 65, 87 };
//	int a[] = { 90, 89, 85, 78, 74, 67, 63, 56, 41, 45, 34, 23, 12, 5};
	cout << "Before Selection Sort" << endl;
	printArray(a);
	selectionSort(a);
	cout << "After Selection Sort" << endl;
	printArray(a);

	int b[] = { 12, 89, 23, 90, 34, 78, 45, 56, 21, 54, 98, 32, 65, 87 };
	cout << "\n\nBefore Bubble Sort" << endl;
	printArray(b);
	bubbleSort(b);
	cout << "After Bubble Sort" << endl;
	printArray(b);

//	int c[] = { 12, 89, 23, 90, 34, 78, 45, 56, 21, 54, 98, 32, 65, 87 };
	int c[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100, 110, 120, 130, 140};
	cout << "\n\nBefore Quick Sort" << endl;
	printArray(c);
	quickSort(c, 0, SIZE-1);
	cout << "After Quick Sort" << endl;
	printArray(c);
	cout << "qCost = " << qCost << endl;
}
