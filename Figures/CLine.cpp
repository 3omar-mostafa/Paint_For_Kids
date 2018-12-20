#include "CLine.h"

CLine::CLine(Point P_1, Point P_2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = P_1;
	P2 = P_2;
	FigType = LINE;
}

Point CLine::getP1() {
	return P1;
}
Point CLine::getP2() {
	return P2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(P1, P2, FigGfxInfo, Selected);
}

double CLine::getTriangularArea(int x, int y) {
	// Area of any triangle using vertices is 0.5* absolute of the followning determinant
	// | x1	 y1	 1 |
	// | x2	 y2	 1 |  = 0.5* | ( x1(y2-y3) +x2(y3-y1) +x3(y1-y2) ) |
	// | x3	 y3	 1 |

	return 0.5* abs(P1.x*(P2.y - y) + P2.x * (y - P1.y) + x * (P1.y - P2.y));
}

bool CLine::doesItContain(int x, int y) {
	// I am going to create a triangle using 2 point of the line and the given point
	// the normal distance between the line and the given point (height) is area/length of line(base)

	int leftX = (P2.x > P1.x) ? P1.x - 3 : P2.x - 3;
	int rightX = (P2.x < P1.x) ? P1.x + 3 : P2.x + 3;
	int upY = (P2.y > P1.y) ? P1.y - 3 : P2.y - 3;
	int downY = (P2.y < P1.y) ? P1.y + 3 : P2.y + 3;
	if (x >= leftX && x <= rightX && y >= upY && y <= downY) {
		double lengthOFLine = sqrt((rightX - leftX)*(rightX - leftX) + (downY - upY)*(downY - upY));
		if (getTriangularArea(x, y) / lengthOFLine <= 3) {
			return true;
		}
	}
	return false;
}

void CLine::Resize(float R)
{
	Point MP = (P1 + P2) / 2;
	Point C1, C2;

	//Setting the Vertical Coordinates:
	int Lower = (P1.y > P2.y) ? P1.y : P2.y;
	int Vertical = Lower - MP.y;
	if (P1.y > P2.y)
	{
		C1.y = MP.y + Vertical * R;
		C2.y = MP.y - Vertical * R;
	}
	else
	{
		C1.y = MP.y - Vertical * R;
		C2.y = MP.y + Vertical * R;
	}

	//Setting the Horizontal Coordinates:
	int Further = (P1.x > P2.x) ? P1.x : P2.x;
	int Horizontal = Further - MP.x;
	if (P1.x > P2.x)
	{
		C1.x = MP.x + Horizontal * R;
		C2.x = MP.x - Horizontal * R;
	}
	else
	{
		C1.x = MP.x - Horizontal * R;
		C2.x = MP.x + Horizontal * R;
	}

	//Validation:
	if (C2.y < UI.ToolBarHeight || C1.y > UI.height - UI.StatusBarHeight || C2.x < UI.MenuActionWidth)
		return;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CLine(C1, C2, FigGfxInfo);
	setID(oldID);
}

void CLine::Save(ofstream &OutFile)
{
	string Info = StoreType(FigType) + " " + to_string(ID) + " " + P1.Data() + " " + P2.Data() + " " + FigGfxInfo.Data();
	OutFile << endl << Info;
}

void CLine::Load(ifstream &InFile)
{
	Point Pi, Pf;
	GfxInfo LineGfxInfo;
	InFile >> ID;
	Pi.Read(InFile);
	Pf.Read(InFile);
	LineGfxInfo.Read(InFile);
	LineGfxInfo.isFilled = false;
	*this = CLine(Pi, Pf, LineGfxInfo);
}

void CLine::PrintInfo(Output * pOut)
{
	string s;
	s = "ID: " + to_string(ID) + "    Points: (" + to_string(P1.x) + ", " + to_string(P1.y) + "), (" + to_string(P2.x) + ", " + to_string(P2.y) + ")    ";
	s += "Length: " + to_string(sqrt((P2.x - P1.x)*(P2.x - P1.x) + (P2.y - P1.y)*(P2.y - P1.y)));
	pOut->PrintMessage(s);
}
