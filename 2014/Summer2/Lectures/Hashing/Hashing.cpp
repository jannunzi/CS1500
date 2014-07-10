#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

void printArray(string arr[])
{
	for (int i = 0; i < SIZE; i++) {
		cout << "[" << i << "]\t" << arr[i] << endl;
	}
}

int h(string key) {
	int hash = 0;

	for (int i = 0; i < key.length(); i++) {
		hash += key[i];
	}

	hash = hash % SIZE;

	return hash;
}

void put(string arr[], string key) {
	int h1 = h(key);
	if (arr[h1] == "") {
		arr[h1] = key;
	}
	else {
		for (int i = h1; i < SIZE; i++) {
			if (arr[i] == "") {
				arr[i] = key;
				break;
			}
		}
	}
}

int get(string arr[], string key) {
	int h1 = h(key);
	if (key == arr[h1]) {
		return h1;
	}
	else {
		for (int i = h1; i < SIZE; i++) {
			if (key == arr[i]) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	string strings[SIZE];

	string hello = "Hello World";
	string goodb = "Good Bye !!";
	/*
	int h1 = h(hello);
	int h2 = h(goodb);
	cout << h1 << endl;
	cout << h2 << endl;

//	printArray(strings);
	strings[h1] = hello;
	strings[h2] = goodb;
	printArray(strings);

	int find = h("Hello World");
	cout << strings[find] << endl;
*/

	put(strings, hello);
	put(strings, goodb);
	put(strings, "dlroW olleH");
	printArray(strings);

	int h1 = get(strings, hello);
	int h2 = get(strings, goodb);
	int h3 = get(strings, "dlroW olleH");

	cout << h1 << " " << strings[h1] << endl;
	cout << h2 << " " << strings[h2] << endl;
	cout << h3 << " " << strings[h3] << endl;
}
