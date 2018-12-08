#include "CEllipse.h"

CEllipse::CEllipse(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}

Point CEllipse::getCenter(){
	return Center;
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a rhombus on the screen	
	pOut->DrawEllipse(Center, FigGfxInfo, Selected);
}

bool CEllipse::doesItContain(int x, int y) {
	// eq of ellipse: x^2/a^2 + y^2/b^2 = 1
	long long X = x - Center.x;
	long long Y = y - Center.y;

	if (isFilled()) {
		if (6400 * X*X + 22500 * Y*Y <= 144000000) {
			return true;
		}
	}
	else {
		if (6400 * X*X + 22500 * Y*Y >= 135000000 && 6400 * X*X + 22500 * Y*Y <= 150000000) {
			return true;
		}
	}
	return false;
}

string CEllipse::getInfo() {
	string s;
	s = "ID : " + to_string(ID) +  " Center Point : ( " + to_string( Center.x ) + " , " + to_string(Center.y) + " )" ;
	return s;
}

void CEllipse::Save(ofstream &OutFile)
{
	string Info = getInfo();
	OutFile << Info << endl;
}

void CEllipse::Load(ifstream &InFile)
{
}