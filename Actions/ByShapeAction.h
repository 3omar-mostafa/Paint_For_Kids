#pragma once 
#include "Action.h"
class ByShapeAction :public Action
{
	int Correct, Wrong;
	FigureType FIG_TYPE;
	//Output* pOut;
	//Input* pIn;
public:
	ByShapeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	void Play();
	virtual void Execute();

};