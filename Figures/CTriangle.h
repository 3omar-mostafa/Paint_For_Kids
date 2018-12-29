#ifndef TRI_H
#define TRI_H

#include "cFigure.h"

class cTriangle : public cFigure
{
private:
	Point p1, p2, p3;
public:
	cTriangle(Point, Point, Point, GfxInfo );
	void draw(Output* pOut) const override;

	Point getP1() const;
	Point getP2() const;
	Point getP3() const;
	bool doesItContain(int x, int y) override;

	bool resize(double) override;

	void save(ofstream & ) override;
	void load(ifstream & ) override;
	void printInfo(Output* ) override;

private:
	double getTriangularArea(Point p1, Point p2, Point p3) const;
	bool isCollinear(Point p1, Point p2, Point p3) const;
};

#endif