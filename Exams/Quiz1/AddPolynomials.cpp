#include <iostream>
using namespace std;

void addPolynomials(int a[], int b[], int la, int lb)
{
	// find out which length is smaller and biggest
	int lmin = la < lb ? la : lb;
	int lmax = la > lb ? la : lb;

	for (int i = lmax - 1; i >= lmin; i--)
	{
		int c;
		if (la > lb)
			c = a[i];
		else
			c = b[i];
		cout << c << "x^" << i << " + ";
	}

	// add a + b through smallest index
	for (int i = lmin-1; i >= 0; i--)
	{
		int c = a[i] + b[i];
		cout << c << "x^" << i << " + ";
	}
	cout << endl;
}

char* removeAllCharacters(char* phrase, char removeMe, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (phrase[i] != removeMe)
			count++;

	char* newPhrase = new char[count+1];
	int newIndex = 0;
	for (int i = 0; i < size; i++)
		if (phrase[i] != removeMe)
			newPhrase[newIndex++] = phrase[i];

	newPhrase[count] = '\0';

	for (int i = 0; i < count; i++)
		cout << newPhrase[i];

	cout << endl;

	return newPhrase;
}

int main()
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5, 6, 7, 8 };
	addPolynomials(a, b, 3, 5);

	int c[] = { 9, 8, 7 };
	int d[] = { 6, 5, 4 };
	addPolynomials(c, d, 3, 3);

	int e[] = { 1, 2, 3, 4, 5 };
	int f[] = { 6, 7, 8 };
	addPolynomials(e, f, 5, 3);

	char phrase[] = { 'T','o',' ','b','e',' ','o','r',' ','n','o','t',' ','t','o',' ','b','e','\0' };
	cout << "|" << phrase << "|" << endl;
	char* newPhrase = removeAllCharacters(phrase, 'o', 18);

	cout << "|" << newPhrase << "|" << endl;

	// T be r nt t be

	getchar();
}