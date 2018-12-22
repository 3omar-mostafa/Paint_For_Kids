#ifndef ELPS_H
#define ELPS_H

#include "CFigure.h"
#include "..\GUI\Output.h"


class CEllipse : public CFigure
{
private:
	Point Corner1, Corner2;
	Point Center;
public:
	CEllipse(Point Center, GfxInfo FigureGfxInfo);
	CEllipse(Point Corner1, Point Corner2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	Point getCenter();

	int getVertical() const;
	int getHorizontal() const;

	bool doesItContain(int x, int y);
	virtual bool Resize(double);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif
