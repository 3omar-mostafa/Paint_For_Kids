#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager * pApp) : Action(pApp)
{}

void ChangeDrawColor::readActionParameters() {}

//Execute the action
void ChangeDrawColor::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Change Figure's Drawing Color, Click Anywhere");

	pOut->drawDrawingColorMenu();
	pIn->getPointClicked(P.x, P.y);
			
	if (pManager->getSelectedFigure() != nullptr)
		pManager->getSelectedFigure()->changeDrawColor(pOut->selectDrawColor(P));
	else
		pOut->selectDrawColor(P);
	
	pOut->deleteColorMenu();
}
