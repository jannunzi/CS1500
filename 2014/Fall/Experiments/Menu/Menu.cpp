#include <iostream>
using namespace std;

int main() {
	int choice = -1;
	while (choice != 0) {
		std::cout << "Menu" << std::endl;
		cout << "[1] Create Application" << endl;
		cout << "[2] List Applications" << endl;
		cout << "[0] Quit" << endl;
		cout << "Choice: ";
		std::cin >> choice;
		std::cout << "Your Choice: " << choice << std::endl;
		if (choice == 1) {
			cout << "Creating an Application" << endl;
		}
		if (choice == 2) {
			cout << "Listing all Applications" << endl;
		}
	}
	cout << "Done" << endl;
}
