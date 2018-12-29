#pragma once
#include"Action.h"
class byColorAction :public Action
{
	int correct, wrong;
	color FIG_COLOR;
	bool terminate;
public:
	byColorAction(ApplicationManager *pApp);
	void readActionParameters() override;
	bool play();
	void reset() const;
	void execute() override;
	static string colorName(color c);
};
