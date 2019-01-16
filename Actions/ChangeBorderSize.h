#pragma once
#include "Action.h"
class ChangeBorderSize :public Action
{
	Point P;
public:
	ChangeBorderSize(ApplicationManager*);
	void readActionParameters() override;
	void execute() override;
};

