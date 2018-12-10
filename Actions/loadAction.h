#pragma once
#include "Action.h"
class LoadAction :public Action
{
	ActionType ThisAction;
public:
	LoadAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	void QuickLoad();
	~LoadAction();
};

