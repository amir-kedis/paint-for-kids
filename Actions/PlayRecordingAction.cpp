#include "PlayRecordingAction.h"


PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp)
	:Action(pApp)
{
	CanPlayRecord = false;
}

void PlayRecordingAction::ReadActionParameters()
{
	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	// No Record To Play
	if (pManager->IsRecordActionListEmpty())
	{
		pOut->PrintMessage("No Recording To Play...");
		return;
	}

	CanPlayRecord = true;
}

void PlayRecordingAction::Execute()
{
	// check if we can record
	ReadActionParameters();

	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	if (CanPlayRecord)
	{
		pOut->PrintMessage("Playing has started (:");
		pManager->ClearAll();
		pManager->PlayRecording();
	}
}
