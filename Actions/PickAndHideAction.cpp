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

	pManager->UpdateInterface();

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

	string Pick = "Pick ";

	if (ShapeOrColor == 'S')
		Pick += PickShape;
	if (ShapeOrColor == 'C')
		Pick += PickColor;
	if (ShapeOrColor == 'B')
		Pick += ( PickColor + " " + PickShape );

	pOut->PrintMessage(Pick);

	CFigure* UserPick;
	SelectFigureAction* Select = new SelectFigureAction(pManager);
	DeleteFigureAction* Delete = new DeleteFigureAction(pManager);

	do
	{
		UserPick = Select->SelectForPlay();
		if (UserPick == NULL)
			continue;
		if (UserPick->IsThisType(PickShape, PickColor, ShapeOrColor))
		{
			CorrectCnt++;
			Delete->DeleteForPlay(UserPick);
			pManager->UpdateInterface();
		}
		else
			IncorrectCnt++;

		PrintScore();

	} while (!(pManager->Stop(PickShape, PickColor, ShapeOrColor)));

	PrintScore("Well Done!   You Have Got   ");

}

void PickAndHideAction::PrintScore(string start) const
{
	Output* Out = pManager->GetOutput();
	string score = start + "Correct Picks: " + to_string(CorrectCnt);
	score += "  Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}