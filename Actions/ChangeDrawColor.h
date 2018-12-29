#pragma once
#include "Action.h"
class changeDrawColor :public Action
{
	Point P;
public:
	changeDrawColor(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

