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
	pOut->PrintMessage("Do You want to keep graph to play with ? (Y/N) : ");
	string ans;
	do
	{
		ans = pIn->GetSrting(pOut);
	}
	while (ans != "Y" || ans != "N");

	if (ans == "Y")
	{
		Load->LoadDrawModeList();
	}
	else
	{
		Load->Execute();
	}

	WelcomePrint();

	CFigure* UserPick;
	SelectFigureAction* Select = new SelectFigureAction(pManager);
	UserPick = Select->SelectForPlay();

	while(true)
	{
		if (IsShape(UserPick))
		{
			CorrectCnt++;
			DeleteFigureAction* Delete = new DeleteFigureAction(pManager);
			Delete->DeleteForPlay(UserPick);
			pManager->UpdateInterface();
		}
		else
			IncorrectCnt++;

		PrintScore();

		UserPick = Select->SelectForPlay();
	}

}

// checks if the figure is one needed
bool PickByShapeAction::IsShape(CFigure* UserPick) const
{
	if (UserPick == NULL)
		return false;
	if (typeid(*Shape) == typeid(*UserPick))
		return true;
	return false;
}

void PickByShapeAction::PrintScore() const
{
	Output* Out = pManager->GetOutput();
	string score = "Correct Picks: " + to_string(CorrectCnt) + '\t';
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}

void PickByShapeAction::WelcomePrint() const
{
	Output* Out = pManager->GetOutput();

	string welcome = "Pick ";

	string shape;
	for (int i = 7; i < strlen(typeid(*Shape).name()); i++)
		shape += (typeid(*Shape).name())[i];

	welcome += shape += 's';
	Out->PrintMessage(welcome);
}