#include "RedoAct.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAct::RedoAct(ApplicationManager* pApp) :Action(pApp)
{
	IsRecorded = false;
}

void RedoAct::ReadActionParameters()
{
}

bool RedoAct::Execute(bool ReadActionParams)
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();

	//a bool variable to check if the redo action is done or not
	bool IsDone = false;

	//Check if the Redo action is still in URActionList Or not 
	if (pManager->GetURActionCount() < 5 && pManager->GetUndoCount() > 0) 
	{
		IsDone = pManager->RedoAction();   //Make the Redo action which return a boolean value (true if done, false if not)
		pManager->SetUndoCount(pManager->GetUndoCount() - 1);    //Decrement the UndoCount by 1
	}
	// To check if a redo action can be done or not
	if (!IsDone)
		pOut->PrintMessage("Cannot Redo");

	bool shouldBeDeleted = true; // this action should be deleted by default

	// add action to record and record list if recording list
	if (pManager->GetRecordingStatus())
	{
		shouldBeDeleted = !pManager->AddActionToRecording(this);
		IsRecorded = !shouldBeDeleted;
	}

	return shouldBeDeleted; // By default every action should be deleted
}

bool RedoAct::IsActionRecorded()
{
	return IsRecorded;
}