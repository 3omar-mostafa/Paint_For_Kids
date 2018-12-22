#pragma once
#include "Action.h"
class SaveByTypeAction :public Action
{
	ActionType Confirm;	//An ActionType variable to act as a confirmation for the action
public:
	SaveByTypeAction(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	FigureType SetSavedType();	//Determines the FigureType chosen for saving
	~SaveByTypeAction();
};

