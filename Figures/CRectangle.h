#ifndef C_RECTANGLE_H
#define C_RECTANGLE_H

#include "CFigure.h"

class CRectangle : public CFigure
{
	Point corner1;
	Point corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	void draw(Output* pOut) const override;

	Point getP1() const;
	Point getP2() const;
	bool doesItContain(int x, int y) override;

	bool resize(double) override;

	void save(ofstream & ) override;
	void load(ifstream & ) override;
	void printInfo(Output* ) override;
};

#endif