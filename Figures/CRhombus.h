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
	//Creates a Rhombus with the Center and the Horizontal and Vertical Distances from the Center
	CRhombus(Point P, GfxInfo FigureGfxInfo, int a = 120, int b = 60);
	
	//Creates a Rhombus from an array of X and Y coordinates
	CRhombus(const int* X, const int* Y, GfxInfo FigureGfxInfo);
	
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
