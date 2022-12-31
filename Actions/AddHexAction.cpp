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


	HexGfxInfo.isFilled = UI.IsFilled;
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

bool AddHexAction::Execute(bool ReadActionParams)
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\hexagon.wav"), NULL, SND_ASYNC);
	}

	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

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
}

void AddHexAction::RedoAct()
{
	pManager->AddFigure(SelectedFig);
}
