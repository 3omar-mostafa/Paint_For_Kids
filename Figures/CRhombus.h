#ifndef C_RHOMBUS_H
#define C_RHOMBUS_H

#include "CFigure.h"

class CRhombus : public CFigure
{
	Point center;
	int xArr[4];
	int yArr[4];
public:
	//Creates a Rhombus with the center and the Horizontal and Vertical Distances from the center
	CRhombus(Point P, GfxInfo FigureGfxInfo, int a = 120, int b = 60);
	
	//Creates a Rhombus from an array of X and Y coordinates
	CRhombus(const int* , const int* , GfxInfo );

	void draw(Output* ) const override;
	Point getCenter() const;

	//Returns the Vertical Distance of the Furthest Point from the center
	int getVertical() const;

	//Returns the Horizontal Distance of the Furthest Point from the center
	int getHorizontal() const;

	bool doesItContain(int x, int y) override;
	bool resize(double) override;
	void save(ofstream & ) override;
	void load(ifstream & ) override;
	void printInfo(Output* ) override;
};

#endif
