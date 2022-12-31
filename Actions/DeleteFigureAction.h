#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

class DeleteFigureAction : public Action
{
private:
	CFigure* SelectedFig;

public:
	DeleteFigureAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool ReadActionParams = true);

	virtual void DeleteForPlay(CFigure* Fig);
	// Used to Undo the Delete Action
	virtual void UndoAct();

	// Redo the Undo Action (delete the figure again)
	virtual void RedoAct();
};

#endif