#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriAction : public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads triangle vertices
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};

#endif