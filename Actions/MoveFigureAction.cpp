#include "MoveFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
}

void MoveFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at any Point to Move the figure to it");

	//Read the center of the new figure
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->ClearStatusBar();
}

void MoveFigureAction::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	//Get a Pointer to the Selected Figure
	SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return;
	}

	//Get the Center of the shape before moving it
	PreviousCenter = SelectedFig->GetCenter();

	//Read the new Center from the user
	ReadActionParameters();

	//Call MoveFigure function to move the selected figure
	pManager->MoveFigure(SelectedFig, Center);

	SelectedFig->SetSelected(false);
}

void MoveFigureAction::play()
{
	// Change The Tool Bar
	UI.InterfaceMode = MODE_DRAW;
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	//Get a Pointer to the Selected Figure
	CFigure* SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return;
	}

	//Call MoveFigure function to move the selected figure
	pManager->MoveFigure(SelectedFig, Center);

	SelectedFig->SetSelected(false);
}

void MoveFigureAction::UndoAct()
{
	if (SelectedFig != NULL)
		pManager->MoveFigure(SelectedFig, PreviousCenter);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("A Failed Moving attempt was made");
		return; //In case we added anything else in the future after this condition
	}
}

void MoveFigureAction::RedoAct()
{
	pManager->MoveFigure(SelectedFig, Center);
}
