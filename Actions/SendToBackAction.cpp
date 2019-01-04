#include "SendToBackAction.h"


SendToBackAction::SendToBackAction(ApplicationManager *pApp) :Action(pApp)
{}

void SendToBackAction::readActionParameters()
{
	currentFigure = pManager->getSelectedFigure();
}
void SendToBackAction::execute()
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
