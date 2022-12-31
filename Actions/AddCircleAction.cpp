#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the Center of the Circle");

	//Read the Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at Any Point on the Circle");

	//Read Second Point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = UI.IsFilled;
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

bool AddCircleAction::Execute(bool ReadActionParams)
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\circle.wav"), NULL, SND_ASYNC);
	}


	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a circle with the parameters read from the user
	CCircle* R = new CCircle(P1, P2, CircleGfxInfo);
	SelectedFig = R;

	//Add the circle to the list of figures
	pManager->AddFigure(R);
}

void AddCircleAction::UndoAct()
{
	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

}

void AddCircleAction::RedoAct()
{
	pManager->AddFigure(SelectedFig);
}
