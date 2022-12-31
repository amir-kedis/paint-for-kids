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

bool PlayRecordingAction::Execute(bool ReadActionParams)
{
	// check if we can record
	ReadActionParameters();

	// prepare output to print msgs to user
	Output* pOut = pManager->GetOutput();

	if (CanPlayRecord)
	{
		pOut->PrintMessage("Playing has started (:");

		// save the fig list first then delete all
		SaveAction saveDraw(pManager);
		saveDraw.SaveDrawModeList();

		// clean app vars
		pManager->ClearFigList();
		pManager->ClearUndoRedoList();
		bool recordingStat = pManager->GetRecordingStatus();
		pManager->SetRecordingStatus(false);

		// play recording
		pManager->PlayRecording();

		// ending msg
		pOut->PrintMessage("Playing has Ended (:");
		Sleep(1000);

		// restore recording state
		pManager->SetRecordingStatus(recordingStat);

		// when you return the toolbar should be on draw mode
		UI.InterfaceMode = MODE_DRAW;

		// Load Draw Mode After Recirding
		LoadAction loadDraw(pManager);
		loadDraw.LoadDrawModeList();
	}


	return true; // By default every action should be deleted
}
