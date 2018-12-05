#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager * pApp) : Action(pApp)
{}

void ChangeDrawColor::ReadActionParameters() {}

//Execute the action
void ChangeDrawColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->drawDrawingColorMenu();
	pIn->GetPointClicked(P.x, P.y);
			
	if (pManager->getSelectedFigure() != NULL)
		pManager->getSelectedFigure()->ChngDrawClr(pOut->selectDrawColor(P));
	else
		pOut->selectDrawColor(P);
	
	pOut->deleteColorMenu();
}
