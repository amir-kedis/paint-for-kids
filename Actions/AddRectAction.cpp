#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
	IsRecorded = false;
}

void AddRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.IsFilled;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddRectAction::Execute(bool ReadActionParams)
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\rectangle.wav"), NULL, SND_ASYNC);
	}

	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a rectangle with the parameters read from the user
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);
	SelectedFig = R;

	//Add the rectangle to the list of figures
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

void AddRectAction::UndoAct()
{
	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);
}

void AddRectAction::RedoAct()
{
	pManager->AddFigure(SelectedFig);
}

bool AddRectAction::IsActionRecorded()
{
	return IsRecorded;
}
