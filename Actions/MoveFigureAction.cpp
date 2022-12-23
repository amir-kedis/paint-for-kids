#include "MoveFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp):Action(pApp)
{}

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
	//This action needs to read some parameters first
	ReadActionParameters();


}
