#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
	xArr[0] = P.x;			xArr[1] = P.x + 120;	xArr[2] = P.x;			xArr[3] = P.x - 120;
	yArr[0] = P.y + 60;		yArr[1] = P.y;			yArr[2] = P.y - 60;		yArr[3] = P.y;
	FigType = RHOMBUS;
}

CRhombus::CRhombus(const int * X, const int * Y, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	for (int i = 0; i < 4; i++)
		xArr[i] = X[i], yArr[i] = Y[i];
	Center = Point((xArr[1] + xArr[3]) / 2, (yArr[0] + yArr[2]) / 2);
	FigType = RHOMBUS;
}

Point CRhombus::getCenter() {
	return Center;
}

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	//pOut->DrawRhombus(Center, FigGfxInfo, Selected);
	pOut->DrawRhombus(xArr, yArr, FigGfxInfo, Selected);
}

bool CRhombus::doesItContain(int x, int y) {
	int X = x - Center.x;
	int Y = y - Center.y;
	int a = xArr[1] - Center.x;
	int b = yArr[0] - Center.y;

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

bool CRhombus::Resize(double R)
{
	if (R < 1.01 && R> 0.99) // if the user didn't select any ratio from the menu
		return false;

	//Setting the Horizontal Coordinates:
	int a = xArr[1] - Center.x;
	int X[4] = { xArr[0], Center.x + a * R, xArr[2], Center.x - a * R };

	//Setting the Vertical Coordinates:
	int b = yArr[0] - Center.y;
	int Y[4] = { Center.y + b * R, yArr[1], Center.y - b * R , yArr[3] };

	//Validation:
	if (Y[0] > UI.height - UI.StatusBarHeight || Y[2] < UI.ToolBarHeight)
		return false;
	if (X[3] < UI.MenuActionWidth)
		return false;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CRhombus(X, Y, FigGfxInfo);
	setID(oldID);
	return true;
}

void CRhombus::Save(ofstream &OutFile)
{
	string Info = StoreType(FigType) + " " + to_string(ID) + " " + Center.Data() + " " + FigGfxInfo.Data();
	OutFile << endl << Info;
}

void CRhombus::Load(ifstream &InFile)
{
	Point P;
	GfxInfo RhomGfxInfo;
	InFile >> ID;
	P.Read(InFile);
	RhomGfxInfo.Read(InFile);
	*this = CRhombus(P, RhomGfxInfo);
}

void CRhombus::PrintInfo(Output * pOut)
{
	string s;
	s = "ID: " + to_string(ID) + "    Center Point: (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->PrintMessage(s);
}
