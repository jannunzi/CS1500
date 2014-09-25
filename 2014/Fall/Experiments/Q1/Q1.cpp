#include <iostream>
#include <string>
using namespace std;

void replaceAll(char phrase[], char replace[], char with[],
				int phraseLength, int replaceLength) {
	for (int p = 0; p < phraseLength - replaceLength + 1; p++) {
		int r;
		for (r = 0; r < replaceLength; r++) {
			if (phrase[p + r] != replace[r])
				break;
		}
		if (r == replaceLength) {
			for (r = 0; r < replaceLength; r++) {
				phrase[p + r] = with[r];
			}
		}
	}
}

void displayCharArray(char a[], int l) {
	for (int i = 0; i < l; i++) {
		cout << a[i];
	}
	cout << endl;
}

int main() {
	char phrase[] = { 'T', 'o', ' ', 'b', 'e', ' ', 'o', 'r', ' ', 'n', 'o', 't', ' ', 't', 'o', ' ', 'b', 'e' };
	char replace[] = { 'b', 'e' };
	char with[] = { 'g', 'o' };

	displayCharArray(phrase, 18);
	replaceAll(phrase, replace, with, 18, 2);
	displayCharArray(phrase, 18);
}
