#include "copyAction.h"


copyAction::copyAction(ApplicationManager * pApp) :Action(pApp)
{}

void copyAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	pOut->printMessage("Copy, Selected Figure copied to Clipboard");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_copy_Selected.jpg", ITM_COPY);

	if (pManager->getClipboard() != nullptr)
	{

		if (pManager->getClipboard()->isCut())
		{
			if (!pManager->getLastCut()->isFilled()) 
			{
				pManager->getLastCut()->changeDrawColor(pManager->getLastDrawClr());
			}
			else 
			{
				pManager->getLastCut()->changeDrawColor(pManager->getLastDrawClr());
				pManager->getLastCut()->changeFillColor(pManager->getLastFillClr());
			}
			pManager->setLastCut(nullptr);
			pManager->getClipboard()->setCut(false);
		}
	}

	copied = pManager->getSelectedFigure();
}

void copyAction::execute()
{

	readActionParameters();
	Output* pOut = pManager->getOutput();

	if (copied == nullptr)
	{
		pOut->printMessage("Please Select a Figure to copy");
		return;
	}

	pManager->setClipboard(copied);
}