#pragma once
#include "Action.h"
class SaveAction :public Action
{
	ActionType ThisAction;
public:
	SaveAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveAction();
};

