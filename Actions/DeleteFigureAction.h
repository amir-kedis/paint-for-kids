#ifndef DELETE_FIGURE_ACTION_H
#define DELETE_FIGURE_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

class DeleteFigureAction : public Action
{
private:
	CFigure* SelectedFig;
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	DeleteFigureAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool ReadActionParams = true);

	virtual void DeleteForPlay(CFigure* Fig);
	// Used to Undo the Delete Action
	virtual void UndoAct();

	// Redo the Undo Action (delete the figure again)
	virtual void RedoAct();

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

#endif