#include "UndoAct.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

UndoAct::UndoAct(ApplicationManager* pApp) :Action(pApp)
{}

void UndoAct::ReadActionParameters()
{
}

void UndoAct::Execute(bool ReadActionParams = true)
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();

	//Check if there are actions to Undo or not
	if (pManager->GetURActionCount() == 0)
	{
		pOut->PrintMessage("You Must do an action first to Undo");
		return;
	}

	pManager->UndoAction();
}
