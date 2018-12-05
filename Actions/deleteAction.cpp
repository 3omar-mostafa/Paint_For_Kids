#include "deleteAction.h"

deleteAction::deleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void deleteAction::ReadActionParameters(){
	deletedFigure = pManager->getSelectedFigure();
}
void deleteAction::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (deletedFigure == NULL)
		pOut->PrintMessage("Please Select a Figure to delete");
	else {
		int count = pManager->getFigureCount();
		FigList = pManager->getFigureArray();
		int i ;

		for ( i = 0; i < count; i++){
			if (FigList[i] == deletedFigure)
				break;
		}

		for ( i ; i < count -1 ; i++){
			FigList[i] = FigList[i+1];
		}
		pManager->setSelectedFigure(NULL);
		pManager->setFigureCount(--count);
		FigList[count] = NULL;
	}
}
