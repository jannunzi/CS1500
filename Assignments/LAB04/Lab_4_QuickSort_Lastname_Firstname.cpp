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
    swapAppNames(3, 6, appNames);
    displayAllApplicationNames(appNames, 9);
    quickSort(0, 8, appNames);
    displayAllApplicationNames(appNames, 9);

    getchar();
}

void displayAllApplicationNames(string appNames[], int appCount)
{
    // write your code here
}

void swapAppNames(int appIndex1, int appIndex2, string appNames[])
{
    // write your code here
}

int pivot(int first, int last, string appNames[])
{
    // write your code here
}

void quickSort(int first, int last, string appNames[])
{
    // write your code here
}
