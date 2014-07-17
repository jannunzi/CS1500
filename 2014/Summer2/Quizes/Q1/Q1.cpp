#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int countContains(string sentence, string word) {
	int count = 0;
	int j = 0;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == word[0]) {
			int same = 0;
			for (int j = 0; j < word.length(); j++){
				if (sentence[i + j] == word[j]) {
					same++;
				}
			}
			if (same == word.length())
				count++;
		}
	}
	return count;
}

float P(float a[], int order, int x) {
	float value = 0;
	for (int i = 0; i < order; i++){
		value += a[i] * pow(x, i);
	}
	return value;
}

int main() {
	cout << countContains("To Be Or Not To Be", "Be") << endl;
	cout << countContains("Buffalo buffalo Buffalo buffalo buffalo buffalo Buffalo buffalo", "Buffalo") << endl;
	cout << countContains("That that is is that that is not is not is that it it is", "that") << endl;

	float a[] = { 12.23, 23.34, 34.45 };
	cout << P(a, 3, 5) << endl;
	float b[] = { 1,2,3,4 };
	cout << P(b, 4, 2) << endl;
}