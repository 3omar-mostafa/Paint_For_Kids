#include "CutAction.h"


CutAction::CutAction(ApplicationManager * pApp) :Action(pApp)
{}

void CutAction::readActionParameters()
{

	Output* pOut = pManager->getOutput();
	pOut->printMessage("Cut, Selected Figure cut to Clipboard");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_Cut_Selected.jpg", ITM_CUT);

	//if there was a previous cut we return it to its initial color
	if (pManager->getLastCut()!= nullptr) 
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
	}

	pManager->setLastCut(pManager->getSelectedFigure());
	if (pManager->getSelectedFigure() != nullptr)
	{
		pManager->setLastDrawColor(pManager->getSelectedFigure()->getDrawColor());
		pManager->setLastFillColor(pManager->getSelectedFigure()->getFillColor());
		pManager->setLastBorderSize(pManager->getSelectedFigure()->getBorderSize());
	}

	cut = pManager->getSelectedFigure();
}

void CutAction::execute() 
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

CutAction::~CutAction()
{}
