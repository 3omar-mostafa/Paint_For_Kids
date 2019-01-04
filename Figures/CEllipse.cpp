#include "CEllipse.h"

CEllipse::CEllipse(Point center, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = center;
	Corner1 = center + Point(120, 60);
	Corner2 = center + Point(-120, -60);
	figType = ELLIPSE;
}

CEllipse::CEllipse(Point C1, Point C2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = C1;
	Corner2 = C2;
	Center = (Corner1 + Corner2) / 2;
	figType = ELLIPSE;
}

Point CEllipse::getCenter() const
{
	return Center;
}

int CEllipse::getVertical() const {
	return abs(Corner1.y - Center.y);
}

int CEllipse::getHorizontal() const {
	return abs(Corner1.x - Center.x);
}

void CEllipse::draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a rhombus on the screen	
	pOut->drawEllipse(Corner1, Corner2, figGfxInfo, selected);
}

bool CEllipse::doesItContain(int x, int y) {
	// eq of ellipse: x^2/a^2 + y^2/b^2 = 1
	// which equals b^2 * x^2 + a^2 * y^2 = a^2 * b^2
	long long X = x - Center.x;
	long long Y = y - Center.y;
	long long a = Corner1.x - Center.x;
	long long b = Corner1.y - Center.y;

	return b * b * X * X + a * a * Y * Y <= a * a * b * b;
}

bool CEllipse::resize(double R)
{
	if (R < 1.01 && R> 0.99) // if the user didn't select any ratio from the menu
							// didn't use == to avoid precision errors
		return false;

	Point C1, C2;

	//Setting the Vertical Coordinates:
	int lower = (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	int vertical = lower - Center.y;
	C1.y = Center.y + vertical * R;
	C2.y = Center.y - vertical * R;

	//Setting the Horizontal Coordinates:
	int further = (Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int horizontal = further - Center.x;
	C1.x = Center.x + horizontal * R;
	C2.x = Center.x - horizontal * R;

	//Validation:
	if (C2.y < UI.ToolBarHeight || C1.y > UI.height - UI.StatusBarHeight || C2.x < UI.MenuActionWidth)
		return false;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CEllipse(C1, C2, figGfxInfo);
	setID(oldID);

	return true;
}

void CEllipse::save(ofstream &OutFile)
{
	string info = storeType(figType) + " " + to_string(ID) + " " + Corner1.data() + " " + Corner2.data() + " " + figGfxInfo.data();
	OutFile << endl << info;
}

void CEllipse::load(ifstream &InFile)
{
	Point P1, P2;
	GfxInfo EllipseGfxInfo;
	InFile >> ID;
	P1.read(InFile);
	P2.read(InFile);
	EllipseGfxInfo.read(InFile);
	*this = CEllipse(P1, P2, EllipseGfxInfo);
}

void CEllipse::printInfo(Output * pOut)
{
	string s = "ID: " + to_string(ID) + "    center Point: (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->printMessage(s);
}
