#include "DeleteFigureAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = NULL;
}

void DeleteFigureAction::ReadActionParameters()
{}

void DeleteFigureAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return;
	}

	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

	//Make the figure not highlighted
	SelectedFig->SetSelected(false);

	//Add the figure to a list to get access to it when we undo
	pManager->AddToDeletedFigures(SelectedFig);
}

void DeleteFigureAction::play()
{
	// Change The Tool Bar
	UI.InterfaceMode = MODE_DRAW;

	Output* pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	//Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return;
	}

	//Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

	//Delete the dynamically allocated figure from the memory
	delete SelectedFig;
}

void DeleteFigureAction::UndoAct()
{
	pManager->AddFigure(SelectedFig);
}
