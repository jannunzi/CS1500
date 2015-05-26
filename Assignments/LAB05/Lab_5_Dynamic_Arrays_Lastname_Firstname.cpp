#include <iostream>
using namespace std;

void displayIntArray(int arr[], int size);
void readIntArray(int arr[], int size);
int* copyArray(int arr[], int size);
int* concatenateIntArrays(int arr1[], int arr2[], int size1, int size2);
int* subArray(int arr[], int size, int start, int count);

int main()
{
    // Read 2 dynamic arrays
    int size1, size2, size3;
    cout << "Size of arr1: ";
    cin >> size1;
    cout << "Size of arr2: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    readIntArray(arr1, size1);
    readIntArray(arr2, size2);

    // concatenate two arrays into a third
    int* arr3;
    arr3 = concatenateIntArrays(arr1, arr2, size1, size2);

    size3 = size1 + size2;
    cout << "Concatenated Array:" << endl;
    displayIntArray(arr3, size3);

    getchar();

    // Copy an array
    int* copy = copyArray(arr1, size1);
    cout << "Copied Array:" << endl;
    displayIntArray(copy, size1);

    // Get sub array
    // Read parent array
    int size4;
    cout << "Array Size: ";
    cin >> size4;
    int* arr4 = new int[size4];
    readIntArray(arr4, size4);

    // get sub array
    int start, count;
    cout << "Start: ";
    cin >> start;
    cout << "Count: ";
    cin >> count;
    int* sub = subArray(arr4, size4, start, count);

    // display sub array
    cout << "Sub Array:" << endl;
    displayIntArray(sub, count);
}
