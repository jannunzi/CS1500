#include <iostream>
#include <string>
using namespace std;

const int GAMES = 0;
const int TRAVEL = 1;
const int EVERYONE = 0;
const int MATURE = 1;

struct Application {
	string name;
	string description;
	int category;
	int rating;
	Application();
	Application(string n, string d, int c, int r);
	void display();
};

struct AppNode {
	AppNode* next;
	Application* application;
	AppNode* prev;
	AppNode();
	AppNode(Application* application);
};

struct AppStore {
	string name;
	AppNode* head;
	AppNode* tail;
	AppStore();
	AppStore(string name);
	~AppStore();
	AppNode* findAppsByCategory(int type);
	void removeAppsByRating(int rating);
	void addApps(AppNode* appList);
	void display();
};

Application::Application(){}
Application::Application(string name, string description, int category, int rating) {
	this->name = name; this->description = description; this->category = category; this->rating = rating;
}
void Application::display(){
	cout << this->name << ", " << this->description << endl;
}
AppNode::AppNode(){
	next = NULL; prev = NULL; application = NULL;
}
AppNode::AppNode(Application* app) : AppNode() {
	this->application = app;
}
AppStore::AppStore(){
	head = NULL; tail = NULL;
}
AppStore::AppStore(string name) : AppStore() {
	this->name = name;
}
AppStore::~AppStore() {
}
void AppStore::display() {
	cout << name << endl;
	AppNode* current = head;
	while (current != NULL) {
		current->application->display();
		current = current->next;
	}
	cout << endl;
}
AppNode* AppStore::findAppsByCategory(int category) {
	if (head == NULL) return NULL;
	AppNode* current = head;
	AppNode* newListHead = NULL;
	AppNode* newListTail = NULL;
	while (current != NULL) {
		if (current->application->category == category) {
			string name = current->application->name;
			string description = current->application->description;
			int category = current->application->category;
			int rating = current->application->rating;
			Application* appCopy = new Application(name, description, category, rating);
			AppNode* newNode = new AppNode(appCopy);
			if (newListHead == NULL) {
				newListHead = newNode;
				newListTail = newNode;
			}
			else {
				newListTail->next = newNode;
				newNode->prev = newListTail;
				newListTail = newNode;
			}
		}
			current = current->next;
	}
	return newListHead;
}

void AppStore::removeAppsByRating(int rating) {
	AppNode* current = head;
	while (current != NULL) {
		if (current->application->rating == rating) {
			AppNode* remove = current;
			current->next->prev = current->prev;
			current->prev->next = current->next;
			current = current->next;
			delete remove->application;
			delete remove;
			continue;
		}
		current = current->next;
	}
}

void AppStore::addApps(AppNode* appList) {
	if (appList == NULL) {
		return;
	}
	if (head == NULL) {
		head = appList;
		tail = appList;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		return;
	}
	tail->next = appList;
	tail = appList;
	while (tail->next != NULL) {
		tail = tail->next;
	}
}

int main() {
	Application* mineCraft = new Application("Mine Craft", "Sandbox indie game", GAMES, EVERYONE);
	Application* tripAdvisor = new Application("Trip Advisor", "Trip planning", TRAVEL, EVERYONE);
	Application* borderlands2 = new Application("Borderlands 2", "Action role-playing first-person shooter", GAMES, MATURE);
	Application* kayak = new Application("Kayak", "Travel Booking", TRAVEL, EVERYONE);

	AppNode* n1 = new AppNode(mineCraft);
	AppNode* n2 = new AppNode(tripAdvisor);
	AppNode* n3 = new AppNode(borderlands2);
	AppNode* n4 = new AppNode(kayak);

	n1->next = n2;	n2->prev = n1;
	n2->next = n3;	n3->prev = n2;
	n3->next = n4;	n4->prev = n3;

	AppStore* store = new AppStore("Store");
	store->addApps(n1);
	store->display();

	AppNode* games = store->findAppsByCategory(GAMES);

	AppStore* gameStore = new AppStore("Game Store");
	gameStore->addApps(games);
	gameStore->display();
	store->display();

	store->removeAppsByRating(MATURE);
	store->display();
	gameStore->display();
}
