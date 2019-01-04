#ifndef EXIT_ACTION_H
#define EXIT_ACTION_H

#include "Action.h"

//Exit Action class
class ExitAction : public Action
{
private:
	int FigCount;
public:
	ExitAction(ApplicationManager *pApp);

	//Reads Action parameters
	void readActionParameters() override;

	//Exit the program
	void execute() override;

};

#endif