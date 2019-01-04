#include "PasteAction.h"


PasteAction::PasteAction(ApplicationManager * pApp) :Action(pApp)
{}

void PasteAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();

	pOut->printMessage("Paste, Pasting Figure from Clipboard");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_Paste_Selected.jpg", ITM_PASTE);

	if (pManager->getClipboard() == nullptr)
	{
		pOut->printMessage("Copy or Cut first then try again");
		return;
	}
	toPaste = pManager->getClipboard();
	pOut->printMessage("Enter the center point for the figure to be pasted");

}

void PasteAction::execute()
{
	Output* pOut = pManager->getOutput();
	readActionParameters();

	if (pManager->getClipboard() == nullptr)
		return;

	if (dynamic_cast<CEllipse*>(toPaste))
	{
		// Validating the New Position:
		CEllipse* testEllipse = dynamic_cast<CEllipse*>(toPaste);
		Point Center;
		validateEllipse(Center, testEllipse);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled
		int a = testEllipse->getHorizontal();
		int b = testEllipse->getVertical();

		if (toPaste->isCut())
		{
			toPasteGfxInfo.drawColor = pManager->getLastDrawClr();
			toPasteGfxInfo.fillColor = pManager->getLastFillClr();
			pManager->deleteFigure(toPaste);
			pManager->setClipboard(nullptr);
			pManager->setLastCut(nullptr);
		}

		else
		{
			toPasteGfxInfo.drawColor = toPaste->getDrawColor();
			toPasteGfxInfo.fillColor = toPaste->getFillColor();
		}

		Point P1 = Center + Point(a, b);		//Bottom Right Corner
		Point P2 = Center + Point(-a, -b);	//Upper Left Corner
		
		// Recreating the object with its New Position:
		CEllipse* ellipse = new CEllipse(P1, P2, toPasteGfxInfo);
		pManager->addFigure(ellipse);
		pManager->setClipboard(ellipse);
	}

	else if (dynamic_cast<CRhombus*>(toPaste))
	{
		// Validating the New Position:
		CRhombus* testRhombus = dynamic_cast<CRhombus*>(toPaste);
		Point Center;
		validateRhombus(Center, testRhombus);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled
		int a = testRhombus->getHorizontal();
		int b = testRhombus->getVertical();

		if (toPaste->isCut())
		{
			toPasteGfxInfo.drawColor = pManager->getLastDrawClr();
			toPasteGfxInfo.fillColor = pManager->getLastFillClr();
			pManager->deleteFigure(toPaste);
			pManager->setClipboard(nullptr);
			pManager->setLastCut(nullptr);
		}

		else
		{
			toPasteGfxInfo.drawColor = toPaste->getDrawColor();
			toPasteGfxInfo.fillColor = toPaste->getFillColor();
		}
		
		// Recreating the object with its New Position:
		CRhombus* rhombus = new CRhombus(Center, toPasteGfxInfo, a, b);
		pManager->addFigure(rhombus);
		pManager->setClipboard(rhombus);
	}

	else if (dynamic_cast<CTriangle*>(toPaste))
	{

		CTriangle* tri = dynamic_cast<CTriangle*>(toPaste);
		Point Pa, Pb, Pc;
		validateTriangle(Pa, Pb, Pc, tri);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled

		if (toPaste->isCut())
		{
			toPasteGfxInfo.drawColor = pManager->getLastDrawClr();
			toPasteGfxInfo.fillColor = pManager->getLastFillClr();
			pManager->deleteFigure(toPaste);
			pManager->setClipboard(nullptr);
			pManager->setLastCut(nullptr);
		}

		else
		{
			toPasteGfxInfo.drawColor = toPaste->getDrawColor();
			toPasteGfxInfo.fillColor = toPaste->getFillColor();
		}

		pOut->drawTriangle(Pa, Pb, Pc, toPasteGfxInfo, false);
		//Create a triangle with the center from the user
		CTriangle *Tr = new CTriangle(Pa, Pb, Pc, toPasteGfxInfo);
		//Add the triangle to the list of figures
		pManager->addFigure(Tr);
		pManager->setClipboard(Tr);
	}

	else if (dynamic_cast<CRectangle*>(toPaste))
	{

		CRectangle* Rec = dynamic_cast<CRectangle*>(toPaste);
		Point Pa, Pb;
		validateRectangle(Pa, Pb, Rec);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled

		if (toPaste->isCut())
		{
			toPasteGfxInfo.drawColor = pManager->getLastDrawClr();
			toPasteGfxInfo.fillColor = pManager->getLastFillClr();
			pManager->deleteFigure(toPaste);
			pManager->setClipboard(nullptr);
			pManager->setLastCut(nullptr);
		}

		else
		{
			toPasteGfxInfo.drawColor = toPaste->getDrawColor();
			toPasteGfxInfo.fillColor = toPaste->getFillColor();
		}

		pOut->drawRectangle(Pa, Pb, toPasteGfxInfo, false);
		//Create a rectangle with the center from the user
		CRectangle *Rect = new CRectangle(Pa, Pb, toPasteGfxInfo);
		//Add the rectangle to the list of figures
		pManager->addFigure(Rect);
		pManager->setClipboard(Rect);
	}

	else if (dynamic_cast<CLine*>(toPaste))
	{

		CLine* line = dynamic_cast<CLine*>(toPaste);
		Point Pa, Pb;
		validateLine(Pa, Pb, line);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled

		if (toPaste->isCut())
		{
			toPasteGfxInfo.drawColor = pManager->getLastDrawClr();
			toPasteGfxInfo.fillColor = pManager->getLastFillClr();
			pManager->deleteFigure(toPaste);
			pManager->setClipboard(nullptr);
			pManager->setLastCut(nullptr);
		}

		else
		{
			toPasteGfxInfo.drawColor = toPaste->getDrawColor();
			toPasteGfxInfo.fillColor = toPaste->getFillColor();
		}

		pOut->drawLine(Pa, Pb, toPasteGfxInfo, false);
		//Create a Line with the center from the user
		CLine *Line = new CLine(Pa, Pb, toPasteGfxInfo);
		//Add the Line to the list of figures
		pManager->addFigure(Line);
		pManager->setClipboard(Line);

	}
}

void PasteAction::validateTriangle(Point& Pa, Point& Pb, Point& Pc, CTriangle* Tri) {
	Input* pIn = pManager->getInput();
	Output* pOut = pManager->getOutput();

	Point Center1, Center2;
	Center1.x = (Tri->getP1().x + Tri->getP2().x + Tri->getP3().x) / 3;
	Center1.y = (Tri->getP1().y + Tri->getP2().y + Tri->getP3().y) / 3;
	while (true)
	{
		pIn->getPointClicked(Center2.x, Center2.y);
		int deltaX = Center2.x - Center1.x;
		int deltaY = Center2.y - Center1.y;
		Pa.x = Tri->getP1().x + deltaX;
		Pa.y = Tri->getP1().y + deltaY;
		Pb.x = Tri->getP2().x + deltaX;
		Pb.y = Tri->getP2().y + deltaY;
		Pc.x = Tri->getP3().x + deltaX;
		Pc.y = Tri->getP3().y + deltaY;
		if (Pa.y < UI.ToolBarHeight || Pa.y > UI.height - UI.StatusBarHeight || Pa.x < UI.MenuActionWidth ||
			Pb.y < UI.ToolBarHeight || Pb.y > UI.height - UI.StatusBarHeight || Pb.x < UI.MenuActionWidth ||
			Pc.y < UI.ToolBarHeight || Pc.y > UI.height - UI.StatusBarHeight || Pc.x < UI.MenuActionWidth)
		{
			pOut->printMessage("Please Select a Valid Point");
		}
		else break;
	}
}

void PasteAction::validateEllipse(Point &P, CEllipse *ellipse)
{
	Input* pIn = pManager->getInput();
	Output* pOut = pManager->getOutput();
	int a = ellipse->getHorizontal();
	int b = ellipse->getVertical();
	while (true)
	{
		pIn->getPointClicked(P.x, P.y);
		if (P.y - b < UI.ToolBarHeight || P.y + b > UI.height - UI.StatusBarHeight || P.x - a < UI.MenuActionWidth)
			pOut->printMessage("Please Select a Valid Point");
		else break;
	}
}

void PasteAction::validateRhombus(Point &P, CRhombus *rhombus)
{
	Input* pIn = pManager->getInput();
	Output* pOut = pManager->getOutput();
	int a = rhombus->getHorizontal();
	int b = rhombus->getVertical();
	while (true)
	{
		pIn->getPointClicked(P.x, P.y);
		if (P.y - b < UI.ToolBarHeight || P.y + b > UI.height - UI.StatusBarHeight || P.x - a < UI.MenuActionWidth)
			pOut->printMessage("Please Select a Valid Point");
		else break;
	}
}

void PasteAction::validateRectangle(Point& Pa, Point& Pb, CRectangle* Rec)
{
	Input* pIn = pManager->getInput();
	Output* pOut = pManager->getOutput();

	Point center1, center2;
	center1.x = (Rec->getP1().x + Rec->getP2().x) / 2;
	center1.y = (Rec->getP1().y + Rec->getP2().y) / 2;
	while (true)
	{
		pIn->getPointClicked(center2.x, center2.y);
		int deltaX = center2.x - center1.x;
		int deltaY = center2.y - center1.y;
		Pa.x = Rec->getP1().x + deltaX;
		Pa.y = Rec->getP1().y + deltaY;
		Pb.x = Rec->getP2().x + deltaX;
		Pb.y = Rec->getP2().y + deltaY;

		if (Pa.y < UI.ToolBarHeight || Pa.y > UI.height - UI.StatusBarHeight || Pa.x < UI.MenuActionWidth ||
			Pb.y < UI.ToolBarHeight || Pb.y > UI.height - UI.StatusBarHeight || Pb.x < UI.MenuActionWidth)
		{
			pOut->printMessage("Please Select a Valid Point");
		}
		else break;
	}
}

void PasteAction::validateLine(Point& Pa, Point& Pb, CLine* Line)
{
	Input* pIn = pManager->getInput();
	Output* pOut = pManager->getOutput();

	Point center1, center2;
	center1.x = (Line->getP1().x + Line->getP2().x) / 2;
	center1.y = (Line->getP1().y + Line->getP2().y) / 2;
	while (true)
	{
		pIn->getPointClicked(center2.x, center2.y);
		int deltaX = center2.x - center1.x;
		int deltaY = center2.y - center1.y;
		Pa.x = Line->getP1().x + deltaX;
		Pa.y = Line->getP1().y + deltaY;
		Pb.x = Line->getP2().x + deltaX;
		Pb.y = Line->getP2().y + deltaY;
		if (Pa.y < UI.ToolBarHeight || Pa.y > UI.height - UI.StatusBarHeight || Pa.x < UI.MenuActionWidth ||
			Pb.y < UI.ToolBarHeight || Pb.y > UI.height - UI.StatusBarHeight || Pb.x < UI.MenuActionWidth)
		{
			pOut->printMessage("Please Select a Valid Point");
		}
		else break;
	}
}

