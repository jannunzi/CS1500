#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int insert(string tableName, string records[], int count)
{
	ofstream file;
	file.open(tableName.c_str(), ios::out | ios::app);
	for (int i = 0; i < count; i++)
	{
		file << records[i] << endl;
	}
	file.close();
	return count;
}

int insert(string tableName, string record)
{
	ofstream file;
	file.open(tableName.c_str(), ios::out | ios::app);
	file << record << endl;
	file.close();
	return 1;
}

void main()
{
	ofstream file;
	string records[] =
	{
		"Pages,0.0",
		"Keynote,0.99",
		"Numbers,1.99"
	};
	insert("applications.csv", records, 3);
	insert("applications.csv", "Word,99.99");

	getchar();
}
