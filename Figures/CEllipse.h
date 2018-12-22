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
	
	//Creates an Ellipse inscribed in the Rectangle formed by the 2 Points
	CEllipse(Point Corner1, Point Corner2, GfxInfo FigureGfxInfo);
	
	virtual void Draw(Output* pOut) const;
	Point getCenter();

	//Returns the Vertical Distance of the Furthest Point from the Center
	int getVertical() const;

	//Returns the Horizontal Distance of the Furthest Point from the Center
	int getHorizontal() const;

	bool doesItContain(int x, int y);
	virtual bool Resize(double);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif
