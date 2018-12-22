#include "CTriangle.h"

CTriangle::CTriangle(Point A, Point B, Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = A;
	P2 = B;
	P3 = C;
	FigType = TRIANGLE;
}

Point CTriangle::getP1(){
	return P1 ;
}
Point CTriangle::getP2(){
	return P2 ;
}
Point CTriangle::getP3(){
	return P3 ;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);
}

double CTriangle::getTriangularArea(Point p1, Point p2, Point p3) {
	// Area of any triangle using vertices is 0.5* absolute of the followning determinant
	// | x1	 y1	 1 |
	// | x2	 y2	 1 |  = 0.5* | ( x1(y2-y3) +x2(y3-y1) +x3(y1-y2) ) |
	// | x3	 y3	 1 |

	return 0.5* abs(p1.x*(p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

bool CTriangle::isColinear(Point p1, Point p2, Point p3) {
	// I am going to create a triangle using 2 point of the line and the given point
	// the normal distance between the line and the given point (height) is area/length of line(base)

	int leftX = (p2.x > p1.x) ? p1.x - 3 : p2.x - 3;
	int rightX = (p2.x < p1.x) ? p1.x + 3 : p2.x + 3;
	int upY = (p2.y > p1.y) ? p1.y - 3 : p2.y - 3;
	int downY = (p2.y < p1.y) ? p1.y + 3 : p2.y + 3;

	if (p3.x >= leftX && p3.x <= rightX && p3.y >= upY && p3.y <= downY) {
		double lengthOFLine = sqrt((rightX - leftX)*(rightX - leftX) + (downY - upY)*(downY - upY));
		if (getTriangularArea(p1,p2,p3) / lengthOFLine <= 3) {
			return true;
		}
	}
	return false;
}

bool CTriangle::doesItContain(int x, int y) {
	Point p4;
	p4.x = x;
	p4.y = y;

	// if the point is inside the triangle and we connected it with the vertices
	// we will have 3 smaller triangles and the sum of their areas MUST equal the bigger one

	double totalArea = getTriangularArea(P1, P2, P3);
	double area1 = getTriangularArea(P1, P2, p4);
	double area2 = getTriangularArea(P1, p4, P3);
	double area3 = getTriangularArea(p4, P2, P3);

	if (abs(totalArea - (area1 + area2 + area3)) <= 1) {
		return true;
	}
	
	return false;
}

bool CTriangle::Resize(double R)
{
	Point MP = (P1 + P2 + P3) / 3;
	Point C1, C2, C3;

	//Resizing each point at a time:
	// P1:
	if (P1.x > MP.x)
	{
		int diff = P1.x - MP.x;
		C1.x = MP.x + diff * R;
	}
	else
	{
		int diff = MP.x - P1.x;
		C1.x = MP.x - diff * R;
	}

	if (P1.y > MP.y)
	{
		int diff = P1.y - MP.y;
		C1.y = MP.y + diff * R;
	}
	else
	{
		int diff = MP.y - P1.y;
		C1.y = MP.y - diff * R;
	}

	// P2:
	if (P2.x > MP.x)
	{
		int diff = P2.x - MP.x;
		C2.x = MP.x + diff * R;
	}
	else
	{
		int diff = MP.x - P2.x;
		C2.x = MP.x - diff * R;
	}

	if (P2.y > MP.y)
	{
		int diff = P2.y - MP.y;
		C2.y = MP.y + diff * R;
	}
	else
	{
		int diff = MP.y - P2.y;
		C2.y = MP.y - diff * R;
	}

	// P3:
	if (P3.x > MP.x)
	{
		int diff = P3.x - MP.x;
		C3.x = MP.x + diff * R;
	}
	else
	{
		int diff = MP.x - P3.x;
		C3.x = MP.x - diff * R;
	}

	if (P3.y > MP.y)
	{
		int diff = P3.y - MP.y;
		C3.y = MP.y + diff * R;
	}
	else
	{
		int diff = MP.y - P3.y;
		C3.y = MP.y - diff * R;
	}

	//Validation:
	if (C1.y < UI.ToolBarHeight || C1.y > UI.height - UI.StatusBarHeight || C1.x < UI.MenuActionWidth)
		return false;
	if (C2.y < UI.ToolBarHeight || C2.y > UI.height - UI.StatusBarHeight || C2.x < UI.MenuActionWidth)
		return false;
	if (C3.y < UI.ToolBarHeight || C3.y > UI.height - UI.StatusBarHeight || C3.x < UI.MenuActionWidth)
		return false;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CTriangle(C1, C2, C3, FigGfxInfo);
	setID(oldID);
	return true;
}

void CTriangle::Save(ofstream &OutFile)
{
	string Info = StoreType(FigType) + " " + to_string(ID) + " " + P1.Data() + " " + P2.Data() + " " + P3.Data() + " " + FigGfxInfo.Data();
	OutFile << endl << Info;
}

void CTriangle::Load(ifstream &InFile)
{
	Point P_1, P_2, P_3;
	GfxInfo TriGfxInfo;
	InFile >> ID;
	P_1.Read(InFile);
	P_2.Read(InFile);
	P_3.Read(InFile);
	TriGfxInfo.Read(InFile);
	*this = CTriangle(P_1, P_2, P_3, TriGfxInfo);
}

void CTriangle::PrintInfo(Output * pOut)
{
	string s;
	s = "ID: " + to_string(ID) + "    Points: (" + to_string(P1.x) + ", " + to_string(P1.y) + "), (" + to_string(P2.x) + ", " + to_string(P2.y) + "), (" + to_string(P3.x) + ", " + to_string(P3.y) + ") ";
	pOut->PrintMessage(s);
}
