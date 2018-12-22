#ifndef ADD_ELPS_ACTION_H
#define ADD_ELPS_ACTION_H

#include "Action.h"

//Add Ellipse Action class
class AddElpsAction : public Action
{
private:
	Point P; //Ellipse Center
	GfxInfo ElpsGfxInfo;
public:
	AddElpsAction(ApplicationManager *pApp);

	//Reads ellipse center
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();

};

#endif