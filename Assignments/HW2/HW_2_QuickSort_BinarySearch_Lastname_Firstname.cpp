#include <iostream>
#include <string>
using namespace std;

void displayApplication(int appIndex, string appNames[], float appPrices[]);
void displayAllApplications(string appNames[], float appPrices[], int appCount);
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

	displayAllApplications(appNames, appPrices, 9);
	quickSort(0, 8, appNames, appPrices);
	displayAllApplications(appNames, appPrices, 9);
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
