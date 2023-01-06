#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter File Name :");

	//Read the file name to save graph into it
	FileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

bool SaveAction::Execute(bool ReadActionParams)
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create and Open file
	ofstream OutputFile;
	OutputFile.open(FileName, ios::out);

	//Check if file is open correctly
	if (!OutputFile.is_open())
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Couldn't open file...");
		return true;
	}

	//Save all figures
	pManager->SaveAll(OutputFile);

	OutputFile.close();

	return true; // By default every action should be deleted
}

void SaveAction::SaveDrawModeList()
{

	string SaveDrawFileName = "DrawModeFigList.txt";

	//Create and Open file
	ofstream OutputFile;
	OutputFile.open(SaveDrawFileName, ios::out);

	//Check if file is open correctly
	if (!OutputFile.is_open())
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Couldn't Save Draw Mode List");
		return;
	}

	//Save all figures
	pManager->SaveAll(OutputFile);

	OutputFile.close();
}
