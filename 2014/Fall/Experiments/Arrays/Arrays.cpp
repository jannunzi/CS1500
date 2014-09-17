#include <iostream>
#include <string>
using namespace std;

void displayEmployee(int ids[], string names[], double salaries[], int index)
{
	cout << "Employee" << endl;
	cout << ids[index] << endl;
	cout << names[index] << endl;
	cout << salaries[index] << endl;
}

int searchName(string key, int ids[], string names[], double salaries[], int length)
{
	for (int i = 0; i < length; i++) {
		if (key == names[i]){
			return i;
		}
	}
}
int main() {
	int id[] = { 1, 2, 3, 4 };
	string name[] = { "Alice", "Bob", "Charlie", "Dan" };
	double salary[] = { 123.23, 234.23, 345.45, 456.65 };
	displayEmployee(id,name,salary,1);
	int found = searchName("Charlie", id, name, salary, 4);
	displayEmployee(id, name, salary, found);
}