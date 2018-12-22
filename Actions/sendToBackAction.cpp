#include "sendToBackAction.h"


sendToBackAction::sendToBackAction(ApplicationManager *pApp) :Action(pApp)
{}

void sendToBackAction::ReadActionParameters()
{
	currentFigure = pManager->getSelectedFigure();
}
void sendToBackAction::Execute()
{

	ReadActionParameters();

	Output* pOut = pManager->GetOutput();

	pOut->CreateDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_send_to_back_Selected.jpg", ITM_SEND_TO_BACK);

	if (currentFigure == NULL)
		pOut->PrintMessage("Please Select a Figure first");
	else
		pManager->sendToBack(currentFigure);

}
