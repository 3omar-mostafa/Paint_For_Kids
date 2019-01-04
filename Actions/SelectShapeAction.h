#pragma once
#include "Action.h"

class SelectShapeAction :public Action
{
public:
	SelectShapeAction(ApplicationManager* pApp);
	//Reads rectangle parameters
	void readActionParameters() override;

	//Add rectangle to the ApplicationManager
	void execute() override;
};

