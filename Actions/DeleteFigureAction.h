#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H

#include "Action.h"

class DeleteFigureAction : public Action
{
private:
	CFigure* SelectedFig;
public:
	DeleteFigureAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	// Used to Undo the Delete Action
	virtual void UndoAct();
	
	//Redo the Undo Action (delete the figure again)
	virtual void RedoAct();
};

#endif