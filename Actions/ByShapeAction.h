#pragma once 
#include "Action.h"
class byShapeAction :public Action
{
	int Correct, Wrong;
	FigureType FIG_TYPE;
	bool terminate;
	
public:
	byShapeAction(ApplicationManager *pApp);
	void readActionParameters() override;
	bool Play();
	void reset() const;
	void execute() override;
};