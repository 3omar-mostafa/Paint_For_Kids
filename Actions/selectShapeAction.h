#pragma once
#include "Action.h"

class selectShapeAction :public Action
{
public:
	selectShapeAction(ApplicationManager* pApp);
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};

