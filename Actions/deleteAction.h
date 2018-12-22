#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class DeleteAction :public Action
{
	CFigure * deletedFigure;
public:
	DeleteAction(ApplicationManager*);
	virtual void ReadActionParameters();
    virtual void Execute();
};

