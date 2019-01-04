#include "SelectShapeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

SelectShapeAction::SelectShapeAction(ApplicationManager * pApp) :Action(pApp) 
{}


//TODO: Comment this properly 
void SelectShapeAction::readActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();

	pOut->printMessage("Select, Click anywhere");
	pOut->createDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_select_Selected.jpg", ITM_SELECT);

	int x, y;
	pIn->getPointClicked(x, y);
	pManager->setLastSelected(pManager->getSelectedFigure());
	pManager->setSelectedFigure(pManager->getFigure(x, y));
}

//TODO: Comment this properly 
void SelectShapeAction::execute() 
{
	Output* pOut = pManager->getOutput();
	readActionParameters();

	// if the figure was selected twice consecutively
	if (pManager->getLastSelected() == pManager->getSelectedFigure() && pManager->getSelectedFigure() != nullptr) 
	{
		pManager->getSelectedFigure()->toggleSelection();
		if (pManager->getSelectedFigure()->isSelected())
			// print its info it its last state was that it is selected
			pManager->getSelectedFigure()->printInfo(pOut);
		else
		{
			pManager->setLastSelected(nullptr);
			pManager->setSelectedFigure(nullptr);
		}
	}
	else 
	{
		// remove selection from last selected figure
		if (pManager->getLastSelected() != nullptr) 
		{
			pManager->getLastSelected()->setSelected(false);
			pManager->setLastSelected(nullptr);
		}
		if (pManager->getSelectedFigure() != nullptr) 
		{
			pManager->getSelectedFigure()->toggleSelection();

			// change draw color icon according to the selected figure color
			pOut->changeDrawColorIcon(pManager->getSelectedFigure()->getDrawColor());
			// change fill color icon according to the selected figure color and its fill state
			pOut->changeFillColorIcon(pManager->getSelectedFigure()->getFillColor(), pManager->getSelectedFigure()->isFilled());

			if ( ! pManager->getSelectedFigure()->isSelected())
				pManager->getSelectedFigure()->setSelected(false);
			else
				pManager->getSelectedFigure()->printInfo(pOut);
		}
	}
}