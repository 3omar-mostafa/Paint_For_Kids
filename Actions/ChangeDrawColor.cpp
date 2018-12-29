#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

changeDrawColor::changeDrawColor(ApplicationManager * pApp) : Action(pApp)
{}

void changeDrawColor::readActionParameters() {}

//Execute the action
void changeDrawColor::execute()
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
