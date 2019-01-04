#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class ResizeAction :public Action
{
	double Ratio;
	CFigure* toResize;
	ActionType Confirm;

public:
	ResizeAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};
