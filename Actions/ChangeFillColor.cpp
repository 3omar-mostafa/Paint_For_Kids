#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColor::ChangeFillColor(ApplicationManager * pApp) :Action(pApp)
{}

void ChangeFillColor::ReadActionParameters() {}

//Execute the action
void ChangeFillColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Change Figure's Fill Color, Click Anywhere");

	pOut->drawFillColorMenu();

	pIn->GetPointClicked(P.x, P.y);
		
	if (pManager->getSelectedFigure() != NULL) {
		color c = pOut->selectFillColor(P);
		if (c != NOFILL)
			pManager->getSelectedFigure()->ChngFillClr(c);
		else
			pManager->getSelectedFigure()->setFilled(false);
	}else
		pOut->selectFillColor(P);
	
	pOut->deleteColorMenu();
}
