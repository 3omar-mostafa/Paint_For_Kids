#ifndef CLEAR_H
#define CLEAR_H

#include "Action.h"

//Clear action class
class clearAction : public Action
{
private:
	ActionType Confirm;	//An ActionType variable to act as a confirmation for the action
public:
	clearAction(ApplicationManager *pApp);
	void readActionParameters() override;
	void execute() override;
};

#endif