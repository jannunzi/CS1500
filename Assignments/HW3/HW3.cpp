#include <iostream>
#include <string>
using namespace std;

struct Application {
	string name;
	float price;
};

int displayMainMenu();
Application* createNewAppList(int);
Application* createNewApp();
void addAppToAppList(Application* app, Application* appList, int appListCount);
void displayAppList(Application* appList, int);
int chooseApp(Application* appList, int appListCount);
void updateAppApp(Application* appList, int appIndex, Application* app);

int main()
{
	const int QUIT = 0;
	const int CREATE_NEW_APP_LIST = 1;
	const int CREATE_NEW_APP = 2;
	const int READ_ALL_APPS = 3;
	const int UPDATE_APP = 4;
	const int DELETE_APP = 5;
	int choice;
	int appListSize;
	int appListCount = 0;
	Application* appList;
	Application* app;
	do
	{
		choice = displayMainMenu();
		switch (choice)
		{
		case CREATE_NEW_APP_LIST:
			cout << "How Many Applications?" << endl;
			cin >> appListSize;
			cout << endl;
			appList = createNewAppList(appListSize);
			break;
		case CREATE_NEW_APP:
			app = createNewApp();
			addAppToAppList(app, appList, appListCount);
			appListCount++;
			break;
		case READ_ALL_APPS:
			displayAppList(appList, appListCount);
			break;
		case UPDATE_APP:
			int appIndex = chooseApp(appList, appListCount);
			app = createNewApp();
			updateAppApp(appList, appIndex, app);
			break;
		case DELETE_APP:
//			int appIndex = chooseApp(appList);
//			deleteApp(appIndex);
			break;
		}
	} while (choice != QUIT);
}

int displayMainMenu()
{
	cout << "Main Menu" << endl;
	cout << "[1] Create New List of Applications" << endl;
	cout << "[2] Add New Application to List" << endl;
	cout << "[3] Display List of Applications" << endl;
	cout << "[4] Update Existing Application" << endl;
	cout << "[5] Delete Existing Application" << endl;
	cout << "[0] Quit" << endl;
	int choice;
	cin >> choice;
	cout << endl;
	return choice;
}

Application* createNewAppList(int count)
{
	return new Application[count];
}

Application* createNewApp()
{
	cout << "New Application" << endl;
	Application* newApplication = new Application;
	cout << "Name: ";
	cin >> newApplication->name;
	cout << "Price: ";
	cin >> newApplication->price;
	cout << endl;
	return newApplication;
}

void addAppToAppList(Application* app, Application* appList, int appListCount)
{
	appList[appListCount] = *app;
}

void displayAppList(Application* appList, int appListSize)
{
	for (int i = 0; i < appListSize; i++)
	{
		cout << "[" << i << "] " << appList[i].name << " $" << appList[i].price << endl;
	}
	cout << endl;
}

int chooseApp(Application* appList, int appListCount)
{
	int choice;
	displayAppList(appList, appListCount);
	cout << "Choose Application" << endl;
	cin >> choice;
	return choice;
}

void updateAppApp(Application* appList, int appIndex, Application* app)
{
	appList[appIndex] = *app;
}
