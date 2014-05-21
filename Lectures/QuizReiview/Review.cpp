#include <iostream>
#include <string>
using namespace std;

int pivot(int a[], int start, int end);
int* concatArrays(int a[], int b[], int aSize, int bSize);

void displayArray(string name, int arr[], int size)
{
	cout << name << endl;
	for (int i = 0; i < size; i++)
	{
		cout << name << "[" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}

int* merge(int* a, int* b, int asize, int bsize)
{
	int* c = new int[asize + bsize];
	int ai = 0, bi = 0, ci = 0;
	while (ai < asize && bi < bsize)
	{
		if (a[ai] < b[bi])
		{
			c[ci++] = a[ai++];
		}
		else if (b[bi] < a[ai])
		{
			c[ci++] = b[bi++];
		}
		else
		{
			c[ci++] = b[bi++];
			c[ci++] = a[ai++];
		}
	}
	while (ai < asize)
	{
		c[ci++] = a[ai++];
	}
	while (bi < bsize)
	{
		c[ci++] = b[bi++];
	}
	return c;
}

int* addArrays(int* a, int* b, int asize, int bsize)
{
	int csize = asize > bsize ? asize : bsize;
	if (asize > bsize)
		csize = asize;
	else
		csize = bsize;

	int* c = new int[csize];

	if (asize < bsize)
	{
		for (int i = 0; i < asize; i++)
		{
			c[i] = a[i] + b[i];
		}
	}
}

int main()
{
	int aa[] = { 1, 3, 5, 7, 9 };
	int bb[] = { 2,4,6,8,10,12,14,16 };
	int* merged = merge(aa, bb, 5, 8);
	displayArray("merged", merged, 13);

	int a[11] = {5,9,2,8,3,7,3,7};

	int p = pivot(a, 0, 10);
	cout << "p: " << p << endl;
	displayArray("a", a, 10);

	int b[5];
	b[0] = 21;
	b[1] = 32;
	b[2] = 43;
	b[3] = 54;
	b[4] = 65;

	displayArray("a", a, 4);
	displayArray("b", b, 5);

	int* c = new int[6];

	int dSize;
	cout << "Size of D?" << endl;
	cin >> dSize;
	int* d = new int[dSize];
	d[0] = 11;
	d[1] = 22;
	d[2] = 33;
	d[3] = 44;
	d[4] = 55;
	d[5] = 66;

	int* concat = concatArrays(d, b, dSize, 5);
	displayArray("concat", c, 5 + dSize);

	getchar();
	getchar();
}

int pivot(int a[], int start, int end)
{
	int p = start;
	int pv = a[p];
	for (int i = start + 1; i <= end; i++)
	{
		if (a[i] < pv)
		{
			p++;
			swap(a[p], a[i]);
		}
	}
	swap(a[start], a[p]);
	return p;
}

int* concatArrays(int* a, int* b, int aSize, int bSize)
{
	int* c = new int[aSize + bSize];
	for (int i = 0; i < aSize; i++)
	{
		c[i] = a[i];
	}
	for (int i = aSize; i < aSize + bSize; i++)
	{
		c[aSize] = b[i - aSize];
	}
	return c;
}