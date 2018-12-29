#include "bringToFrontAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

bringToFrontAction::bringToFrontAction(ApplicationManager *pApp) :Action(pApp)
{}

void bringToFrontAction::readActionParameters()
{
	currentFigure = pManager->getSelectedFigure();
}
void bringToFrontAction::execute()
{

	readActionParameters();

	Output* pOut = pManager->getOutput();

	pOut->createDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_bring_to_front_Selected.jpg", ITM_BRING_TO_FRONT);

	if (currentFigure == nullptr)
		pOut->printMessage("Please Select a Figure first");

	else
		pManager->bringToFront(currentFigure);

}
