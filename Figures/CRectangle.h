#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	Point getP1();
	Point getP2();
	bool doesItContain(int x, int y);

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif