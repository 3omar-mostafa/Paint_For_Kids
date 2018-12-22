#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class pasteAction :public Action
{
	Point newFigCenter;
	CFigure* toPaste;
	GfxInfo toPasteGfxInfo;
public:

	pasteAction(ApplicationManager*);
	virtual void ValidateRectangle(Point&, Point&, CRectangle*);
	virtual void ValidateTriangle(Point&, Point&, Point&, CTriangle*);
	virtual void ValidateEllipse(Point&, CEllipse*);
	virtual void ValidateRhombus(Point&, CRhombus*);
	virtual void ValidateLine(Point&, Point&, CLine*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~pasteAction();
};

