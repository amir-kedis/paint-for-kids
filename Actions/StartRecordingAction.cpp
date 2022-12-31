#include "StartRecordingAction.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp)
	:Action(pApp)
{
	CanRecord = false;
}

void StartRecordingAction::ReadActionParameters()
{
	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	// get current status of recording
	bool IsRecording = pManager->GetRecordingStatus();

	// Can't start two recording at once
	if (IsRecording)
	{
		pOut->PrintMessage("Can't start two recording at once...");
		return;
	}

	// can't start recording unless instart of app or if you clear all first
	if (!pManager->IsFigListEmpty())
	{
		pOut->PrintMessage("Can't start recording unless you clear all first..");
		return;
	}

	CanRecord = true;
}

bool StartRecordingAction::Execute(bool ReadActionParams)
{
	// check if we can record
	ReadActionParameters();

	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	if (CanRecord)
	{
		pManager->SetRecordingStatus(true);
		pOut->PrintMessage("Recording has started (:");
	}

	return true; // By default every action should be deleted
}
