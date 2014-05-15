#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void swap(int values[], int index1, int index2)
{
	int tmp;
	tmp = values[index1];
	values[index1] = values[index2];
	values[index2] = tmp;
}



void mergeSort(int values[], int first, int last)
{

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