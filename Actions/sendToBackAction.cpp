#include "sendToBackAction.h"


sendToBackAction::sendToBackAction(ApplicationManager *pApp) :Action(pApp)
{}

void sendToBackAction::readActionParameters()
{
	currentFigure = pManager->getSelectedFigure();
}
void sendToBackAction::execute()
{

	readActionParameters();

	Output* pOut = pManager->getOutput();

	pOut->createDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_send_to_back_Selected.jpg", ITM_SEND_TO_BACK);

	if (currentFigure == nullptr)
		pOut->printMessage("Please Select a Figure first");
	else
		pManager->sendToBack(currentFigure);

}
