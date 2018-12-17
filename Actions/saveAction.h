#pragma once
#include "Action.h"
class SaveAction :public Action
{
	ActionType Confirm;	//An ActionType variable to act as a confirmation for the action
public:
	SaveAction(ApplicationManager*);	
	virtual void ReadActionParameters();
	virtual void Execute();
	void QuickSave();	//Saves without confirmation or asking for a name for the file
	~SaveAction();
};

