#include "CRhombus.h"

cRhombus::cRhombus(Point P, GfxInfo FigureGfxInfo, int a, int b) :cFigure(FigureGfxInfo)
{
	center = P;
	xArr[0] = P.x;			xArr[1] = P.x + a;		xArr[2] = P.x;			xArr[3] = P.x - a;
	yArr[0] = P.y + b;		yArr[1] = P.y;			yArr[2] = P.y - b;		yArr[3] = P.y;
	figType = RHOMBUS;
}

cRhombus::cRhombus(const int * X, const int * Y, GfxInfo FigureGfxInfo) :cFigure(FigureGfxInfo)
{
	for (int i = 0; i < 4; i++)
		xArr[i] = X[i], yArr[i] = Y[i];
	center = Point((xArr[1] + xArr[3]) / 2, (yArr[0] + yArr[2]) / 2);
	figType = RHOMBUS;
}

Point cRhombus::getCenter() const {
	return center;
}

int cRhombus::getVertical() const {
	return abs(yArr[0] - center.y);
}

int cRhombus::getHorizontal() const {
	return abs(xArr[1] - center.x);
}

void cRhombus::draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	//pOut->DrawRhombus(center, FigGfxInfo, Selected);
	pOut->drawRhombus(xArr, yArr, figGfxInfo, selected);
}

bool cRhombus::doesItContain(int x, int y) {
	int X = x - center.x;
	int Y = y - center.y;
	int a = xArr[1] - center.x;
	int b = yArr[0] - center.y;

	if (X >= -a && X <= a && Y >= -b && Y <= b) {

		// 1.1 is just an error percentage of 10%
		if (X >= 0 && X <= a && Y >= 0 && Y <= b) { //1st quad
			if (a * Y + b * X <= a * b *1.1 )
				return true;
		}
		else if (X <= 0 && X >= -a && Y >= 0 && Y <= b) { //2nd quad
			if (a * Y - b * X <= a * b*1.1)
				return true;
		}
		else if (X <= 0 && X >= -a && Y <= 0 && Y >= -b) { //3rd quad
			if (a * Y + b * X >= -a * b*1.1)
				return true;
		}
		else if (X >= 0 && X <= a && Y <= 0 && Y >= -b) { //4th quad
			if (a * Y - b * X >= -a * b*1.1)
				return true;
		}
	}

	return false;
}

bool cRhombus::resize(double R)
{
	if (R < 1.01 && R > 0.99) // if the user didn't select any ratio from the menu
		return false;

	//Setting the Horizontal Coordinates:
	int a = xArr[1] - center.x;
	int X[4] = { xArr[0], center.x + a * R, xArr[2], center.x - a * R };

	//Setting the Vertical Coordinates:
	int b = yArr[0] - center.y;
	int Y[4] = { center.y + b * R, yArr[1], center.y - b * R , yArr[3] };

	//Validation:
	if (Y[0] > UI.height - UI.StatusBarHeight || Y[2] < UI.ToolBarHeight)
		return false;
	if (X[3] < UI.MenuActionWidth)
		return false;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = cRhombus(X, Y, figGfxInfo);
	setID(oldID);
	return true;
}

void cRhombus::save(ofstream &OutFile)
{
	string info = storeType(figType) + " " + to_string(ID) + " " + center.data() + " " + to_string(getHorizontal()) + " " + to_string(getVertical()) + " " + figGfxInfo.data();
	OutFile << endl << info;
}

void cRhombus::load(ifstream &InFile)
{
	Point P;
	int a, b;
	GfxInfo rhombusGfxInfo;
	InFile >> ID;
	P.read(InFile);
	InFile >> a >> b;
	rhombusGfxInfo.read(InFile);
	*this = cRhombus(P, rhombusGfxInfo, a, b);
}

void cRhombus::printInfo(Output * pOut)
{
	string s = "ID: " + to_string(ID) + "    center Point: (" + to_string(center.x) + ", " + to_string(center.y) + ")";
	pOut->printMessage(s);
}
