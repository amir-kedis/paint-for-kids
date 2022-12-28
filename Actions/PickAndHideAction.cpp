#include "PickAndHideAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "SelectFigureAction.h"
#include "LoadAction.h"
#include "DeleteFigureAction.h"
#include <string>

PickAndHideAction::PickAndHideAction(ApplicationManager* pApp, char SOrC) : Action(pApp)
{
	ShapeOrColor = SOrC;
	CorrectCnt = 0;
	IncorrectCnt = 0;
}

//Reads parameters required for action to execute
void PickAndHideAction::ReadActionParameters()
{
}

//Execute action
void PickAndHideAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	LoadAction* Load = new LoadAction(pManager);

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

	// Update Interface to make all figures show up
	pManager->UpdateInterface();
	
	// Get a random shape or color or both according to the case
	int prev = -1;
	if (ShapeOrColor == 'B')
	{
		PickShape = pManager->GetRandomFig('S', prev);
		PickColor = pManager->GetRandomFig('C', prev);
	}
	else if (ShapeOrColor == 'S')
		PickShape = pManager->GetRandomFig(ShapeOrColor, prev);
	else
		PickColor = pManager->GetRandomFig(ShapeOrColor, prev);

	// print the thing that the user should pick to let him know
	string Pick = "Pick ";
	if (ShapeOrColor == 'S')
		Pick += PickShape + 's';
	if (ShapeOrColor == 'C' || ShapeOrColor == 'B')
	{
		Pick += PickColor[0];
		for(int i = 1; i < PickColor.size(); i++)
		Pick += tolower(PickColor[i]);
	}
	if (ShapeOrColor == 'B')
		Pick += " " + PickShape + 's';

	pOut->PrintMessage(Pick);

	CFigure* UserPick;
	SelectFigureAction* Select = new SelectFigureAction(pManager);
	DeleteFigureAction* Delete = new DeleteFigureAction(pManager);

	//loop till all figures that should be picked are already picked
	do
	{
		UserPick = Select->SelectForPlay(); // Get picked figure
		if (UserPick == NULL)
			continue;
		if (UserPick->IsThisType(PickShape, PickColor, ShapeOrColor))
		{
			CorrectCnt++;
			Delete->DeleteForPlay(UserPick); // If it is the required figure, so I need to delete it
			pManager->UpdateInterface();	// Update Interface to make the deleted figure disappear
		}
		else
			IncorrectCnt++;

		PrintScore();

	} while (!(pManager->Stop(PickShape, PickColor, ShapeOrColor)));

	PrintScore("Well Done!   You Have Got ");

}

void PickAndHideAction::PrintScore(string start) const
{
	Output* Out = pManager->GetOutput();
	string score = start + "Correct Picks: " + to_string(CorrectCnt);
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}