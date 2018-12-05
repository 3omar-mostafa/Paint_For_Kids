
#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point P1;
	Point P2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	Point getP1();
	Point getP2();
	bool doesItContain(int x, int y);

private:
	double getTriangularArea(int x, int y);
};

#endif