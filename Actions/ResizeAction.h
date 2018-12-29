#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class resizeAction :public Action
{
	double Ratio;
	cFigure* toResize;
	ActionType Confirm;

public:
	resizeAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};
