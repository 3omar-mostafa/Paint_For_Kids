#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class PasteAction :public Action
{
	Point newFigCenter;
	CFigure* toPaste;
	GfxInfo toPasteGfxInfo;
public:

	PasteAction(ApplicationManager*);
	virtual void validateRectangle(Point&, Point&, CRectangle*);
	virtual void validateTriangle(Point&, Point&, Point&, CTriangle*);
	virtual void validateEllipse(Point&, CEllipse*);
	virtual void validateRhombus(Point&, CRhombus*);
	virtual void validateLine(Point&, Point&, CLine*);
	void readActionParameters() override;
	void execute() override;
};

