#include <iostream>
#include <string>
using namespace std;

void displayAllApplicationNames(string appNames[], int appCount);
void swapAppNames(int appIndex1, int appIndex2, string appNames[]);
int  pivot(int first, int last, string appNames[]);
void quickSort(int first, int last, string appNames[]);

void main()
{
	string appNames[] =
	{
		"Pages", "Keynote", "Numbers",
		"Word", "PowerPoint", "Excel",
		"Documents", "Presentation", "Sheets"
	};

	displayAllApplicationNames(appNames, 9);
	quickSort(0, 8, appNames);
	displayAllApplicationNames(appNames, 9);

	getchar();
}

void displayAllApplicationNames(string appNames[], int appCount)
{
	cout << "Applications Names:" << endl;
	for (int i = 0; i < appCount; i++)
	{
		cout << i << ") " << appNames[i] << endl;
	}
}

void swapAppNames(int appIndex1, int appIndex2, string appNames[])
{
	string tempAppName;
	float tempAppPrice;

	tempAppName = appNames[appIndex1];
	appNames[appIndex1] = appNames[appIndex2];
	appNames[appIndex2] = tempAppName;
}


int pivot(int first, int last, string appNames[])
{
	int  p = first;
	string pivotElement = appNames[first];

	for (int i = first + 1; i <= last; i++)
	{
		if (appNames[i] <= pivotElement)
		{
			p++;
			swapAppNames(i, p, appNames);
		}
	}

	swapAppNames(p, first, appNames);

	return p;
}

void quickSort(int first, int last, string appNames[])
{
	int pivotElement;

	if (first < last)
	{
		pivotElement = pivot(first, last, appNames);
		quickSort(first, pivotElement - 1, appNames);
		quickSort(pivotElement + 1, last, appNames);
	}
}
