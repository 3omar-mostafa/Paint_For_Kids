#pragma once
#include "Action.h"
class loadAction :public Action
{
	ActionType confirm;	//An ActionType variable to act as a confirmation for the action
public:
	loadAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
	void readFigures(ifstream&) const;	//Reads Figure Information from a file
	void quickLoad() const;	//Loads without confirmation or asking for a name for the file
};

