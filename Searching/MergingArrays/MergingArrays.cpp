#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void mergeArrays(int a[], int b[], int c[], int aSize, int bSize, int cSize)
{
	int aIndex = 0, bIndex = 0, cIndex = 0;

	while (aIndex < aSize && bIndex < bIndex)
	{
		if (a[aIndex] > b[bIndex])
		{
			c[cIndex] = a[aIndex];
			cIndex++;
			aIndex++;
		}
		else if (a[aIndex] < b[bIndex])
		{
			c[cIndex] = b[bIndex];
			cIndex++;
			bIndex++;
		}
		else
		{
			c[cIndex] = b[bIndex];
			cIndex++;
			bIndex++;
			aIndex++;
		}
	}
}

const int A_SIZE = 10;
const int B_SIZE = 10;
const int C_SIZE = A_SIZE + B_SIZE;

int main()
{
	int maxSize = A_SIZE > B_SIZE ? A_SIZE : B_SIZE;

	srand(time(NULL));

	int a[A_SIZE];
	int b[B_SIZE];
	int c[C_SIZE];

	for (int i = 0; i < maxSize; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < A_SIZE; i++)
	{
		a[i] = rand() % 1000;
		cout << a[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < B_SIZE; i++)
	{
		b[i] = rand() % 1000;
		cout << b[i] << "\t";
	}
	cout << endl;

	mergeArrays(a, b, c, A_SIZE, B_SIZE, C_SIZE);

	for (int i = 0; i < C_SIZE; i++)
	{
		cout << c[i] << "\t";
	}
	getchar();
}