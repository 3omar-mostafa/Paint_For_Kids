#pragma once
#include "Action.h"
class ChangeDrawColor :public Action
{
	Point P;
public:
	ChangeDrawColor(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

