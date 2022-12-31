#include "MoveFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
}

void MoveFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at any Point to Move the figure to it");

	//Read the center of the new figure
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->ClearStatusBar();
}

bool MoveFigureAction::Execute(bool ReadActionParams)
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	//Get a Pointer to the Selected Figure
	SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return true;
	}

	//Get the Center of the shape before moving it
	PreviousCenter = SelectedFig->GetCenter();

	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
	else
	{
		UI.InterfaceMode = MODE_DRAW;
	}

	//Call MoveFigure function to move the selected figure
	pManager->MoveFigure(SelectedFig, Center);

	SelectedFig->SetSelected(false);

	bool shouldBeDeleted = false; // this action shoudn't be deleted by default

	// add action to record and record list if recording list
	if (pManager->GetRecordingStatus())
	{
		pManager->AddActionToRecording(this);
	}
	pManager->AddToURActionList(this);

	return shouldBeDeleted; // By default every action should be deleted
}


void MoveFigureAction::UndoAct()
{
	if (SelectedFig != NULL)
		pManager->MoveFigure(SelectedFig, PreviousCenter);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("A Failed Moving attempt was made");
		return; //In case we added anything else in the future after this condition
	}
}

void MoveFigureAction::RedoAct()
{
	pManager->MoveFigure(SelectedFig, Center);
}
