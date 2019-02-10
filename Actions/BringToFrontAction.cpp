#include "BringToFrontAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

BringToFrontAction::BringToFrontAction(ApplicationManager *pApp) :Action(pApp)
{}

void BringToFrontAction::readActionParameters()
{
	currentFigure = pManager->getSelectedFigure();
}
void BringToFrontAction::execute()
{

	readActionParameters();

	Output* pOut = pManager->getOutput();

	pOut->createDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_bring_to_front_Selected.jpg", ITM_BRING_TO_FRONT);

	if (currentFigure == nullptr)
		pOut->printMessage("Please Select a Figure first");

	else
		pManager->bringToFront(currentFigure);

	SaveAction save(pManager);
	save.saveForUndo();
}
