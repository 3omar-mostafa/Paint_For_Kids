#include "cutAction.h"


cutAction::cutAction(ApplicationManager * pApp) :Action(pApp)
{}

void cutAction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();

	//if there was a previous cut we return it to its initial color
		if (pManager->getLastCut()!= NULL) 
		{
			if (!pManager->getLastCut()->isFilled()) {
				pManager->getLastCut()->ChngDrawClr(pManager->getLastDrawClr());
			}
			else {
				pManager->getLastCut()->ChngDrawClr(pManager->getLastDrawClr());
				pManager->getLastCut()->ChngFillClr(pManager->getLastFillClr());
			}
		}

		pManager->setLastCut(pManager->getSelectedFigure());
		pManager->setLastDrawClr(pManager->getSelectedFigure()->getDrawColor());
		pManager->setLastFillClr(pManager->getSelectedFigure()->getFillColor());
	
	cut = pManager->getSelectedFigure();
}

void cutAction::Execute() {

	ReadActionParameters();
	cut->SetCut(true);
	pManager->setClipboard(cut);
	pManager->getSelectedFigure()->ChngDrawClr(GREY);
	if(pManager->getSelectedFigure()->isFilled())
		pManager->getSelectedFigure()->ChngFillClr(GREY);	
	else {
		pManager->getSelectedFigure()->SetSelected(false);
	}
}

cutAction::~cutAction()
{
}
