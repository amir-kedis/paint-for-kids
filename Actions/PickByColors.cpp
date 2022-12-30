#include "PickByColors.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectFigureAction.h"
#include "LoadAction.h"
#include "DeleteFigureAction.h"
#include <string>

PickByColors::PickByColors(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCnt = 0;
	IncorrectCnt = 0;
}

//Reads parameters required for action to execute
void PickByColors::ReadActionParameters()
{
}

//Execute action
void PickByColors::Execute()
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

	// Get a random Color from Figure List
	int prev = -1; // Because the function needs a second
	Pick = pManager->GetRandomFig('C', prev);

	// print the Color that the user should pick to let him know
	pOut->PrintMessage("Pick " + Pick);

	CFigure* UserPick;
	SelectFigureAction* Select = new SelectFigureAction(pManager);
	DeleteFigureAction* Delete = new DeleteFigureAction(pManager);

	//loop till all figures that should be picked are already picked
	do
	{
		UserPick = Select->SelectForPlay(); // Get picked figure
		if (UserPick == NULL)
			continue;
		if (UserPick->IsThisType(Pick, 'C')) //To check Color in order to know if it is the needed one or not
		{
			CorrectCnt++;
			Delete->DeleteForPlay(UserPick); // If it is the required figure, so I need to delete it
			pManager->UpdateInterface();	// Update Interface to make the deleted figure disappear
		}
		else
			IncorrectCnt++;

		PrintScore();

	} while (!(pManager->Stop('C', Pick)));

	PrintScore("Well Done!   You Have Got ");

}

void PickByColors::PrintScore(string start) const
{
	Output* Out = pManager->GetOutput();
	string score = start + "Correct Picks: " + to_string(CorrectCnt);
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}