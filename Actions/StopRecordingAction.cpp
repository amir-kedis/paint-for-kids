#include "StopRecordingAction.h"


StopRecordingAction::StopRecordingAction(ApplicationManager* pApp)
	:Action(pApp)
{
	CanStopRecord = false;
}

void StopRecordingAction::ReadActionParameters()
{
	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	// get current status of recording
	bool IsRecording = pManager->GetRecordingStatus();

	// there is no recording to stop
	if (!IsRecording)
	{
		pOut->PrintMessage("there is no recording to stop...");
		return;
	}

	CanStopRecord = true;
}

bool StopRecordingAction::Execute(bool ReadActionParams)
{
	// check if we can stop record
	ReadActionParameters();

	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	if (CanStopRecord)
	{
		pManager->SetRecordingStatus(false);
		pOut->PrintMessage("Recording has Stoped");
	}


	return true; // By default every action should be deleted
}
