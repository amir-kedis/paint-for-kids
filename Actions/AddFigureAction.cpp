#include "AddFigureAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddFigureAction::AddFigureAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddFigureAction::ReadActionParameters()
{}

void AddFigureAction::Execute(bool ReadActionParams)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	//Draw Shapes Tool Bar
	pOut->CreateShapesToolBar();

}

void AddFigureAction::play()
{
	Execute();
}


