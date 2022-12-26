#include "PickByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Actions\SelectFigureAction.h"
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
	Output* Out = pManager->GetOutput();
	string shape = to_string(typeid(*Shape).name);
	Out->PrintMessage("Pick ");
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
	string score = "Correct Picks: " + to_string(CorrectCnt) + '\t';
	score += " Incorrect Picks: " + to_string(IncorrectCnt);
	Out->PrintMessage(score);
}