#ifndef RHOM_H
#define RHOM_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	Point getCenter();
	bool doesItContain(int x, int y);

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif
