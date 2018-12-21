#include "CEllipse.h"

CEllipse::CEllipse(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
	Corner1 = P + Point(120, 60);
	Corner2 = P + Point(-120, -60);
	FigType = ELLIPSE;
}

CEllipse::CEllipse(Point C1, Point C2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = C1;
	Corner2 = C2;
	Center = (Corner1 + Corner2) / 2;
	FigType = ELLIPSE;
}

Point CEllipse::getCenter() {
	return Center;
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a rhombus on the screen	
	pOut->DrawEllipse(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CEllipse::doesItContain(int x, int y) {
	// eq of ellipse: x^2/a^2 + y^2/b^2 = 1
	long long X = x - Center.x;
	long long Y = y - Center.y;
	long long a = Corner1.x - Center.x;
	long long b = Corner1.y - Center.y;

	if (b*b * X*X + a*a * Y*Y <= a*a * b*b) {
		return true;
	}

	return false;
}

void CEllipse::Resize(float R)
{
	Point C1, C2;

	//Setting the Vertical Coordinates:
	int Lower = (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	int Vertical = Lower - Center.y;
	C1.y = Center.y + Vertical * R;
	C2.y = Center.y - Vertical * R;

	//Setting the Horizontal Coordinates:
	int Further = (Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Horizontal = Further - Center.x;
	C1.x = Center.x + Horizontal * R;
	C2.x = Center.x - Horizontal * R;

	//Validation:
	if (C2.y < UI.ToolBarHeight || C1.y > UI.height - UI.StatusBarHeight || C2.x < UI.MenuActionWidth)
		return;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CEllipse(C1, C2, FigGfxInfo);
	setID(oldID);
}

void CEllipse::Save(ofstream &OutFile)
{
	string Info = StoreType(FigType) + " " + to_string(ID) + " " + Center.Data() + " " + FigGfxInfo.Data();
	OutFile << endl << Info;
}

void CEllipse::Load(ifstream &InFile)
{
	Point P;
	GfxInfo ElpsGfxInfo;
	InFile >> ID;
	P.Read(InFile);
	ElpsGfxInfo.Read(InFile);
	*this = CEllipse(P, ElpsGfxInfo);
}

void CEllipse::PrintInfo(Output * pOut)
{
	string s;
	s = "ID: " + to_string(ID) + "    Center Point: (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->PrintMessage(s);
}
