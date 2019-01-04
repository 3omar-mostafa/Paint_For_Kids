#ifndef ADD_RHOMBUS_ACTION_H
#define ADD_RHOMBUS_ACTION_H

#include "Action.h"

//Add Rhombus Action class
class AddRhombusAction : public Action
{
private:
	Point P; //Rhombus center
	GfxInfo RhomGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads rhombus center
	void readActionParameters() override;

	//Add rhombus to the ApplicationManager
	void execute() override;

};

#endif