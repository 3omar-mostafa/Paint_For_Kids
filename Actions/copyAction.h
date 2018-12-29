#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class copyAction :public Action
{
	cFigure* copied;
public:
	copyAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

