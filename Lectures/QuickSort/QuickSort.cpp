#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int partition(int haystack[], int start, int end)
{
	int p = start;
	int pValue = haystack[p];

	for (int i = start + 1; i <= end; i++)
	{
		if (haystack[i] > pValue)
		{
			p++;
			swap(haystack, i, p);
		}
	}
	swap(haystack, start, p);
	return p;
}

void quicksort(int haystack[], int start, int end)
{
	if (start < end)
	{
		int p = partition(haystack, start, end);
		quicksort(haystack, start, p - 1);
		quicksort(haystack, p + 1, end);
	}
}

int main()
{
	const int SIZE = 10;
	int haystack[SIZE];
	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
	{
		int value = rand() % SIZE;
		cout << i << " " << value << endl;
		haystack[i] = value;
	}
	
	int pivot = partition(haystack, 0, SIZE);
	cout << "Pivot: " << pivot << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " " << haystack[i] << endl;
	}

	quicksort(haystack, 0, SIZE);
	cout << "Quicksort: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << " " << haystack[i] << endl;
	}
	getchar();
}