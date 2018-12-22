#include "pasteAction.h"


pasteAction::pasteAction(ApplicationManager * pApp) :Action(pApp)
{}

void pasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Paste, Pasting Figure from Clipboard");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_Paste_Selected.jpg", ITM_PASTE);

	if (pManager->getClipboard() == NULL)
	{
		pOut->PrintMessage("Copy or Cut first then try again");
		return;
	}
	toPaste = pManager->getClipboard();
	pOut->PrintMessage("Enter the center point for the figure to be pasted");

}

void pasteAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (pManager->getClipboard() == NULL)
		return;

	if (dynamic_cast<CEllipse*>(toPaste))
	{
		CEllipse* Elps = dynamic_cast<CEllipse*>(toPaste);
		Point Center;
		ValidateEllipse(Center, Elps);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled
		int a = Elps->getHorizontal();
		int b = Elps->getVertical();

		if (toPaste->IsCut())
		{
			toPasteGfxInfo.DrawClr = pManager->getLastDrawClr();
			toPasteGfxInfo.FillClr = pManager->getLastFillClr();
			pManager->DeleteFigure(toPaste);
			pManager->setClipboard(NULL);
			pManager->setLastCut(NULL);
		}

		else
		{
			toPasteGfxInfo.DrawClr = toPaste->getDrawColor();
			toPasteGfxInfo.FillClr = toPaste->getFillColor();
		}

		Point P1, P2;
		P1 = Center + Point(a, b);
		P2 = Center + Point(-a, -b);
		Elps = new CEllipse(P1, P2, toPasteGfxInfo);
		pManager->AddFigure(Elps);
		pManager->setClipboard(Elps);
	}

	else if (dynamic_cast<CRhombus*>(toPaste))
	{
		CRhombus* Rhom = dynamic_cast<CRhombus*>(toPaste);
		Point Center;
		ValidateRhombus(Center, Rhom);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled
		int a = Rhom->getHorizontal();
		int b = Rhom->getVertical();

		if (toPaste->IsCut())
		{
			toPasteGfxInfo.DrawClr = pManager->getLastDrawClr();
			toPasteGfxInfo.FillClr = pManager->getLastFillClr();
			pManager->DeleteFigure(toPaste);
			pManager->setClipboard(NULL);
			pManager->setLastCut(NULL);
		}

		else
		{
			toPasteGfxInfo.DrawClr = toPaste->getDrawColor();
			toPasteGfxInfo.FillClr = toPaste->getFillColor();
		}
		
		Rhom = new CRhombus(Center, toPasteGfxInfo, a, b);
		pManager->AddFigure(Rhom);
		pManager->setClipboard(Rhom);
	}

	else if (dynamic_cast<CTriangle*>(toPaste))
	{

		CTriangle* tri = dynamic_cast<CTriangle*>(toPaste);
		Point Pa, Pb, Pc, Center1, Center2;
		ValidateTriangle(Pa, Pb, Pc, tri);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled

		if (toPaste->IsCut())
		{
			toPasteGfxInfo.DrawClr = pManager->getLastDrawClr();
			toPasteGfxInfo.FillClr = pManager->getLastFillClr();
			pManager->DeleteFigure(toPaste);
			pManager->setClipboard(NULL);
			pManager->setLastCut(NULL);
		}

		else
		{
			toPasteGfxInfo.DrawClr = toPaste->getDrawColor();
			toPasteGfxInfo.FillClr = toPaste->getFillColor();
		}

		pOut->DrawTriangle(Pa, Pb, Pc, toPasteGfxInfo, false);
		//Create a triangle with the center from the user
		CTriangle *Tr = new CTriangle(Pa, Pb, Pc, toPasteGfxInfo);
		//Add the triangle to the list of figures
		pManager->AddFigure(Tr);
		pManager->setClipboard(Tr);
	}

	else if (dynamic_cast<CRectangle*>(toPaste))
	{

		CRectangle* Rec = dynamic_cast<CRectangle*>(toPaste);
		Point Pa, Pb;
		ValidateRectangle(Pa, Pb, Rec);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled

		if (toPaste->IsCut())
		{
			toPasteGfxInfo.DrawClr = pManager->getLastDrawClr();
			toPasteGfxInfo.FillClr = pManager->getLastFillClr();
			pManager->DeleteFigure(toPaste);
			pManager->setClipboard(NULL);
			pManager->setLastCut(NULL);
		}

		else
		{
			toPasteGfxInfo.DrawClr = toPaste->getDrawColor();
			toPasteGfxInfo.FillClr = toPaste->getFillColor();
		}

		pOut->DrawRect(Pa, Pb, toPasteGfxInfo, false);
		//Create a rectangle with the center from the user
		CRectangle *Rect = new CRectangle(Pa, Pb, toPasteGfxInfo);
		//Add the rectangle to the list of figures
		pManager->AddFigure(Rect);
		pManager->setClipboard(Rect);
	}

	else if (dynamic_cast<CLine*>(toPaste))
	{

		CLine* line = dynamic_cast<CLine*>(toPaste);
		Point Pa, Pb;
		ValidateLine(Pa, Pb, line);
		toPasteGfxInfo.isFilled = toPaste->isFilled();	//default is filled

		if (toPaste->IsCut())
		{
			toPasteGfxInfo.DrawClr = pManager->getLastDrawClr();
			toPasteGfxInfo.FillClr = pManager->getLastFillClr();
			pManager->DeleteFigure(toPaste);
			pManager->setClipboard(NULL);
			pManager->setLastCut(NULL);
		}

		else
		{
			toPasteGfxInfo.DrawClr = toPaste->getDrawColor();
			toPasteGfxInfo.FillClr = toPaste->getFillColor();
		}

		pOut->DrawLine(Pa, Pb, toPasteGfxInfo, false);
		//Create a Line with the center from the user
		CLine *Line = new CLine(Pa, Pb, toPasteGfxInfo);
		//Add the Line to the list of figures
		pManager->AddFigure(Line);
		pManager->setClipboard(Line);

	}
}

void pasteAction::ValidateTriangle(Point& Pa, Point& Pb, Point& Pc, CTriangle* Tri) {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Point Center1, Center2;
	Center1.x = (Tri->getP1().x + Tri->getP2().x + Tri->getP3().x) / 3;
	Center1.y = (Tri->getP1().y + Tri->getP2().y + Tri->getP3().y) / 3;
	int deltaX, deltaY;
	while (true)
	{
		pIn->GetPointClicked(Center2.x, Center2.y);
		deltaX = Center2.x - Center1.x;
		deltaY = Center2.y - Center1.y;
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
			pOut->PrintMessage("Please Select a Valid Point");
		}
		else break;
	}
}

void pasteAction::ValidateEllipse(Point &P, CEllipse *Elps)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int a = Elps->getHorizontal();
	int b = Elps->getVertical();
	while (true)
	{
		pIn->GetPointClicked(P.x, P.y);
		if (P.y - b < UI.ToolBarHeight || P.y + b > UI.height - UI.StatusBarHeight || P.x - a < UI.MenuActionWidth)
			pOut->PrintMessage("Please Select a Valid Point");
		else break;
	}
}

void pasteAction::ValidateRhombus(Point &P, CRhombus *Rhom)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int a = Rhom->getHorizontal();
	int b = Rhom->getVertical();
	while (true)
	{
		pIn->GetPointClicked(P.x, P.y);
		if (P.y - b < UI.ToolBarHeight || P.y + b > UI.height - UI.StatusBarHeight || P.x - a < UI.MenuActionWidth)
			pOut->PrintMessage("Please Select a Valid Point");
		else break;
	}
}

void pasteAction::ValidateRectangle(Point& Pa, Point& Pb, CRectangle* Rec)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Point Center1, Center2;
	Center1.x = (Rec->getP1().x + Rec->getP2().x) / 2;
	Center1.y = (Rec->getP1().y + Rec->getP2().y) / 2;
	int deltaX, deltaY;
	while (true)
	{
		pIn->GetPointClicked(Center2.x, Center2.y);
		deltaX = Center2.x - Center1.x;
		deltaY = Center2.y - Center1.y;
		Pa.x = Rec->getP1().x + deltaX;
		Pa.y = Rec->getP1().y + deltaY;
		Pb.x = Rec->getP2().x + deltaX;
		Pb.y = Rec->getP2().y + deltaY;

		if (Pa.y < UI.ToolBarHeight || Pa.y > UI.height - UI.StatusBarHeight || Pa.x < UI.MenuActionWidth ||
			Pb.y < UI.ToolBarHeight || Pb.y > UI.height - UI.StatusBarHeight || Pb.x < UI.MenuActionWidth)
		{
			pOut->PrintMessage("Please Select a Valid Point");
		}
		else break;
	}
}

void pasteAction::ValidateLine(Point& Pa, Point& Pb, CLine* Line)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Point Center1, Center2;
	Center1.x = (Line->getP1().x + Line->getP2().x) / 2;
	Center1.y = (Line->getP1().y + Line->getP2().y) / 2;
	int deltaX, deltaY;
	while (true)
	{
		pIn->GetPointClicked(Center2.x, Center2.y);
		deltaX = Center2.x - Center1.x;
		deltaY = Center2.y - Center1.y;
		Pa.x = Line->getP1().x + deltaX;
		Pa.y = Line->getP1().y + deltaY;
		Pb.x = Line->getP2().x + deltaX;
		Pb.y = Line->getP2().y + deltaY;
		if (Pa.y < UI.ToolBarHeight || Pa.y > UI.height - UI.StatusBarHeight || Pa.x < UI.MenuActionWidth ||
			Pb.y < UI.ToolBarHeight || Pb.y > UI.height - UI.StatusBarHeight || Pb.x < UI.MenuActionWidth)
		{
			pOut->PrintMessage("Please Select a Valid Point");
		}
		else break;
	}
}

pasteAction::~pasteAction()
{}
