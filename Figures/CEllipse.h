#ifndef ELPS_H
#define ELPS_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif
