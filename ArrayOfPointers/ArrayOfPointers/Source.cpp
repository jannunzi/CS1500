#include <iostream>
#include <string>
using namespace std;

struct Book {
	string title;
	float price;
};

void putBookAt(Book book, Book array[], int index)
{
	array[index] = book;
}

Book getBook(Book array[], int index)
{
	return array[index];
}

int main()
{
	Book array1[10];
	Book dune = { "Dune", 9.9 };

	putBookAt(dune, array1, 3);
	Book b = getBook(array1, 3);
	cout << b.title << endl;

	Book* array2[10];

	getchar();
}