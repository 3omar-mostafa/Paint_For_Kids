#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class CutAction :public Action
{
	CFigure* cut;
public:
	CutAction(ApplicationManager *);
	~CutAction();
	void readActionParameters() override;
	void execute() override;
};

