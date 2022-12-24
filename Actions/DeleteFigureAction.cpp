#include "DeleteFigureAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp):Action(pApp)
{}

void DeleteFigureAction::ReadActionParameters()
{}

void DeleteFigureAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	CFigure* SelectedFig = pManager->GetSelectedFig();

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
