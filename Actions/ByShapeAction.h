#pragma once 
#include "Action.h"
class ByShapeAction :public Action
{
	int Correct, Wrong;
	FigureType FIG_TYPE;
	bool terminate;
	
public:
	ByShapeAction(ApplicationManager *pApp);
	void readActionParameters() override;
	bool Play();
	void reset() const;
	void execute() override;
};