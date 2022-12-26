#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter File Name :");

	//Read the file name to Load graph from
	FileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	pManager->ClearAll();

	//Create and Open file
	ifstream InputFile;
	InputFile.open(FileName, ios::in);
	if (!InputFile.is_open())
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Couldn't open file...");
		return;
	}
	string str;
	InputFile >> str;

	// Takes current draw and fill colors
	UI.DrawColor = ApplicationManager::StringToColor(str);
	InputFile >> str;
	UI.FillColor = ApplicationManager::StringToColor(str);

	int n, id;

	// Takes number of figures
	InputFile >> n;

	// Create New figure and loop through all figures in the file 
	// To read its parameters then load it
	CFigure* NewFig = NULL;
	for (int i = 0; i < n; i++)
	{
		InputFile >> str;
		InputFile >> id;
		if (str == "CIRCLE")
			NewFig = new CCircle(id);
		else if (str == "HEXAGON")
			NewFig = new CHexagon(id);
		else if (str == "RECT")
			NewFig = new CRectangle(id);
		else if (str == "SQUARE")
			NewFig = new CSquare(id);
		else
			NewFig = new CTriangle(id);

		NewFig->Load(InputFile);

		pManager->AddFigure(NewFig);
	}

	InputFile.close();
}

void LoadAction::LoadDrawModeList()
{
	// Clear All Figers Before Loading
	pManager->ClearFigList();


	string LoadDrawFileName = "DrawModeFigList.txt";
	//Create and Open file
	ifstream InputFile;
	InputFile.open(LoadDrawFileName, ios::in);
	if (!InputFile.is_open())
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Couldn't Load Draw Mode Shapes...");
		return;
	}
	string str;
	InputFile >> str;

	// Takes current draw and fill colors
	UI.DrawColor = ApplicationManager::StringToColor(str);
	InputFile >> str;
	UI.FillColor = ApplicationManager::StringToColor(str);

	int n, id;

	// Takes number of figures
	InputFile >> n;

	// Create New figure and loop through all figures in the file 
	// To read its parameters then load it
	CFigure* NewFig = NULL;
	for (int i = 0; i < n; i++)
	{
		InputFile >> str;
		InputFile >> id;
		if (str == "CIRCLE")
			NewFig = new CCircle(id);
		else if (str == "HEXAGON")
			NewFig = new CHexagon(id);
		else if (str == "RECT")
			NewFig = new CRectangle(id);
		else if (str == "SQUARE")
			NewFig = new CSquare(id);
		else
			NewFig = new CTriangle(id);

		NewFig->Load(InputFile);

		pManager->AddFigure(NewFig);
	}

	InputFile.close();
}
