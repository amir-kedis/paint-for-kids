#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H

#include "Action.h"

class MoveFigureAction : public Action
{
	Point Center;
	Point PreviousCenter;
	CFigure* SelectedFig;
public:
	MoveFigureAction(ApplicationManager* pApp);

	//Reads the new center of the figure
	virtual void ReadActionParameters();

	//Call MoveFigure function in ApplicationManager
	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	virtual void UndoAct();
};

#endif