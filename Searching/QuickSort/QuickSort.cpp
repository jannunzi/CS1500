#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void swap(int values[], int index1, int index2)
{
	int tmp;
	tmp = values[index1];
	values[index1] = values[index2];
	values[index2] = tmp;
}

int partition(int values[], int first, int last)
{
	int p = first;
	int pvalue = values[first];

//	for (int i = first + 1; i <= last; i++)
	for (int i = first + 1; i < last; i++)
	{
		if (values[i] <= pvalue)
		{
			p++;
			swap(values, i, p);
		}
	}
	swap(values, p, first);
	return p;
}

void quicksort(int values[], int start, int end)
{
	if (start > end)
		return;
	int pivot = partition(values, start, end);
	quicksort(values, start, pivot-1);
	quicksort(values, pivot + 1, end);
}

int main()
{
	const int SIZE = 10;

	int t = time(NULL);
	cout << t << endl;

	srand(t);

	int haystack[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "\t";
	}

	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		haystack[i] = rand() % 1000;
		cout << haystack[i] << "\t";
	}
	cout << endl;

	quicksort(haystack, 0, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		cout << haystack[i] << "\t";
	}

	getchar();
}