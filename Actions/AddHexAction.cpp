#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center of the hexagon");

	//Read the center and store it in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(P1, HexGfxInfo);
	SelectedFig = R;

	//Add the hexagon to the list of figures
	pManager->AddFigure(R);
}

void AddHexAction::play()
{
	// Change The Tool Bar
	UI.InterfaceMode = MODE_DRAW;

	//Create a hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(P1, HexGfxInfo);
	SelectedFig = R;

	//Add the hexagon to the list of figures
	pManager->AddFigure(R);
}

void AddHexAction::UndoAct()
{
	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

	//Delete the dynamically allocated figure from the memory
	delete SelectedFig;
}
