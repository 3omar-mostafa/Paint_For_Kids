#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class copyAction :public Action
{
	CFigure* copied;
public:
	copyAction(ApplicationManager*);
	~copyAction();
	virtual void ReadActionParameters();
	virtual void Execute();
};

