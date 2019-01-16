#include "AddLineAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CLine.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


AddLineAction::AddLineAction(ApplicationManager *pApp) :Action(pApp)
{}

void AddLineAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Line_Selected.jpg", ITM_LINE);
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/Line.wav"), nullptr, SND_ASYNC);
	pOut->printMessage("New Line: Click at first point");

	//Read 1st point and store in point p1
	pOut->getValidPoint(P1);

	pOut->printMessage("New Line: Click at second point");
	//Read 2nd point and store in point p2
	pOut->getValidPoint(P2);
	
	//get drawing color and pen width from the interface
	LineGfxInfo.drawColor = pOut->getCurrentDrawColor();
	LineGfxInfo.borderSize = pOut->getCurrentBorderSize();
	LineGfxInfo.isFilled = false;

	pOut->clearStatusBar();
}




 void AddLineAction::execute()
 {//This action needs to read some parameters first
	 readActionParameters();

	 //Create a Line with the parameters read from the user
	 CLine *L = new CLine(P1, P2, LineGfxInfo);

	 //Add the Line to the list of figures
	 pManager->addFigure(L);
 }