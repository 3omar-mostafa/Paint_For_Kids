#pragma once
#include "Action.h"
class ChangeFillColor :public Action
{
	Point P;
public:
	ChangeFillColor(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

