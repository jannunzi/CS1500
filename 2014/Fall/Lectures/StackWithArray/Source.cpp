#include <iostream>
#include <string>
using namespace std;

enum ActionType
{
	CUT, COPY, PASTE, PAINT, DRAW
};

class Action
{
private:
	ActionType type;
	string name;
public:
	Action(){}
	Action(string name, ActionType type)
	{
		this->name = name;
		this->type = type;
	}
	void performAction()
	{
		cout << name << endl;
	}
};

class ActionStack {
private:
	Action ** actions = NULL;
	int top = -1;
	int size = 0;
public:
	ActionStack(){}
	ActionStack(int size)
	{
		this->size = size;
		actions = new Action*[size];
	}
	void doAction(Action* action)
	{
		if (isFull())
			return;
		top++;
		actions[top] = action;
	}
	Action* undoAction()
	{
		if (isEmpty())
			return NULL;
		Action* action = actions[top];
		actions[top] = NULL;
		top--;
		return action;
	}
	bool isFull()
	{
		if (top == size - 1)
			return true;
		return false;
	}
	bool isEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}
	void performActionStack()
	{
		for (int i = 0; i <= top; i++)
		{
			actions[i]->performAction();
		}
		cout << "----" << endl;
	}
};

int main()
{
	Action* a1 = new Action("Paint 1", PAINT);
	Action* a2 = new Action("Draw 1", DRAW);
	Action* a3 = new Action("Cut 1", CUT);
	Action* a4 = new Action("Paste 1", PASTE);
	Action* a5 = new Action("Copy 1", COPY);
	Action* a6 = new Action("Paint 2", PAINT);
	Action* a7 = new Action("Draw 2", DRAW);

	ActionStack* stack = new ActionStack(5);
	stack->doAction(a1);
	stack->doAction(a2);
	stack->doAction(a3);
	stack->doAction(a4);
	stack->doAction(a5);
	stack->doAction(a6);
	stack->doAction(a7);
	stack->performActionStack();

	for (int i = 0; i < 10; i++)
	{
		Action* action = stack->undoAction();
		if (action != NULL)
			action->performAction();
	}
}
