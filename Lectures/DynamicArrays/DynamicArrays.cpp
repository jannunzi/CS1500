#include <iostream>
using namespace std;

int* mergeIntArrays(int* aa, int* bb, int aSize, int bSize)
{
	cout << "mergeIntArrays" << endl;
	int* cc = new int[aSize + bSize];

	int a=0, b=0, c=0;

	do
	{
		if (aa[a] < bb[b])
		{
			cc[c] = aa[a];
			c++;
			a++;
		}
		else if (bb[b] < aa[a])
		{
			cc[c] = bb[b];
			c++;
			b++;
		}
		else
		{
			cc[c] = aa[a];
			c++;
			cc[c] = bb[b];
			c++;
			b++;
			a++;
		}
	} while (a < aSize && b < bSize);

	while (a < aSize)
	{
		cc[c] = aa[a];
		a++;
		c++;
	}

	while (b < bSize)
	{
		cc[c] = bb[b];
		b++;
		c++;
	}

	return cc;
}


int* concatenateIntArrays(int a[], int b[], int aSize, int bSize)
{
	cout << "concatenateIntArrays()" << endl;
	cout << a << endl;
	cout << b << endl;

	int* c = new int[aSize + bSize];

	for (int i = 0; i < aSize; i++)
	{
		c[i] = a[i];
	}

	for (int i = 0; i < bSize; i++)
	{
		c[i+aSize] = b[i];
	}

	return c;
}


int* createIntArray(int size)
{
	int* x = new int[size];
	return x;
//	return new int[size];
}

void displayIntArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "] " << arr+i << " " << arr[i] << endl;
	}
}

int main()
{
	int a[] = {12,23,34,45};

	int n;
	cin >> n;
	int* b = new int[n];

	cout << b << endl;
	cout << b + 1 << endl;
	cout << b + 2 << endl;
	cout << b + 3 << endl;

	*b = 12;
	*(b + 1) = 23;
	*(b + 2) = 34;
	b[3] = 45;
	b[4] = 56;

	cout << *b << endl;
	cout << *(b + 1) << endl;
	cout << *(b + 2) << endl;

	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[2] << endl;
	cout << *(b + 3) << endl;
	cout << *(b + 4) << endl;


	int* newArray = createIntArray(n);
	cout << newArray << endl;
	newArray[0] = 123;
	newArray[1] = 234;
	displayIntArray(newArray, n);

	int aSize, bSize;
	cout << "A Size: ";
	cin >> aSize;
//	getchar();
	cout << "B Size: ";
	cin >> bSize;
//	getchar();
	int* aa = new int[aSize];
	int* bb = new int[bSize];
	cout << "Values for aa" << endl;
	for (int i = 0; i < aSize; i++)
	{
		cin >> aa[i];
	}
	cout << "Values for bb" << endl;
	for (int i = 0; i < bSize; i++)
	{
		cin >> bb[i];
	}

	int* cc = concatenateIntArrays(aa, bb, aSize, bSize);
	displayIntArray(cc, aSize + bSize);

	cc = mergeIntArrays(aa, bb, aSize, bSize);
	displayIntArray(cc, aSize + bSize);

	getchar();
	getchar();
}
