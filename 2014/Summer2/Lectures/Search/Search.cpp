#include <iostream>
#include <string>
using namespace std;

int linearCost = 0;
int binaryCost = 0;

void displayBook(int bookIndex, string titles[], string authors[], string isbns[]);
int linearSearchByTitle(string title, string titles[], int size);
int linearSearchByAuthor(string author, string authors[], int size);
int binarySearchByTitle(string title, string titles[], int bottom, int top);

int main() {
	string titles[] = {
		"Book1", "Book2", "Book3", "Book4", "Book5", "Book6", "Dune", "LOTR"
	};
	string authors[] = {
		"Author 1", 
		"Author 2", 
		"Author 3", 
		"Author 4", 
		"Author 5",
		"Frank",
		"Phillip",
		"Tolkien"
	};
	string isbns[] = {
		"12341234",
		"23452345",
		"34563456",
		"45674567",
		"56785687",
		"67896789",
		"76547654",
		"87587655"
	};
	displayBook(1, titles, authors, isbns);

	int indexFound = linearSearchByTitle("LOTR", titles, 8);
	displayBook(indexFound, titles, authors, isbns);
	
	indexFound = binarySearchByTitle("LOTR", titles, 0, 7);
	displayBook(indexFound, titles, authors, isbns);

	cout << "binaryCost: " << binaryCost << endl;
	cout << "linearCost: " << linearCost << endl;
}

int binarySearchByTitle(string title, string titles[], int bottom, int top)
{
	binaryCost++;
	if (bottom > top)
	{
		return -1;
	}
	int middle = (bottom + top) / 2;
	if (title == titles[middle])
	{
		return middle;
	}
	else if (title > titles[middle])
	{
		return binarySearchByTitle(title, titles, middle + 1, top);
	}
	else if (title < titles[middle])
	{
		return binarySearchByTitle(title, titles, bottom, middle - 1);
	}
	return -1;
}

int linearSearchByTitle(string title, string titles[], int size)
{
	for (int i = 0; i < size; i++)
	{
		linearCost++;
		if (title == titles[i])
		{
			return i;
		}
	}
	return -1;
}

void displayBook(int bookIndex, string titles[], string authors[], string isbns[])
{
	if (bookIndex >= 0)
	{
		cout << titles[bookIndex] << " " << authors[bookIndex] << " " << isbns[bookIndex] << endl;
	}
	else {
		cout << "Book not found" << endl;
	}
}
