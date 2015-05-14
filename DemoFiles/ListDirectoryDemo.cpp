#include <iostream>	// for cout, cin, endl
#include <dirent.h>	// for directory listing
#include <conio.h>
#include <string>
using namespace std;

int main() {
	DIR *directory;
	struct dirent *file;     
	directory = opendir ("./");
	string ending = ".csv";
	if (directory != NULL) {
		while (file = readdir (directory)) {
			string name = string(file->d_name);
			if(name.length() < 4) continue;
			bool isCsv = name.compare (name.length() - ending.length(), ending.length(), ending) == 0;
			if(isCsv)
				cout << name << endl;
		}
		closedir (directory);
	}
	getch();
}
