#pragma once
#include "Action.h"
class SaveByTypeAction :public Action
{
	ActionType ThisAction;
public:
	SaveByTypeAction(ApplicationManager*);
	void ReadActionParameters();
	FigureType SavedType();
	void Execute();
	~SaveByTypeAction();
};

