#pragma once
#include"Action.h"
class ByColorAction :public Action
{
	int Correct, Wrong;
	color FIG_COLOR;
	bool Terminate;
public:
	ByColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	bool Play();
	void Reset();
	virtual void Execute();
	string colorname(color c);
};
