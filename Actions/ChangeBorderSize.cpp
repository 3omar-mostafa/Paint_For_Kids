#include "ChangeBorderSize.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ChangeBorderSize::ChangeBorderSize(ApplicationManager* pApp) : Action(pApp)
{}

void ChangeBorderSize::readActionParameters() {}

//Execute the action
void ChangeBorderSize::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Change Figure's Border Width, Click Anywhere");

	pOut->drawBorderSizeMenu();
	pIn->getPointClicked(P.x, P.y);

	int currentBorderSize, selectedBorderSize;
	if (pManager->getSelectedFigure() != nullptr)
	{
		currentBorderSize = pManager->getSelectedFigure()->getBorderSize();
		selectedBorderSize = pOut->selectBorderSize(P);
		pManager->getSelectedFigure()->changeBorderSize(selectedBorderSize);
	}
	else
	{
		selectedBorderSize = currentBorderSize = UI.BorderSize;
		if(pOut->selectBorderSize(P) != -1) // i.e. the user selected one of the choices
			selectedBorderSize = pOut->selectBorderSize(P);
	}

	if (selectedBorderSize != currentBorderSize) {
		SaveAction save(pManager);
		save.saveForUndo();
	}
}
