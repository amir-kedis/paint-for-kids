#include "PickByShapeAction.h"
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
#include <fstream>
#include <typeinfo>

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp) : Action(pApp)
{
	Shape = pManager->GetRandomFig();
	CorrectCnt = 0;
	IncorrectCnt = 0;
}

//Reads parameters required for action to execute
void PickByShapeAction::ReadActionParameters()
{

}

//Execute action
void PickByShapeAction::Execute()
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
	{
		Load->LoadDrawModeList();
	}
	else
	{
		Load->Execute();
	}

	pOut->PrintMessage("Pick " + Shape);

	CFigure* UserPick;
	SelectFigureAction* Select = new SelectFigureAction(pManager);
	DeleteFigureAction* Delete = new DeleteFigureAction(pManager);

	do
	{
		UserPick = Select->SelectForPlay();
		if (UserPick == NULL)
			continue;
		if (UserPick->IsThisType(Shape))
		{
			CorrectCnt++;
			Delete->DeleteForPlay(UserPick);
			pManager->UpdateInterface();
		}
		else
			IncorrectCnt++;

		PrintScore();

	} while (true);

}

void PickByShapeAction::PrintScore() const
{
	Output* Out = pManager->GetOutput();
	string score = "Correct Picks: " + to_string(CorrectCnt) + '\t';
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}