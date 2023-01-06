#include "PickByColorsAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectFigureAction.h"
#include "LoadAction.h"
#include "DeleteFigureAction.h"
#include <string>

PickByColorsAction::PickByColorsAction(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCnt = 0;
	IncorrectCnt = 0;
}

//Reads parameters required for action to execute
void PickByColorsAction::ReadActionParameters()
{
}

//Execute action
bool PickByColorsAction::Execute(bool ReadActionParams)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Action* Load = new LoadAction(pManager);

	//Ask the user to draw something in case the graph is empty
	if (pManager->IsFigListEmpty())
	{
		pOut->PrintMessage("There is No Graph to Play With, Go Draw or Load a graph and Comeback :) ");
		return true;
	}
	else
	{
		Load->Execute(false);
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

		if (UserPick == NULL) // in case the user clicked on an empty area
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

	return true; // By default every action should be deleted
}

void PickByColorsAction::PrintScore(string start) const
{
	Output* Out = pManager->GetOutput();
	string score = start + "Correct Picks: " + to_string(CorrectCnt);
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}