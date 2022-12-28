#include "RedoAct.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

RedoAct::RedoAct(ApplicationManager* pApp):Action(pApp)
{
}

void RedoAct::ReadActionParameters()
{
}

void RedoAct::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	//a bool variable to check if the redo action is done or not
	bool IsDone = false;

	//Check if the Redo action is still in URActionList Or not 
	if (pManager->GetURActionCount() < 5)
		IsDone = pManager->RedoAction();   //Make the Redo action which return a boolean value (true if done, false if not)

	// To check if a redo action can be done or not
	if (!IsDone)
		pOut->PrintMessage("Cannot Redo");
}