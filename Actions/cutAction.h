#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class cutAction :public Action
{
	cFigure* cut;
public:
	cutAction(ApplicationManager *);
	~cutAction();
	void readActionParameters() override;
	void execute() override;
};

