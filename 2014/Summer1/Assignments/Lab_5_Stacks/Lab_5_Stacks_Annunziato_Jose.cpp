#include <iostream>
#include <string>
using namespace std;

struct Application
{
	string name;
	float  price;
	Application* next;
};

void displayApplication(Application* app)
{

}

Application* pop(Application** top)
{
	return NULL;
}

void push(Application** top, Application* application)
{

}

int main()
{
	Application* top = NULL;

	Application* mineCraft = new Application();
	Application* kerbalSpace = new Application();
	Application* gearsOfWars = new Application();
	Application* kingdomHearts = new Application();

	push(&top, mineCraft);
	push(&top, kerbalSpace);
	push(&top, gearsOfWars);
	push(&top, kingdomHearts);

	Application* app = pop(&top);
}
