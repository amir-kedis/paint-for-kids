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
void PickByBothAction::Execute(bool ReadActionParams)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Action* Load = new LoadAction(pManager);

	//Ask the user to draw something in case the graph is empty
	if (pManager->IsFigListEmpty())
	{
		pOut->PrintMessage("There is No Graph to Play With, Go Draw or Load a graph and Comeback :) ");
		return;
	}
	else
	{
		Load->Execute(false);
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