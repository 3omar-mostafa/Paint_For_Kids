#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	figType = RECTANGLE;
}

Point CRectangle::getP1() const
{
	return corner1;
}
Point CRectangle::getP2() const
{
	return corner2;
}

void CRectangle::draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->drawRectangle(corner1, corner2, figGfxInfo, selected);
}

bool CRectangle::doesItContain(int x, int y) {
	int x1 = corner1.x;
	int y1 = corner1.y;
	int x2 = corner2.x;
	int y2 = corner2.y;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);

	if (isFilled()) {
		if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
			return true;
	}
	else {
		if ( ( ( (x >= x1 && x <= x1 + figGfxInfo.borderSize) || (x <= x2 && x >= x2 - figGfxInfo.borderSize) ) && (y >= y1 && y <= y2) )
			|| ( (y >= y1 && y <= y1 + figGfxInfo.borderSize) || (y <= y2 && y >= y2 - figGfxInfo.borderSize) ) && (x >= x1 && x <= x2) )
		{
			return true;
		}
	}

	return false;
}

bool CRectangle::resize(double R)
{
	if (R < 1.01 && R> 0.99) // if the user didn't select any ratio from the menu
		return false;

	Point center = (corner1 + corner2) / 2;
	Point C1, C2;

	//Setting the Vertical Coordinates:
	int lower = (corner1.y > corner2.y) ? corner1.y : corner2.y;
	int vertical = lower - center.y;
	C1.y = center.y + vertical * R;
	C2.y = center.y - vertical * R;

	//Setting the Horizontal Coordinates:
	int further = (corner1.x > corner2.x) ? corner1.x : corner2.x;
	int horizontal = further - center.x;
	C1.x = center.x + horizontal * R;
	C2.x = center.x - horizontal * R;

	//Validation:
	if (C2.y < UI.ToolBarHeight || C1.y > UI.height - UI.StatusBarHeight || C2.x < UI.MenuActionWidth)
		return false;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CRectangle(C1, C2, figGfxInfo);
	setID(oldID);
	return true;
}

void CRectangle::save(ofstream &OutFile)
{
	string info = storeType(figType) + " " + to_string(ID) + " " + corner1.data() + " " + corner2.data() + " " + figGfxInfo.data();
	OutFile << endl << info;
}

void CRectangle::load(ifstream &InFile)
{
	Point P1, P2;
	GfxInfo rectangleGfxInfo;
	InFile >> ID;
	P1.read(InFile);
	P2.read(InFile);
	rectangleGfxInfo.read(InFile);
	*this = CRectangle(P1, P2, rectangleGfxInfo);
}

void CRectangle::printInfo(Output * pOut)
{
	string s = "ID: " + to_string(ID) + "    Points: (" + to_string(corner1.x) + ", " + to_string(corner1.y) + "), (" +
		to_string(corner2.x) + ", " + to_string(corner2.y) + ")    " + "Length: " +
		to_string(abs(corner1.x - corner2.x)) + "    Width: " + to_string(abs(corner1.y - corner2.y));
	pOut->printMessage(s);
}
