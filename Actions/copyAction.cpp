#include "copyAction.h"


copyAction::copyAction(ApplicationManager * pApp) :Action(pApp)
{}

void copyAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Copy, Selected Figure copied to Clipboard");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_copy_Selected.jpg", ITM_COPY);

	if (pManager->getClipboard() != NULL) {

		if (pManager->getClipboard()->IsCut())
		{
			if (!pManager->getLastCut()->isFilled()) {
				pManager->getLastCut()->ChngDrawClr(pManager->getLastDrawClr());
			}
			else {
				pManager->getLastCut()->ChngDrawClr(pManager->getLastDrawClr());
				pManager->getLastCut()->ChngFillClr(pManager->getLastFillClr());
			}
			pManager->setLastCut(NULL);
			pManager->getClipboard()->SetCut(false);
		}
	}

	copied = pManager->getSelectedFigure();
}

void copyAction::Execute(){
	ReadActionParameters();
	
	pManager->setClipboard(copied);
}

copyAction::~copyAction()
{
}
