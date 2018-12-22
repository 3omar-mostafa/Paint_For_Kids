#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class ResizeAction :public Action
{
	double Ratio;
	CFigure* toResize;
	ActionType Confirm;

public:
	ResizeAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};
