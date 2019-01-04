#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"

class BringToFrontAction : public Action
{
	CFigure * currentFigure;
public:

	BringToFrontAction(ApplicationManager *pApp);
	void readActionParameters() override;
	void execute() override;
};

