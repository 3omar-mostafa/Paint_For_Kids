#include "AddLineAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CLine.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddLineAction::AddLineAction(ApplicationManager *pApp) :Action(pApp)
{
}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");
	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");
	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	
	//get drawing color and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	

	pOut->ClearStatusBar();
}




 void AddLineAction::Execute()
 {//This action needs to read some parameters first
	 ReadActionParameters();

	 //Create a Line with the parameters read from the user
	 CLine *L = new CLine(P1, P2, LineGfxInfo);

	 //Add the Line to the list of figures
	 pManager->AddFigure(L);
 }