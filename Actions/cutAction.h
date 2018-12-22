#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class cutAction :public Action
{
	CFigure* cut;
public:
	cutAction(ApplicationManager *);
	~cutAction();
	virtual void ReadActionParameters();
	virtual void Execute();
};

