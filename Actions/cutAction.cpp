#include "cutAction.h"


cutAction::cutAction(ApplicationManager * pApp) :Action(pApp)
{}

void cutAction::readActionParameters()
{

	Output* pOut = pManager->getOutput();
	pOut->printMessage("Cut, Selected Figure cut to Clipboard");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_Cut_Selected.jpg", ITM_CUT);

	//if there was a previous cut we return it to its initial color
	if (pManager->getLastCut()!= nullptr) 
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
	}

	pManager->setLastCut(pManager->getSelectedFigure());
	if (pManager->getSelectedFigure() != nullptr)
	{
		pManager->setLastDrawClr(pManager->getSelectedFigure()->getDrawColor());
		pManager->setLastFillClr(pManager->getSelectedFigure()->getFillColor());
	}

	cut = pManager->getSelectedFigure();
}

void cutAction::execute() 
{

	readActionParameters();
	Output* pOut = pManager->getOutput();

	if (cut == nullptr)
	{
		pOut->printMessage("Please Select a Figure to cut");
		return;
	}

	cut->setCut(true);
	pManager->setClipboard(cut);
	pManager->getSelectedFigure()->changeDrawColor(GREY);
	if(pManager->getSelectedFigure()->isFilled())
		pManager->getSelectedFigure()->changeFillColor(GREY);	
	else 
	{
		pManager->getSelectedFigure()->setSelected(false);
	}
}

cutAction::~cutAction()
{}
