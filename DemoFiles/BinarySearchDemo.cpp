#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

/*
 *	Iterative version
 */
int binarySearch(int a[], int low, int high, int target) {
    while (low <= high) {
        int middle = low + (high - low)/2;
        if (target < a[middle])
            high = middle - 1;
        else if (target > a[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

/*
 *	Recursive version
 */
int binarySearchRec(int a[], int low, int high, int target) {
    if (high < low)
        return -1;
    int middle = (low + high)/2;
    if (target < a[middle])
        return binarySearchRec(a, low, middle-1, target);
    else if (target > a[middle])
        return binarySearchRec(a, middle+1, high, target);
    else if (target == a[middle])
        return middle;
}

int main() {
	int array[] = {12,23,34,45,56,67,78,89,90,123};
	int result = binarySearch(array, 0, 9, 89);
	cout << result << endl;
	getch();

	result = binarySearchRec(array, 0, 9, 89);
	cout << result << endl;
	getch();
}
