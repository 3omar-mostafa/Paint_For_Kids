#pragma once
#include "Action.h"
class changeFillColor :public Action
{
	Point P;
public:
	changeFillColor(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

