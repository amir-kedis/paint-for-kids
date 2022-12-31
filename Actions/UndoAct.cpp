#include "UndoAct.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAct::UndoAct(ApplicationManager* pApp) :Action(pApp)
{}

void UndoAct::ReadActionParameters()
{
}

bool UndoAct::Execute(bool ReadActionParams)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();

	//Check if there are actions to Undo or not
	if (pManager->GetURActionCount() == 0)
	{
		pOut->PrintMessage("You Must do an action first to Undo");
		return true;
	}

	pManager->UndoAction();

	bool shouldBeDeleted = true; // this action should be deleted by default

	// add action to record and record list if recording list
	if (pManager->GetRecordingStatus())
	{
		shouldBeDeleted = !pManager->AddActionToRecording(this);
	}

	pManager->SetUndoCount(pManager->GetUndoCount() + 1);      //Increment the UndoCount by 1

	return shouldBeDeleted; // By default every action should be deleted
}
