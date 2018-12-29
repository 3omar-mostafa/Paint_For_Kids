#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

changeFillColor::changeFillColor(ApplicationManager * pApp) :Action(pApp)
{}

void changeFillColor::readActionParameters() {}

//Execute the action
void changeFillColor::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Change Figure's Fill Color, Click Anywhere");

	pOut->drawFillColorMenu();

	pIn->getPointClicked(P.x, P.y);
		
	if (pManager->getSelectedFigure() != nullptr) 
	{
		color c = pOut->selectFillColor(P);
		if (c != NOFILL)
			pManager->getSelectedFigure()->changeFillColor(c);
		else
			pManager->getSelectedFigure()->setFilled(false);
	}
	else
		pOut->selectFillColor(P);
	
	pOut->deleteColorMenu();
}
