#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class bringToFrontAction : public Action
{
	cFigure * currentFigure;
public:

	bringToFrontAction(ApplicationManager *pApp);
	void readActionParameters() override;
	void execute() override;
};

