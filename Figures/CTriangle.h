#ifndef TRI_H
#define TRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point P1, P2, P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif