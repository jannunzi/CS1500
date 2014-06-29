#include <iostream>
using namespace std;

float average(int array[], int size = 10)
{
	float total = 0.0;
	for (int i = 0; i < size; i++)
	{
		total = total + array[i];
	}
	float avg = total / size;
	return avg;
}

void printArray(int array[], int start = 0, int end = 10)
{
	for (int i = start; i < end; i++)
	{
		std::cout << "array[" << i << "] == " << array[i] << endl;
	}
}

void swapIntArray(int array[], int index1, int index2)
{
	int tmp;
	tmp = array[index1];
	array[index1] = array[index2];
	array[index2] = tmp;
}

int linearSearch(int haystack[], int needle, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (haystack[i] == needle)
		{
			return i;
		}
	}
	return -1;
}

int menu()
{
	int option;
	cout << "Choose favorite color" << endl;
	cout << "[1] Yellow" << endl;
	cout << "[2] Blue" << endl;
	cout << "[3] Red" << endl;
	cin >> option;
	return option;
}

int const SIZE = 10;

int main()
{

	int color = menu();
	cout << color << endl;

	getchar();
	int scores[SIZE] = {95,92,100,85,97};
	scores[8] = 78;

//	cout << linearSearch(scores, 86, SIZE) << endl;

	int foundAt = linearSearch(scores, 85, SIZE);
	if (foundAt != -1)
	{
		cout << "Found at: " << foundAt << endl;
 	}
	else
	{
		cout << "Sorry not found" << endl;
	}

	printArray(scores);
	swapIntArray(scores, 0, 2);
	printArray(scores);

	cout << "Average: " << average(scores, SIZE) << endl;

	getchar();
}