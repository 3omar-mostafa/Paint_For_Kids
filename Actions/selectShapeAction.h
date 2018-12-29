#pragma once
#include "Action.h"

class selectShapeAction :public Action
{
public:
	selectShapeAction(ApplicationManager* pApp);
	//Reads rectangle parameters
	void readActionParameters() override;

	//Add rectangle to the ApplicationManager
	void execute() override;
};

