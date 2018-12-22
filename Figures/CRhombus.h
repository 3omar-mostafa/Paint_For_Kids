#ifndef RHOM_H
#define RHOM_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
	int xArr[4];
	int yArr[4];
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	CRhombus(const int* X, const int* Y, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	Point getCenter();
	bool doesItContain(int x, int y);

	virtual bool Resize(double);

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif
