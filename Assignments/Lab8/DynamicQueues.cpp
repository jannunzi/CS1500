#include <iostream>
#include <string>
using namespace std;

struct Donut
{
	string flavor = "";
	float price = 0.0;
	Donut(string flvr, float prc)
	{
		flavor = flvr;
		price = prc;
	}
	Donut(){}
};

struct DonutTray
{
	Donut** donuts;
	int capacity;
	int front = 0, back = 0;
	int count = 0;
	DonutTray(int size)
	{
		capacity = size;
		donuts = new Donut*[capacity];
	}
};

void   enqueueDonut(DonutTray* tray, Donut* donut);
Donut* dequeueDonut(DonutTray* tray);
void   displayDonut(Donut* donut);
void   displayDonutTray(DonutTray* tray);

int main()
{
	Donut* chocolate = new Donut("Chocolate", 0.99);
	Donut* boston = new Donut("Boston Crm", 0.99);
	Donut* jelly = new Donut("Jelly", 0.99);
	Donut* glazed = new Donut("Glazed", 0.99);
	Donut* eclair = new Donut("Eclair", 0.99);
	Donut* snowy = new Donut("Snowy", 0.99);
	Donut* moon = new Donut("Moonraker", 0.99);

	DonutTray* tray = new DonutTray(5);

	enqueueDonut(tray, chocolate);
	enqueueDonut(tray, boston);
	enqueueDonut(tray, jelly);
	enqueueDonut(tray, glazed);
	displayDonutTray(tray);

	Donut* donut = dequeueDonut(tray);
	displayDonut(donut);
	displayDonutTray(tray);

	enqueueDonut(tray, eclair);
	enqueueDonut(tray, snowy);
	displayDonutTray(tray);

	donut = dequeueDonut(tray);
	displayDonut(donut);
	donut = dequeueDonut(tray);
	displayDonut(donut);
	enqueueDonut(tray, moon);

	displayDonutTray(tray);
}
