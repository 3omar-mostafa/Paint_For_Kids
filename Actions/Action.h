#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppManager to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void readActionParameters() = 0;

	//Execute action (code depends on action type)
	virtual void execute() = 0;

};

#endif