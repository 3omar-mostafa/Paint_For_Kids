#include "CTriangle.h"

CTriangle::CTriangle(Point A, Point B, Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = A;
	p2 = B;
	p3 = C;
	figType = TRIANGLE;
}

Point CTriangle::getP1() const
{
	return p1 ;
}
Point CTriangle::getP2() const
{
	return p2 ;
}
Point CTriangle::getP3() const
{
	return p3 ;
}

void CTriangle::draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->drawTriangle(p1, p2, p3, figGfxInfo, selected);
}

double CTriangle::getTriangularArea(Point p1, Point p2, Point p3) const
{
	// Area of any triangle using vertices is 0.5* absolute of the following determinant
	// | x1	 y1	 1 |
	// | x2	 y2	 1 |  = 0.5* | ( x1(y2-y3) +x2(y3-y1) +x3(y1-y2) ) |
	// | x3	 y3	 1 |

	return 0.5* abs(p1.x*(p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

bool CTriangle::isCollinear(Point p1, Point p2, Point p3) const
{
	// I am going to create a triangle using 2 point of the line and the given point
	// the normal distance between the line and the given point (height) is area/length of line(base)

	int leftX = (p2.x > p1.x) ? p1.x - 3 : p2.x - 3;
	int rightX = (p2.x < p1.x) ? p1.x + 3 : p2.x + 3;
	int upY = (p2.y > p1.y) ? p1.y - 3 : p2.y - 3;
	int downY = (p2.y < p1.y) ? p1.y + 3 : p2.y + 3;

	if (p3.x >= leftX && p3.x <= rightX && p3.y >= upY && p3.y <= downY) {
		// length of line = sqrt ( (x2-x1)^2 + (y2-y1)^2 )
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

	double totalArea = getTriangularArea(p1, p2, p3);
	double area1 = getTriangularArea(p1, p2, p4);
	double area2 = getTriangularArea(p1, p4, p3);
	double area3 = getTriangularArea(p4, p2, p3);

	return abs(totalArea - (area1 + area2 + area3)) <= 1;
}

bool CTriangle::resize(double R)
{
	if (R < 1.01 && R> 0.99) // if the user didn't select any ratio from the menu
		return false;

	Point center = (p1 + p2 + p3) / 3;
	Point c1, c2, c3;

	//Resizing each point at a time:
	// p1:
	if (p1.x > center.x)
	{
		int diff = p1.x - center.x;
		c1.x = center.x + diff * R;
	}
	else
	{
		int diff = center.x - p1.x;
		c1.x = center.x - diff * R;
	}

	if (p1.y > center.y)
	{
		int diff = p1.y - center.y;
		c1.y = center.y + diff * R;
	}
	else
	{
		int diff = center.y - p1.y;
		c1.y = center.y - diff * R;
	}

	// p2:
	if (p2.x > center.x)
	{
		int diff = p2.x - center.x;
		c2.x = center.x + diff * R;
	}
	else
	{
		int diff = center.x - p2.x;
		c2.x = center.x - diff * R;
	}

	if (p2.y > center.y)
	{
		int diff = p2.y - center.y;
		c2.y = center.y + diff * R;
	}
	else
	{
		int diff = center.y - p2.y;
		c2.y = center.y - diff * R;
	}

	// P3:
	if (p3.x > center.x)
	{
		int diff = p3.x - center.x;
		c3.x = center.x + diff * R;
	}
	else
	{
		int diff = center.x - p3.x;
		c3.x = center.x - diff * R;
	}

	if (p3.y > center.y)
	{
		int diff = p3.y - center.y;
		c3.y = center.y + diff * R;
	}
	else
	{
		int diff = center.y - p3.y;
		c3.y = center.y - diff * R;
	}

	//Validation:
	if (c1.y < UI.ToolBarHeight || c1.y > UI.height - UI.StatusBarHeight || c1.x < UI.MenuActionWidth)
		return false;
	if (c2.y < UI.ToolBarHeight || c2.y > UI.height - UI.StatusBarHeight || c2.x < UI.MenuActionWidth)
		return false;
	if (c3.y < UI.ToolBarHeight || c3.y > UI.height - UI.StatusBarHeight || c3.x < UI.MenuActionWidth)
		return false;

	//Creating the Resized Object and Passing its ID:
	int oldID = ID;
	*this = CTriangle(c1, c2, c3, figGfxInfo);
	setID(oldID);
	return true;
}

void CTriangle::save(ofstream &OutFile)
{
	string info = storeType(figType) + " " + to_string(ID) + " " + p1.data() + " " + p2.data() + " " + p3.data() + " " + figGfxInfo.data();
	OutFile << endl << info;
}

void CTriangle::load(ifstream &InFile)
{
	Point P_1, P_2, P_3;
	GfxInfo TriGfxInfo;
	InFile >> ID;
	P_1.read(InFile);
	P_2.read(InFile);
	P_3.read(InFile);
	TriGfxInfo.read(InFile);
	*this = CTriangle(P_1, P_2, P_3, TriGfxInfo);
}

void CTriangle::printInfo(Output * pOut)
{
	string s = "ID: " + to_string(ID) + "    Points: (" + to_string(p1.x) + ", " + to_string(p1.y) + "), (" +
		to_string(p2.x) + ", " + to_string(p2.y) + "), (" + to_string(p3.x) + ", " + to_string(p3.y) + ") ";
	pOut->printMessage(s);
}
