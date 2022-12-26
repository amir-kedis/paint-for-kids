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
#include <fstream>

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
	CFigure* UserPick = SelectFigureAction::SelectForPlay();

}
