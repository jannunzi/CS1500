#include <iostream>
#include <string>
using namespace std;

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "[" << i << "] = " << array[i] << endl;
	}
}

void bubbleSort(int array[], int length)
{
	bool swapped = true;
	int temp = 0;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < length-1; i++) {
			if (array[i]>array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

void selectionSort(int a[], int length)
{
	int temp;
	for (int i = 0; i < length - 1; i++){
		int min = i;
		for (int j = i + 1; j < length; j++){
			if (a[j] < a[min] ) {
				min = j;
			}
		}
		if (min != i){
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int b, int t)
{
	int p = b;
	int pValue = a[p];
	for (int i = b + 1; i <= t; i++)
	{
		if (a[i] <= pValue) {
			p++;
			swap(a[i], a[p]);
		}
	}
	swap(a[p], a[b]);
	return p;
}

void quickSort(int a[], int b, int t)
{
	if (b < t)
	{
		int p = partition(a, b, t);
		quickSort(a, b, p - 1);
		quickSort(a, p + 1, t);
	}
}

int main()
{
	int input[] = { 21, 66, 43, 88, 34, 9, 65, 32, 67 };
	printArray(input, 9);
//	bubbleSort(input, 9);
//	selectionSort(input, 9);
	quickSort(input, 0, 8);
	printArray(input, 9);
}