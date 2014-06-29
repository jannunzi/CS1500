#include <iostream>
#include <string>
#include <time.h>
using namespace std;


void mergeArrays(int a[], int b[], int c[], int aSize, int bSize, int cSize)
{
	int aIndex = 0, bIndex = 0, cIndex = 0;
	cout << "mergeArrays " << aSize << " " << bSize << " " << cSize << " " << aIndex << " " << bIndex << endl;
	while (aIndex < aSize && bIndex < bSize)
	{
		if (a[aIndex] < b[bIndex])
		{
			c[cIndex] = a[aIndex];
			cIndex++;
			aIndex++;
		}
		else if (a[aIndex] > b[bIndex])
		{
			c[cIndex] = b[bIndex];
			cIndex++;
			bIndex++;
		}
		else if (a[aIndex] == b[bIndex])
		{
			c[cIndex] = b[bIndex];
			cIndex++;
			bIndex++;
			aIndex++;
		}
	}
	while (aIndex < aSize)
	{
		c[cIndex] = a[aIndex];
		cIndex++;
		aIndex++;
	}
	while (bIndex < bSize)
	{
		c[cIndex] = b[bIndex];
		cIndex++;
		bIndex++;
	}
}

void mergeSort(int values[], int first, int last)
{
	if (first > last)
	{
		return;
	}
	int mid = (first + last) / 2;
	mergeSort(values, first, mid);
	mergeSort(values, mid + 2, last);
}

int main()
{
	const int SIZE = 10;

	srand(time(NULL));

	int haystack[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		haystack[i] = rand() % 1000;
		//		cout << i << ") " << haystack[i] << endl;
		cout << haystack[i] << "\t";
	}
	cout << endl;

	mergeSort(haystack, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
	{
		//		cout << i << ") " << haystack[i] << endl;
		cout << haystack[i] << "\t";
	}
	getchar();
}