#pragma once
#include "Action.h"
class saveAction :public Action
{
	ActionType Confirm;	//An ActionType variable to act as a confirmation for the action
public:
	saveAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
	void quickSave() const;	//Saves without confirmation or asking for a name for the file
};

