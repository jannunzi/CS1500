#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int comparisonCount = 0;

int binarySearch(int haystack[], int needle, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middle = (start + end) / 2;
//	cout << needle << "\t" << start << "\t" << middle << "\t" << end << "\t" << haystack[middle] << endl;
	if (needle == haystack[middle])
	{
		comparisonCount++;
		return middle;
	}
	else if (needle > haystack[middle])
	{
		comparisonCount++;
		return binarySearch(haystack, needle, middle + 1, end);
	}
	else if (needle < haystack[middle])
	{
		comparisonCount++;
		return binarySearch(haystack, needle, start, middle - 1);
	}
	return -1;
}

int linearSearch(int haystack[], int needle, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		comparisonCount++;
		if (needle == haystack[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int haystack[1000];
	for (int i = 0; i < 1000; i++)
	{
		haystack[i] = rand() % 1000;
	}

	comparisonCount = 0;
	int foundAt = linearSearch(haystack, 492, 0, 1000);
	cout << "Found At: " << foundAt << endl;
	cout << "comparisonCount: " << comparisonCount << endl;

	for (int i = 0; i < 1000; i++)
	{
		haystack[i] = i * 10;
	}

	comparisonCount = 0;
	foundAt = binarySearch(haystack, 800, 0, 1000);
	cout << "Found At: " << foundAt << endl;
	cout << "comparisonCount: " << comparisonCount << endl;
	getchar();
}
