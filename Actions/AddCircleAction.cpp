#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
	IsRecorded = false;
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

void AddCircleAction::UndoAct()
{
	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

}

void AddCircleAction::RedoAct()
{
	//Call AddFigure funct to add the figure again to the figure list
	pManager->AddFigure(SelectedFig);
}

bool AddCircleAction::IsActionRecorded()
{
	return IsRecorded;
}