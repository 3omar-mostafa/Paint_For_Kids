#include "selectShapeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

selectShapeAction::selectShapeAction(ApplicationManager * pApp) :Action(pApp) 
{}


//TODO: Comment this properly 
void selectShapeAction::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select, Click anywhere");
	pOut->CreateDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_select_Selected.jpg", ITM_SELECT);

	int x, y;
	pIn->GetPointClicked(x, y);
	pManager->setLastSelected(pManager->getSelectedFigure());
	pManager->setSelectedFigure(pManager->GetFigure(x, y));
}

//TODO: Comment this properly 
void selectShapeAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	// if the figure was selected twice consecutively
	if (pManager->getLastSelected() == pManager->getSelectedFigure() && pManager->getSelectedFigure() != NULL) 
	{
		pManager->getSelectedFigure()->toggleSelection();
		if (pManager->getSelectedFigure()->IsSelected())
			// print its info it its last state was that it is selected
			pManager->getSelectedFigure()->PrintInfo(pOut);
		else
		{
			pManager->setLastSelected(NULL);
			pManager->setSelectedFigure(NULL);
		}
	}
	else 
	{
		// remove selection from last selected figure
		if (pManager->getLastSelected() != NULL) 
		{
			pManager->getLastSelected()->SetSelected(false);
			pManager->setLastSelected(NULL);
		}
		if (pManager->getSelectedFigure() != NULL) 
		{
			pManager->getSelectedFigure()->toggleSelection();

			// change draw color icon according to the selected figure color
			pOut->changeDrawColorIcon(pManager->getSelectedFigure()->getDrawColor());
			// change fill color icon according to the selected figure color and its fill state
			pOut->changeFillColorIcon(pManager->getSelectedFigure()->getFillColor(), pManager->getSelectedFigure()->isFilled());

			if ( ! pManager->getSelectedFigure()->IsSelected())
				pManager->getSelectedFigure()->SetSelected(NULL);
			else
				pManager->getSelectedFigure()->PrintInfo(pOut);
		}
	}
}