#include "PickByBothAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectFigureAction.h"
#include "LoadAction.h"
#include "DeleteFigureAction.h"
#include <string>

PickByBothAction::PickByBothAction(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCnt = 0;
	IncorrectCnt = 0;
}

//Reads parameters required for action to execute
void PickByBothAction::ReadActionParameters()
{
}

//Execute action
void PickByBothAction::Execute(bool ReadActionParams = true)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	LoadAction* Load = new LoadAction(pManager);

	//Ask the user to directly load from a file in case that he didn't draw any graph in the drawing area
	if (pManager->IsFigListEmpty())
		Load->Execute();
	else
	{
		// Ask if the user want to load file or stay on same previous graph
		pOut->PrintMessage("Do You want to keep graph to play with ? (y/n) : ");
		string ans;
		do
		{
			ans = pIn->GetSrting(pOut);
		} while (ans != "y" && ans != "n");

		if (ans == "y")
			Load->LoadDrawModeList();
		if (ans == "n")
			Load->Execute();
	}

	// Update Interface to make all figures show up
	pManager->UpdateInterface();

	// Get a random shape with a specific color from Figure List
	int prev = -1; // This is needed for getting the color of the same picked shape
	PickShape = pManager->GetRandomFig('S', prev);
	PickColor = pManager->GetRandomFig('C', prev);

	// print the Color and sahpe that the user should pick to let him know (while making color lower case)
	string Pick = "Pick ";
	Pick += PickColor[0];
	for (int i = 1; i < PickColor.size(); i++)
		Pick += tolower(PickColor[i]);
	Pick += " " + PickShape + 's';
	pOut->PrintMessage(Pick);

	CFigure* UserPick;
	SelectFigureAction* Select = new SelectFigureAction(pManager);
	DeleteFigureAction* Delete = new DeleteFigureAction(pManager);

	//loop till all figures that should be picked are already picked
	do
	{
		UserPick = Select->SelectForPlay(); // Get picked figure

		if (UserPick == NULL) // in case the user clicked on an empty area
			continue;

		//To check Shape and Color to know if it is the needed one or not
		if (UserPick->IsThisType(PickShape, 'S') && UserPick->IsThisType(PickColor, 'C'))
		{
			CorrectCnt++;
			Delete->DeleteForPlay(UserPick); // If it is the required figure, so I need to delete it
			pManager->UpdateInterface();	// Update Interface to make the deleted figure disappear
		}
		else
			IncorrectCnt++;

		PrintScore();

	} while (!(pManager->Stop('B', PickShape, PickColor)));

	PrintScore("Well Done!   You Have Got ");

}

void PickByBothAction::PrintScore(string start) const
{
	Output* Out = pManager->GetOutput();
	string score = start + "Correct Picks: " + to_string(CorrectCnt);
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}