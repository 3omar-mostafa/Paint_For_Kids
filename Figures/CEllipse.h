#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "CFigure.h"
#include "..\GUI\Output.h"


class CEllipse : public CFigure
{
	Point Corner1, Corner2;
	Point Center;
public:
	CEllipse(Point center, GfxInfo FigureGfxInfo);
	
	//Creates an Ellipse inscribed in the Rectangle formed by the 2 Points
	CEllipse(Point C1, Point C2, GfxInfo FigureGfxInfo);

	void draw(Output* pOut) const override;
	Point getCenter() const;

	//Returns the Vertical Distance of the Furthest Point from the center
	int getVertical() const;

	//Returns the Horizontal Distance of the Furthest Point from the center
	int getHorizontal() const;

	bool doesItContain(int x, int y) override;
	bool resize(double) override;
	void save(ofstream &OutFile) override;
	void load(ifstream &Infile) override;
	void printInfo(Output* pOut) override;
};

#endif
