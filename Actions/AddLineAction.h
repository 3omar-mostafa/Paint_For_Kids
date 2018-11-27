#ifndef ADD_Line_ACTION_H
#define ADD_Line_ACTION_H

#include "Action.h"
class AddLineAction :public Action
{
private:
	Point P1, P2; //line limits
	GfxInfo LineGfxInfo;


public:

	AddLineAction(ApplicationManager *pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
};

#endif