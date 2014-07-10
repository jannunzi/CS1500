#include <iostream>
#include <string>
using namespace std;

int h(string str) {
	int size = str.length();
	int hash = 0;
	for (int i = 0; i < size; i++){
		char character = str[i];
		hash += character;
	}
	return hash;
}

const int SIZE = 10;

void printArray(string arr[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << "[" << i << "]\t" << arr[i] << endl;
	}
}

int get(string key, string arr[]) {
	int hash = h(key);
	hash = hash % SIZE;
	string value = arr[hash];
	if (value == key) {
		return hash;
	}
	else {
		for (int i = hash; i < SIZE; i++) {
			if (arr[i] == key)
				return i;
		}
	}
	return -1;
}

void put(string key, string arr[]) {
	int hash = h(key);
	hash = hash % SIZE;
	if (arr[hash] == "") {
		arr[hash] = key;
	}
	else {
		for (int i = hash; i < SIZE; i++) {
			if (arr[i] == "") {
				arr[i] = key;
				break;
			}
		}
	}
}

int main() {
	string hello = "hello world";
	cout << h(hello) << endl;

	string arr[SIZE];
	put("hey", arr);
	put("how are you?", arr);
	put(hello, arr);

	printArray(arr);

	int i1 = get("hey", arr);
	int i2 = get("how are you?", arr);
	int i3 = get(hello, arr);
	cout << i1 << "\t" << arr[i1] << endl;
	cout << i2 << "\t" << arr[i2] << endl;
	cout << i3 << "\t" << arr[i3] << endl;
}
