#ifndef TRI_H
#define TRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point P1, P2, P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	Point getP1();
	Point getP2();
	Point getP3();
	bool doesItContain(int x, int y);
	string getInfo();

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);

private:
	double getTriangularArea(Point p1, Point p2, Point p3);
	bool isColinear(Point p1, Point p2, Point p3);
};

#endif