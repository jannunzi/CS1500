#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int LOGIN = 1;
	const int REGISTER = 2;
	const int LOGIN_AS_GUEST = 3;
	const int QUIT = 0;
	string username;
	string password;
	string passwordVerify;
	int choice;
	do
	{
		cout << "Choose One:" << endl;
		cout << "[1] Login" << endl;
		cout << "[2] Register" << endl;
		cout << "[3] Login as Guest" << endl;
		cout << "[0] Quit" << endl;
		cin >> choice;
		switch(choice)
		{
		case LOGIN:
			cout << "Username: " << endl;
			cin >> username;
			cout << "Password: " << endl;
			cin >> password;
			if (username == "alice" && password == "wonderland")
			{
				cout << "Follow me down the rabbit hole" << endl;
			}
			else if (username == "thomas" && password == "anderson")
			{
				cout << "There is no spoon" << endl;
			}
			else if (username == "yoda" && password == "minch")
			{
				cout << "Do. Or do not. There is no try" << endl;
			}
			break;
		case REGISTER:
			cout << "Username: " << endl;
			cin >> username;
			cout << "Password: " << endl;
			cin >> password;
			cout << "Verify Password: " << endl;
			cin >> passwordVerify;
			if (password != passwordVerify)
			{
				cout << "Passwords must match" << endl;
			}
			break;
		case LOGIN_AS_GUEST:
			break;
		case QUIT:
			break;
		}
	} while (choice != QUIT);
	cout << "Done" << endl;
	getchar();
}