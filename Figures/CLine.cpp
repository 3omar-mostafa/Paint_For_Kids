#include "CLine.h"

CLine::CLine(Point P_1, Point P_2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = P_1;
	P2 = P_2;
	figType = LINE;
}

Point CLine::getP1() const
{
	return P1;
}
Point CLine::getP2() const
{
	return P2;
}

void CLine::draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->drawLine(P1, P2, figGfxInfo, selected);
}

double CLine::getTriangularArea(int x, int y) const
{
	// Area of any triangle using vertices is 0.5* absolute of the following determinant
	// | x1	 y1	 1 |
	// | x2	 y2	 1 |  = 0.5* | ( x1(y2-y3) +x2(y3-y1) +x3(y1-y2) ) |
	// | x3	 y3	 1 |

	return 0.5* abs(P1.x*(P2.y - y) + P2.x * (y - P1.y) + x * (P1.y - P2.y));
}

bool CLine::doesItContain(int x, int y) {
	// I am going to create a triangle using 2 point of the line and the given point
	// the normal distance between the line and the given point (height) is 2*area/length of line(base)

	int leftX = (P2.x > P1.x) ? P1.x - figGfxInfo.borderSize/2 : P2.x - figGfxInfo.borderSize/2;
	int rightX = (P2.x < P1.x) ? P1.x + figGfxInfo.borderSize/2 : P2.x + figGfxInfo.borderSize/2;
	int upY = (P2.y > P1.y) ? P1.y - figGfxInfo.borderSize/2 : P2.y - figGfxInfo.borderSize/2;
	int downY = (P2.y < P1.y) ? P1.y + figGfxInfo.borderSize/2 : P2.y + figGfxInfo.borderSize/2;
	if (x >= leftX && x <= rightX && y >= upY && y <= downY) {
		// length of line = sqrt ( (x2-x1)^2 + (y2-y1)^2 )
		double lengthOFLine = sqrt((rightX - leftX)*(rightX - leftX) + (downY - upY)*(downY - upY));
		if (2*getTriangularArea(x, y) / lengthOFLine <= figGfxInfo.borderSize/2) {
			return true;
		}
	}
	return false;
}

bool CLine::resize(double R)
{
	if (R < 1.01 && R> 0.99) // if the user didn't select any ratio from the menu
		return false;

	Point center = (P1 + P2) / 2;
	Point C1, C2;

	//Setting the Vertical Coordinates:
	int lower = (P1.y > P2.y) ? P1.y : P2.y;
	int vertical = lower - center.y;
	if (P1.y > P2.y)
	{
		C1.y = center.y + vertical * R;
		C2.y = center.y - vertical * R;
	}
	else
	{
		C1.y = center.y - vertical * R;
		C2.y = center.y + vertical * R;
	}

	//Setting the Horizontal Coordinates:
	int further = (P1.x > P2.x) ? P1.x : P2.x;
	int horizontal = further - center.x;
	if (P1.x > P2.x)
	{
		C1.x = center.x + horizontal * R;
		C2.x = center.x - horizontal * R;
	}
	else
	{
		C1.x = center.x - horizontal * R;
		C2.x = center.x + horizontal * R;
	}

	//Validation:
	if (C1.y < UI.ToolBarHeight || C2.y < UI.ToolBarHeight ||  C1.y > UI.height - UI.StatusBarHeight || C2.y > UI.height - UI.StatusBarHeight || C1.x < UI.MenuActionWidth || C2.x < UI.MenuActionWidth)
		return false ;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CLine(C1, C2, figGfxInfo);
	setID(oldID);
	return true;
}

void CLine::save(ofstream &OutFile)
{
	string info = storeType(figType) + " " + to_string(ID) + " " + P1.data() + " " + P2.data() + " " + figGfxInfo.data();
	OutFile << endl << info;
}

void CLine::load(ifstream &InFile)
{
	Point Pi, Pf;
	GfxInfo LineGfxInfo;
	InFile >> ID;
	Pi.read(InFile);
	Pf.read(InFile);
	LineGfxInfo.read(InFile);
	LineGfxInfo.isFilled = false;
	*this = CLine(Pi, Pf, LineGfxInfo);
}

void CLine::printInfo(Output * pOut)
{
	string s = "ID: " + to_string(ID) + "    Points: (" + to_string(P1.x) + ", " + to_string(P1.y) + "), (" +
		to_string(P2.x) + ", " + to_string(P2.y) + ")    " + "Length: " + to_string(
			sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)));
	pOut->printMessage(s);
}
