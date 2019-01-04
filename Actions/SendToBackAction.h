#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"

class SendToBackAction : public Action
{
	CFigure * currentFigure;
public:

	SendToBackAction(ApplicationManager *pApp);
	void readActionParameters() override;
	void execute() override;
};

