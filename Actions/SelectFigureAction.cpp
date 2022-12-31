#include "SelectFigureAction.h"

SelectFigureAction::SelectFigureAction(ApplicationManager* pApp)
	:Action(pApp)
{
	// initailize class figure info with info provided by user
	SelectPoint = Point();
}

void SelectFigureAction::ReadActionParameters()
{
	// get input and output classes pointer from application manger
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Get Point From User
	pOut->PrintMessage("Please Select a Figure");
	pIn->GetPointClicked(SelectPoint.x, SelectPoint.y);

	// Validate that the point is in The drawing area
	while (SelectPoint.y < UI.StatusBarHeight || SelectPoint.y >(UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("Please Choose A valid Point: (Click on The Drawing Area)");
		pIn->GetPointClicked(SelectPoint.x, SelectPoint.y);
	}

	// clear the statusbar after correctly having a point
	pOut->ClearStatusBar();
}

bool SelectFigureAction::Execute(bool ReadActionParams)
{
	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
	else
	{
		// Change The Tool Bar
		UI.InterfaceMode = MODE_DRAW;
	}

	Output* pOut = pManager->GetOutput();

	CFigure* ClickedFigure = pManager->GetFigure(SelectPoint.x, SelectPoint.y);

	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\select.wav"), NULL, SND_ASYNC);
	}

	// If Clicked in No Figure
	if (ClickedFigure == NULL)
	{
		pOut->PrintMessage("No Figure To Be Selected");
		return true;
	}

	// If The Figure was Selected Unselect it and if it wasn't reverse
	if (!ClickedFigure->IsSelected())
	{
		ClickedFigure->SetSelected(true);
		pManager->SetSelectedFig(ClickedFigure);
		ClickedFigure->PrintInfo(pOut);
	}
	else
	{
		ClickedFigure->SetSelected(false);
		pManager->SetSelectedFig(NULL);
	}
	pManager->UnselectAll(ClickedFigure);

	bool shouldBeDeleted = true; // this action should be deleted by default

	// add action to record and record list if recording list
	if (pManager->GetRecordingStatus())
	{
		shouldBeDeleted = !pManager->AddActionToRecording(this);
	}

	return shouldBeDeleted; // By default every action should be deleted
}

CFigure* SelectFigureAction::SelectForPlay() //it is needed for play mode, because I don't need much of Execute() 
{
	Input* pIn = pManager->GetInput();

	// Get Point From User
	pIn->GetPointClicked(SelectPoint.x, SelectPoint.y);

	CFigure* ClickedFigure = pManager->GetFigure(SelectPoint.x, SelectPoint.y);

	return ClickedFigure;

}
