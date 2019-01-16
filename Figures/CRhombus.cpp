#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo, int a, int b) :CFigure(FigureGfxInfo)
{
	center = P;
	xArr[0] = P.x;			xArr[1] = P.x + a;		xArr[2] = P.x;			xArr[3] = P.x - a;
	yArr[0] = P.y + b;		yArr[1] = P.y;			yArr[2] = P.y - b;		yArr[3] = P.y;
	figType = RHOMBUS;
}

CRhombus::CRhombus(const int * X, const int * Y, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	for (int i = 0; i < 4; i++)
		xArr[i] = X[i], yArr[i] = Y[i];
	center = Point((xArr[1] + xArr[3]) / 2, (yArr[0] + yArr[2]) / 2);
	figType = RHOMBUS;
}

Point CRhombus::getCenter() const {
	return center;
}

int CRhombus::getVertical() const {
	return abs(yArr[0] - center.y);
}

int CRhombus::getHorizontal() const {
	return abs(xArr[1] - center.x);
}

void CRhombus::draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	//pOut->DrawRhombus(center, FigGfxInfo, Selected);
	pOut->drawRhombus(xArr, yArr, figGfxInfo, selected);
}

bool CRhombus::doesItContain(int x, int y) {
	int X = x - center.x;
	int Y = y - center.y;
	int a = xArr[1] - center.x ;
	int b = yArr[0] - center.y ;

	double errorPercentage = figGfxInfo.borderSize / 100.0;

	if (X >= -a - figGfxInfo.borderSize/2 && X <= a + figGfxInfo.borderSize/2 && Y >= -b- figGfxInfo.borderSize/2 && Y <= b+ figGfxInfo.borderSize/2) {

		// the center of the rhombus is the origin
		// then these equations are the 4 equations of straight lines of the rhombus

		if (isFilled()) {
			if (X >= 0  && Y >= 0 ) { //1st quad
				if (a * Y + b * X <= a * b *(1+errorPercentage))
					return true;
			}
			else if (X <= 0  && Y >= 0) { //2nd quad
				if (a * Y - b * X <= a * b*(1+errorPercentage))
					return true;
			}
			else if (X <= 0 && Y <= 0 ) { //3rd quad
				if (a * Y + b * X >= -a * b*(1+errorPercentage))
					return true;
			}
			else if (X >= 0 && Y <= 0) { //4th quad
				if (a * Y - b * X >= -a * b*(1+errorPercentage))
					return true;
			}
		}
		else
		{
			if (( a* Y + b * X <= a*b*(1+errorPercentage) && a * Y + b * X >= a*b*(1-errorPercentage)) //1st quadrant
				|| (a * Y - b * X <= a*b*(1+errorPercentage) && a * Y - b * X >= a*b*(1-errorPercentage)) //2nd quadrant
				|| (a * Y + b * X >= -a*b*(1+errorPercentage) && a * Y + b * X <= -a*b*(1-errorPercentage)) //3rd quadrant
				|| (a * Y - b * X >= -a*b*(1+errorPercentage) && a * Y - b * X <= -a*b*(1-errorPercentage))){ //4th quadrant
					return true;
			}
		}
	}

	return false;
}

bool CRhombus::resize(double R)
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
	*this = CRhombus(X, Y, figGfxInfo);
	setID(oldID);
	return true;
}

void CRhombus::save(ofstream &OutFile)
{
	string info = storeType(figType) + " " + to_string(ID) + " " + center.data() + " " + to_string(getHorizontal()) + " " + to_string(getVertical()) + " " + figGfxInfo.data();
	OutFile << endl << info;
}

void CRhombus::load(ifstream &InFile)
{
	Point P;
	int a, b;
	GfxInfo rhombusGfxInfo;
	InFile >> ID;
	P.read(InFile);
	InFile >> a >> b;
	rhombusGfxInfo.read(InFile);
	*this = CRhombus(P, rhombusGfxInfo, a, b);
}

void CRhombus::printInfo(Output * pOut)
{
	string s = "ID: " + to_string(ID) + "    center Point: (" + to_string(center.x) + ", " + to_string(center.y) + ")";
	pOut->printMessage(s);
}
