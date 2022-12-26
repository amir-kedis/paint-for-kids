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
}

//Reads parameters required for action to execute
void PickByShapeAction::ReadActionParameters()
{

}

//Execute action
void PickByShapeAction::Execute()
{
	CFigure* UserPick;
	UserPick = SelectFigureAction::SelectForPlay();
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

		UserPick = SelectFigureAction::SelectForPlay();
	}

}

// checks if the figure is one needed
bool PickByShapeAction::IsShape(CFigure* UserPick) const
{
	if (UserPick == NULL)
		return false;
	if (typeid(Shape) == typeid(UserPick))
		return true;
	return false;
}

void PickByShapeAction::PrintScore() const
{
	Output* Out = pManager->GetOutput();
	Out->PrintMessage("Correct Picks: ");
	Out->PrintMessage(to_string(CorrectCnt));
	Out->PrintMessage("		Incorrect Picks: ");
	Out->PrintMessage(to_string(IncorrectCnt));
}