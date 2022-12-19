#include "SelectFigureAction.h"

SelectFigureAction::SelectFigureAction(ApplicationManager* pApp)
	:Action(pApp)
{
	// initailize class figure info with info provided by user
	//SelectedFigureInformation = SelectedFigureGfx;
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

void SelectFigureAction::Execute()
{
	// get Point From User
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	CFigure* ClickedFigure = pManager->GetFigure(SelectPoint.x, SelectPoint.x);

	// If Clicked in No Figure
	if (ClickedFigure == NULL)
	{
		pOut->PrintMessage("No Figure To Be Selected");
		return;
	}

	if (!ClickedFigure->IsSelected())
	{
		ClickedFigure->SetSelected(true);
		pManager->SetSelectedFig(ClickedFigure);
	}
	else
	{
		ClickedFigure->SetSelected(false);
		pManager->SetSelectedFig(NULL);
	}
}
