#include <iostream>
using namespace std;

void addPolynomials(int A[], int B[], int n, int m)
{
	// find out which array is smaller and bigger
	int min = n < m ? n : m;
	int max = n > m ? n : m;

	// iterate backwards from max to min
	// if different size arrays
	// to deal with elements that don't need
	// to be added, just printed
	// iterating forwards is ok too
	// (A)
	for (int i = max - 1; i >= min; i--)
	{
		int c;
		if (n > m)
			c = A[i];
		else
			c = B[i];
		cout << c << "x^" << i;

		// dont print "+" in the last iteration
		if (i > min)
			cout << " + ";
	}

	// iterate backwards from min to 0
	// adding A[i] and B[i]
	// and printing it to the console
	// iterating forwards is ok too
	// (B)
	for (int i = min-1; i >= 0; i--)
	{
		int c = A[i] + B[i];
		cout << c << "x^" << i;

		// dont print "+" in the last iteration
		if (i > 0)
			cout << " + ";
	}

	// could do (A) or (B) in any order,
	// i.e., first (A), then (B)
	// or first (B), then (A)

	cout << endl;
}

char* removeAllCharacters(char* phrase, char removeMe, int size)
{
	// find out how big does my new array need to be
	int count = 0;
	for (int i = 0; i < size; i++)
		if (phrase[i] != removeMe)
			count++;

	// create my new array
	// one more to hold '\0', but that's optional
	char* newPhrase = new char[count+1];
	int newIndex = 0;

	// copy all characters from input array, but skip the removeMe character
	for (int i = 0; i < size; i++)
		if (phrase[i] != removeMe)
			newPhrase[newIndex++] = phrase[i];

	// add end character at the end, but that's optional
	newPhrase[count] = '\0';

	// print out new phrase (optional)
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