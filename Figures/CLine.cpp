#include "CLine.h"

CLine::CLine(Point P_1, Point P_2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = P_1;
	P2 = P_2;
	ID = LINE;
}

Point CLine::getP1(){
	return P1;
}
Point CLine::getP2(){
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
		if (getTriangularArea(x,y)/ lengthOFLine <= 3) {
			return true;
		}
	}
	return false;
}

string CLine::getInfo() {
	string s;
	s = "ID :" + to_string(ID) + " Points : ( " + to_string(P1.x) + " , " + to_string(P1.y) + " ) , ( " + to_string(P2.x) + " , " + to_string(P2.y) + " ) , " ;
	s += "Length : " + to_string( sqrt((P2.x - P1.x)*(P2.x - P1.x) + (P2.y - P1.y)*(P2.y - P1.y) ) );
	
	string sshort = to_string(ID) + " " + P1.Data() + " " + P2.Data();
	return sshort;
}

void CLine::Save(ofstream &OutFile)
{
	string Info = getInfo();
	OutFile << Info << endl;
}

void CLine::Load(ifstream &InFile)
{
	Point Pi, Pf;
	//InFile >> P1 >> P2;
	//InFile >> LineGfxInfo;
	Pi.Read(InFile);
	Pf.Read(InFile);
	*this = CLine(Pi, Pf, FigGfxInfo);
}