#include <iostream>
#include <string>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

bool isPalindrome(char word[], int length) {
	for (int i = 0; i < length; i++) {
		cout << word[i] << "\t" << word[length - i - 1] << endl;
		if (word[i] != word[length - i - 1]){
			return false;
		}
	}
	return true;
}

const int C_SIZE = 9;

void printIntArray(int a[], int l) {
	cout << "=============" << endl;
	for (int i = 0; i < l; i++) {
		cout << "[" << i << "] " << a[i] << endl;
	}
}

void printCharArray(char a[], int l) {
	cout << "=============" << endl;
	for (int i = 0; i < l; i++) {
		cout << "[" << i << "] " << a[i] << endl;
	}
}

void mergeArrays(int X[], int Y[], int Z[], int lx, int ly)
{
	int x = 0, y = 0, z = 0;
	int lz = lx + ly;
	// copy from X[] or Y[]
	// as long as their indices are within boundaries
	while (x < lx && y < ly) {
		if (X[x] < Y[y]) {
			Z[z] = X[x];
			x++;
			z++;
		}
		else if (Y[y] < X[x]) {
			Z[z] = Y[y];
			y++;
			z++;
		}
		else if (X[x] == Y[y]) {
			Z[z] = X[x];
			x++;
			z++;
			Z[z] = Y[y];
			y++;
			z++;
		}
	}
	// copy the rest from X[] if it's not depleated yet
	while (x < lx) {
		Z[z] = X[x];
		x++;
		z++;
	}

	while (y < ly){
		Z[z] = Y[y];
		y++;
		z++;
	}

	// copy the rest from Y[] if it's not depleated yet
}

void concatenateArrays(int x[], int y[], int z[], int lx, int ly)
{
	// copy x[] into z[]
	for (int i = 0; i < lx; i++){
		z[i] = x[i];
	}
	// copy y[] into z[]
	for (int i = lx; i < lx+ly; i++){
		z[i] = y[i - lx];
	}
	// or copy y[] into z[]
	for (int i = 0; i < ly; i++) {
		z[i + lx] = y[i];
	}
}

int findSubArray(char A[], char B[], int  la, int  lb)
{
	int a = 0, b = 0;
	int timesFound = 0;
	for (a = 0; a < la; a++) {
//		cout << A[a] << endl;
		for (b = 0; b < lb; b++) {
			if (A[a+b] != B[b])
				break;
		}
		if (b == lb)
			timesFound++;
	}
	return timesFound;
}

int main() {

	char A[] = { 'f', 'd', 's', 'a', 'r', 'e', 'w', 'k', 'g', 'f', 'd', 's', 'r', 'e', 'w', 'q', 'b', 'v', 'c', 'x' };
	char B[] = { 'r', 'e', 'w', 'q' };
	cout << "Times Found: " << findSubArray(A, B, 20, 4) << endl;
//	printCharArray(A, 20);
//	printCharArray(B, 4);

	int a[] = { 1, 3, 5, 7, 10, 20};
	int b[] = { 2, 4, 6 };
	int c[C_SIZE];

	mergeArrays(a, b, c, 6, 3);
	printIntArray(a, 4);
	printIntArray(b, 3);
	printIntArray(c, 9);

	concatenateArrays(a, b, c, 4, 3);
	printIntArray(a, 4);
	printIntArray(b, 3);
	printIntArray(c, 7);


	char word[] = { 'c','i','v','j','c' };
	bool pal = isPalindrome(word, 5);
	cout << pal << endl;

	int x = 10, y = 20;
	swap(x, y);
	cout << x << ", " << y << endl;
}