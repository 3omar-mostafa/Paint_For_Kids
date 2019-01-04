#pragma once
#include "Action.h"

#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class DeleteAction :public Action
{
	CFigure * deletedFigure;
public:
	DeleteAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

