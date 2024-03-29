#include "DeleteFigureAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{
	SelectedFig = NULL;
	IsRecorded = false;
}

void DeleteFigureAction::ReadActionParameters()
{
}

bool DeleteFigureAction::Execute(bool ReadActionParams)
{

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

	Output* pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	// Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return true;
	}

	// Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

	// Make the figure not highlighted
	SelectedFig->SetSelected(false);

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

void DeleteFigureAction::DeleteForPlay(CFigure* Fig) //it is needed for play mode, because I don't need much of Execute() 
{
	// Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(Fig);

	// Delete the dynamically allocated figure from the memory
	delete Fig;
}
void DeleteFigureAction::UndoAct()
{
	if (SelectedFig != NULL)
		pManager->AddFigure(SelectedFig);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("A Failed Deleting attempt was made");
		return; // In case we added anything else in the future after this condition
	}
}

void DeleteFigureAction::RedoAct()
{
	if (SelectedFig != NULL)
		pManager->DeleteFigure(SelectedFig);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("A Failed Undo attempt was made");
		return;
	}
}

bool DeleteFigureAction::IsActionRecorded()
{
	return IsRecorded;
}
