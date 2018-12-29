#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class pasteAction :public Action
{
	Point newFigCenter;
	cFigure* toPaste;
	GfxInfo toPasteGfxInfo;
public:

	pasteAction(ApplicationManager*);
	virtual void validateRectangle(Point&, Point&, cRectangle*);
	virtual void validateTriangle(Point&, Point&, Point&, cTriangle*);
	virtual void validateEllipse(Point&, CEllipse*);
	virtual void validateRhombus(Point&, cRhombus*);
	virtual void validateLine(Point&, Point&, CLine*);
	void readActionParameters() override;
	void execute() override;
};

