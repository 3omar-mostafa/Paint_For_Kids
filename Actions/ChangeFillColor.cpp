#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChangeFillColor::ChangeFillColor(ApplicationManager * pApp) :Action(pApp)
{}

void ChangeFillColor::readActionParameters() {}

//Execute the action
void ChangeFillColor::execute()
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
	
}
