#pragma once
#include "Action.h"
class ChangeDrawColor :public Action
{
	Point P;
public:
	ChangeDrawColor(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

