#ifndef C_LINE_H
#define C_LINE_H

#include "CFigure.h"

class CLine : public CFigure
{
	Point P1;
	Point P2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	void draw(Output* pOut) const override;

	Point getP1() const;
	Point getP2() const;
	bool doesItContain(int x, int y) override;

	bool resize(double) override;

	void save(ofstream &OutFile) override;
	void load(ifstream &Infile) override;
	void printInfo(Output* pOut) override;

private:
	double getTriangularArea(int x, int y) const;
};

#endif