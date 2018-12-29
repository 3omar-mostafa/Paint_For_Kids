#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class addRectAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	addRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	void readActionParameters() override;

	//Add rectangle to the ApplicationManager
	void execute() override;

};

#endif