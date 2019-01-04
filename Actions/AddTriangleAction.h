#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TriGfxInfo;
public:
	AddTriangleAction(ApplicationManager *pApp);

	//Reads triangle vertices
	void readActionParameters() override;

	//Add triangle to the ApplicationManager
	void execute() override;

};

#endif