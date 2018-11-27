
#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point lim1;
	Point lim2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif