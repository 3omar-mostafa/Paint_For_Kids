#include "bringToFrontAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

bringToFrontAction::bringToFrontAction(ApplicationManager *pApp) :Action(pApp)
{}

void bringToFrontAction::ReadActionParameters()
{
	currentFigure = pManager->getSelectedFigure();
}
void bringToFrontAction::Execute()
{

	ReadActionParameters();

	Output* pOut = pManager->GetOutput();

	pOut->CreateDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_bring_to_front_Selected.jpg", ITM_BRING_TO_FRONT);

	if (currentFigure == NULL)
		pOut->PrintMessage("Please Select a Figure first");

	else
		pManager->bringToFront(currentFigure);

}
