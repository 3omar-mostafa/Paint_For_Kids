#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class deleteAction :public Action
{
	cFigure * deletedFigure;
public:
	deleteAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

