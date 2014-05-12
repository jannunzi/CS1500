#include <iostream>
#include <string>
using namespace std;

void displayApplication(int appIndex, string appNames[], float appPrices[]);
void displayAllApplication(string appNames[], float appPrices[], int appCount);
void swapApps(int appIndex1, int appIndex2, string appNames[], float appPrices[]);
int  pivot(int first, int last, string appNames[], float appPrices[]);
void quickSort(int first, int last, string appNames[], float appPrices[]);
int  binarySearchForPrice(float searchPrice, int first, int last, float appPrices[]);

void main()
{
	string appNames[] =
	{
		"Pages", "Keynote", "Numbers",
		"Word", "PowerPoint", "Excel",
		"Documents", "Presentation", "Sheets"
	};

	float appPrices[] =
	{
		3.99, 2.99, 1.99,
		19.99, 29.99, 39.99,
		34.99, 24.99, 14.99
	};

	displayAllApplication(appNames, appPrices, 9);
	quickSort(0, 8, appNames, appPrices);
	displayAllApplication(appNames, appPrices, 9);
	int foundIndex = binarySearchForPrice(25.99, 0, 9, appPrices);

	if (foundIndex == -1)
	{
		cout << "Not Found" << endl;
	}
	else
	{
		cout << "Found at index " << foundIndex << endl;
	}

	getchar();
}

int pivot(int first, int last, string appNames [], float appPrices[])
{
	int  p = first;
	int pivotElement = appPrices[first];

	for (int i = first + 1; i <= last; i++)
	{
		if (appPrices[i] <= pivotElement)
		{
			p++;
			swapApps(i, p, appNames, appPrices);
		}
	}

	swapApps(p, first, appNames, appPrices);

	return p;
}

void quickSort(int first, int last, string appNames[], float appPrices[])
{
	int pivotElement;

	if (first < last)
	{
		pivotElement = pivot(first, last,  appNames, appPrices);
		quickSort(first, pivotElement - 1, appNames, appPrices);
		quickSort(pivotElement + 1, last,  appNames, appPrices);
	}
}

void displayApplication(int appIndex, string appNames[], float appPrices[])
{
	cout << appNames[appIndex] << " $" << appPrices[appIndex] << endl;
}

void displayAllApplication(string appNames[], float appPrices[], int appCount)
{
	cout << "Applications:" << endl;
	for (int i = 0; i < appCount; i++)
	{
		cout << i << ") ";
		displayApplication(i, appNames, appPrices);
	}
}

void swapApps(int appIndex1, int appIndex2, string appNames[], float appPrices[])
{
	string tempAppName;
	float tempAppPrice;

	tempAppName = appNames[appIndex1];
	appNames[appIndex1] = appNames[appIndex2];
	appNames[appIndex2] = tempAppName;

	tempAppPrice = appPrices[appIndex1];
	appPrices[appIndex1] = appPrices[appIndex2];
	appPrices[appIndex2] = tempAppPrice;
}

int  binarySearchForPrice(float searchPrice, int first, int last, float appPrices[])
{
	if (first > last)
	{
		cout << "Did not find $" << searchPrice << endl;
		return -1;
	}

	int middle = (first + last) / 2;
	cout << "binarySearchForPrice: " << first << " " << middle << " " << last << " $" << searchPrice << " $" << appPrices[middle] << endl;
	getchar();

	if (searchPrice == appPrices[middle])
	{
		cout << "Found $" << searchPrice << " at index " << middle << endl;
		return middle;
	}
	else if (searchPrice > appPrices[middle])
	{
		return binarySearchForPrice(searchPrice, middle + 1, last, appPrices);
	}
	else if (searchPrice < appPrices[middle])
	{
		return binarySearchForPrice(searchPrice, first, middle - 1, appPrices);
	}
}
