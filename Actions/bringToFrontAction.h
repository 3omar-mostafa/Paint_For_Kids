#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class bringToFrontAction : public Action
{
	CFigure * currentFigure;
public:

	bringToFrontAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

