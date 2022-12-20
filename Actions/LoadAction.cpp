#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter File Name :");

	//Read the file name to save graph into it
	FileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create and Open file
	ifstream InputFile;
	InputFile.open(FileName, ios::in);
	if (!InputFile.is_open())
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Couldn't open file...");
		return;
	}

	InputFile.close();
}
