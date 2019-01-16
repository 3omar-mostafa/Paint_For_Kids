#include "CopyAction.h"


CopyAction::CopyAction(ApplicationManager * pApp) :Action(pApp)
{}

void CopyAction::readActionParameters()
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
				pManager->getLastCut()->changeDrawColor(pManager->getLastDrawColor());
			}
			else 
			{
				pManager->getLastCut()->changeDrawColor(pManager->getLastDrawColor());
				pManager->getLastCut()->changeFillColor(pManager->getLastFillColor());
			}
			pManager->setLastCut(nullptr);
			pManager->getClipboard()->setCut(false);
		}
	}

	copied = pManager->getSelectedFigure();
}

void CopyAction::execute()
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