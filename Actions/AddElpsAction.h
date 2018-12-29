#ifndef ADD_ELLIPSE_ACTION_H
#define ADD_ELLIPSE_ACTION_H

#include "Action.h"

//Add Ellipse Action class
class addEllipseAction : public Action
{
private:
	Point P; //Ellipse center
	GfxInfo ElpsGfxInfo;
public:
	addEllipseAction(ApplicationManager *pApp);

	//Reads ellipse center
	void readActionParameters() override;

	//Add ellipse to the ApplicationManager
	void execute() override;

};

#endif