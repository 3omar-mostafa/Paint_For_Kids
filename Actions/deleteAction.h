#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class deleteAction :public Action
{
	CFigure * deletedFigure;
	CFigure ** FigList;
public:
	deleteAction(ApplicationManager*);

	virtual void ReadActionParameters();

	virtual void Execute();
};

