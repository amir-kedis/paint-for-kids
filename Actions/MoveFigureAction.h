#ifndef MOVE_FIGURE_ACTION_H
#define MOVE_FIGURE_ACTION_H

#include "Action.h"

class MoveFigureAction : public Action
{
	Point Center;               //Current center of the figure
	Point PreviousCenter;       //Previous center of the figure
	CFigure* SelectedFig;       //Pointer to a the figure that will be moved
public:
	MoveFigureAction(ApplicationManager* pApp);

	//Reads the new center of the figure
	virtual void ReadActionParameters();

	//Call MoveFigure function in ApplicationManager
	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	//Used to Undo the Delete Action
	virtual void UndoAct();

	//Redo the Undo Action (delete the figure again)
	virtual void RedoAct();
};

#endif