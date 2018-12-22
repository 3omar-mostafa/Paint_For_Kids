#pragma once 
#include "Action.h"
class ByShapeAction :public Action
{
	int Correct, Wrong;
	FigureType FIG_TYPE;
	bool Terminate;
	
public:
	ByShapeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	bool Play();
	void Reset();
	virtual void Execute();
};