#include <iostream>
using namespace std;

int c = 0;
int binSearch(int haystack[],
	int needle,
	int start, int end)
{
	if (start > end)
		return -1;
	int middle = (start + end) / 2;
	c++;
	if (needle == haystack[middle])
	{
		return middle;
	}
	else if (needle > haystack[middle])
	{
		return binSearch(haystack, needle, middle + 1, end);
	}
	else if (needle < haystack[middle])
	{
		return binSearch(haystack, needle, start, middle - 1);
	}
	return -1;
}

int main()
{
	const int SIZE = 100;
	int haystack[SIZE];
	int needle = 400;
	for (int i = 0; i < SIZE; i++)
	{
		haystack[i] = i*10;
	}
	int foundAt = binSearch(haystack, needle, 0, SIZE);
	cout << "Found " << needle << " at " << foundAt << endl;
	cout << "Comparisons " << c << endl;
	getchar();
}
