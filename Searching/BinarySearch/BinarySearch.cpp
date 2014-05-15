#include <ctime>
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

	cout << comparisonCount << " ";
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
		cout << comparisonCount << " ";
		if (needle == haystack[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	const int SIZE = 10000;
	int haystack[SIZE];
	std::clock_t    start, end;

	for (int i = 0; i < SIZE; i++)
	{
		haystack[i] = rand() % SIZE;
//		cout << haystack[i] << " ";
	}

	comparisonCount = 0;
	
	start = std::clock();
	cout << "Start: " << start << endl;
	int foundAt = linearSearch(haystack, 2081, 0, SIZE);
	end = std::clock();
	cout << endl << "End: " << end << endl;
	cout << "Ellapsed: " << end - start << "ms" << endl;
	cout << "Found At: " << foundAt << endl;
	cout << "comparisonCount: " << comparisonCount << endl;

	for (int i = 0; i < SIZE; i++)
	{
		haystack[i] = i * 10;
	}

	comparisonCount = 0;
	start = std::clock();
	cout << "Start: " << start << endl;
	foundAt = binarySearch(haystack, 8010, 0, SIZE);
	end = std::clock();
	cout << endl << "End: " << end << endl;
	cout << "Ellapsed: " << end - start << "ms" << endl;
	cout << "Found At: " << foundAt << endl;
	cout << "comparisonCount: " << comparisonCount << endl;
	getchar();
}
