#include <iostream>
using namespace std;

void displayIntArray(int arr[], int size);
float averageIntArray(int arr[], int size);
void readIntArray(int arr[], int size);
int* copyArray(int arr[], int size);
int* concatenateIntArrays(int arr1[], int arr2[], int size1, int size2);
int* subArray(int arr[], int size, int start, int count);

int main()
{
	// Read 2 dynamic arrays
	int size1, size2, size3;
	cout << "Size of arr1: ";
	cin >> size1;
	cout << "Size of arr2: ";
	cin >> size2;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	readIntArray(arr1, size1);
	readIntArray(arr2, size2);

	// concatenate two arrays into a third
	int* arr3;
	arr3 = concatenateIntArrays(arr1, arr2, size1, size2);

	size3 = size1 + size2;
	cout << "Concatenated Array:" << endl;
	displayIntArray(arr3, size3);

	getchar();

	// Copy an array
	int* copy = copyArray(arr1, size1);
	cout << "Copied Array:" << endl;
	displayIntArray(copy, size1);

	// Get sub array
	// Read parent array
	int size4;
	cout << "Array Size: ";
	cin >> size4;
	int* arr4 = new int[size4];
	readIntArray(arr4, size4);

	// get sub array
	int start, count;
	cout << "Start: ";
	cin >> start;
	cout << "Count: ";
	cin >> count;
	int* sub = subArray(arr4, size4, start, count);

	// display sub array
	cout << "Sub Array:" << endl;
	displayIntArray(sub, count);

	getchar();
	getchar();
}

int* copyArray(int* originalArray, int size)
{
	int* copy = new int[size];
	for (int i = 0; i < size; i++)
	{
		copy[i] = originalArray[i];
	}
	return copy;
}

void readIntArray(int arr[], int count)
{
	cout << "Reading integer array of size: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
}

void displayIntArray(int arr[], int count)
{
	cout << "Displaying integer array of size: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "[" << i << "] " << arr[i] << endl;
	}
}

float averageIntArray(int arr[], int count)
{
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += arr[i];
	}
	float average = (float)total / count;
	return average;
}

int* concatenateIntArrays(int* arr1, int* arr2, int size1, int size2)
{
	int size3 = size1 + size2;
	int* concat = new int[size3];

	// copy arr1 into arr3
	for (int i = 0; i < size1; i++)
	{
		concat[i] = arr1[i];
	}

	// copy arr2 at the end of arr3
	for (int i = 0; i < size2; i++)
	{
		concat[i + size1] = arr2[i];
	}

	return concat;
}

int* subArray(int arr[], int size, int start, int count)
{
	int* sub = new int[count];
//	for (int i = start; i < start + count; i++)
	for (int i = 0; i < count; i++)
	{
		sub[i] = arr[start + i];
	}
	return sub;
}
