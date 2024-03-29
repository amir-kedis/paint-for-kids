#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
	IsRecorded = false;
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the Center Point");

	//Read the Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	SquareGfxInfo.isFilled = UI.IsFilled;
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

bool AddSquareAction::Execute(bool ReadActionParams)
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\square.wav"), NULL, SND_ASYNC);
	}

	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a square with the parameters read from the user
	CSquare* R = new CSquare(P1, SquareGfxInfo);
	SelectedFig = R;

	//Add the square to the list of figures
	pManager->AddFigure(R);

	bool shouldBeDeleted = false; // this action shoudn't be deleted by default

	// add action to record and record list if recording list
	if (pManager->GetRecordingStatus())
	{
		IsRecorded = pManager->AddActionToRecording(this);
	}
	pManager->AddToURActionList(this);
	pManager->SetUndoCount(0);            //reset the UndoCount

	return shouldBeDeleted; // By default every action should be deleted
}

void AddSquareAction::UndoAct()
{
	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);
}

void AddSquareAction::RedoAct()
{
	pManager->AddFigure(SelectedFig);
}

bool AddSquareAction::IsActionRecorded()
{
	return IsRecorded;
}