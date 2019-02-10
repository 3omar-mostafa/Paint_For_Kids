#pragma once
#include "Action.h"
class SaveAction :public Action
{
	ActionType Confirm;	//An ActionType variable to act as a confirmation for the action
	void savetoFile(string) const;
public:
	SaveAction(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
	void quickSave() const;	//Saves without confirmation or asking for a name for the file
	void saveForUndo();
};

