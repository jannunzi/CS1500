#include <iostream>
#include <string>
using namespace std;

struct Application {
	string name;
    float price;
};

int displayMainMenu();
Application* createNewAppArray(int);
Application* createNewApp();
void addAppToAppArray(Application* app, Application* appArray, int appArrayCount);
void displayAppArray(Application* appArray, int);
int chooseApp(Application* appArray, int appArrayCount);
void updateApp(Application* appArray, int appIndex, Application* app);

int main()
{
	// menu choices
	const int QUIT = 0;
	const int CREATE_NEW_APP_ARRAY = 1;
	const int CREATE_NEW_APP = 2;
	const int READ_ALL_APPS = 3;
	const int UPDATE_APP = 4;
	const int DELETE_APP = 5;

	Application* appArray;	// array of applications
	Application* app;		// pointer to an application

	int choice;				// current menu choice
	int appArraySize;		// size of the array containing applications
	int appArrayCount = 0;	// how many applications have been added to array
	int appIndex;			// which application to update
	do
	{
		choice = displayMainMenu();	// display menu and return choice
		switch (choice)
		{
		case CREATE_NEW_APP_ARRAY:
			// ask how many applications,
			// read in the size,
			// create application array dynamically
			cout << "How Many Applications?" << endl;
			cin >> appArraySize;
			cout << endl;
			appArray = createNewAppArray(appArraySize);
			break;
		case CREATE_NEW_APP:
			// create a new application
			// add it to the array
			// keep count of how many apps we've created so far
			app = createNewApp();
			addAppToAppArray(app, appArray, appArrayCount);
			appArrayCount++;
			break;
		case READ_ALL_APPS:
			// pass application array to function to display them all
			displayAppArray(appArray, appArrayCount);
			break;
		case UPDATE_APP:
			// display all the apps and ask user to choose one
			// create a new app to get all the updates user wants to perform
			// update the selected application with the data in the app just created
			appIndex = chooseApp(appArray, appArrayCount);
			app = createNewApp();
			updateApp(appArray, appIndex, app);
			break;
		}
	} while (choice != QUIT);
}
