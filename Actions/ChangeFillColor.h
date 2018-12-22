#pragma once
#include "Action.h"
class ChangeFillColor :public Action
{
	Point P;
public:
	ChangeFillColor(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

