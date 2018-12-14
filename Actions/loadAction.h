#pragma once
#include "Action.h"
class LoadAction :public Action
{
	ActionType ThisAction;
public:
	LoadAction(ApplicationManager*);
	virtual void ReadActionParameters();
	void ReadFigures(ifstream&);
	virtual void Execute();
	void QuickLoad();
	~LoadAction();
};

