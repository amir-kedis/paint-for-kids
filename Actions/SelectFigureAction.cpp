#include "SelectFigureAction.h"

SelectFigureAction::SelectFigureAction(ApplicationManager* pApp, GfxInfo* SelectedFigureGfx)
	:Action(pApp)
{
	// initailize class figure info with info provided by user
	SelectedFigureInformation = SelectedFigureGfx;
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
}

void SelectFigureAction::Execute()
{
}
