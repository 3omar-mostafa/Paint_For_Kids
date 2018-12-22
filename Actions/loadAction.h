#pragma once
#include "Action.h"
class LoadAction :public Action
{
	ActionType Confirm;	//An ActionType variable to act as a confirmation for the action
public:
	LoadAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	void ReadFigures(ifstream&);	//Reads Figure Information from a file
	void QuickLoad();	//Loads without confirmation or asking for a name for the file
	~LoadAction();
};

