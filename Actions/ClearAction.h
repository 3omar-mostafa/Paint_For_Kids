#ifndef CLEAR_H
#define CLEAR_H

#include "Action.h"

//Clear action class
class ClearAction : public Action
{
private:
	int FigCount;
	ActionType ThisAction;
public:
	ClearAction(ApplicationManager *pApp);

	//Reads Action parameters
	virtual void ReadActionParameters();

	//Exit the program
	virtual void Execute();
};

#endif