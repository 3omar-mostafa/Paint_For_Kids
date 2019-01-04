#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class CopyAction :public Action
{
	CFigure* copied;
public:
	CopyAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

