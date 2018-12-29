#pragma once
#include "Action.h"
class saveByTypeAction :public Action
{
	ActionType confirm;	//An ActionType variable to act as a confirmation for the action
public:
	saveByTypeAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
	FigureType setSavedType() const;	//Determines the FigureType chosen for saving
};

