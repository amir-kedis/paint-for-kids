#ifndef ADD_SEQUARE_ACTION_H
#define ADD_SEQUARE_ACTION_H

#include "Action.h"
#include "..\Figures\CSquare.h"

class AddSquareAction : public Action
{
private:
	Point P1; //Square Center
	GfxInfo SquareGfxInfo;
	CSquare* SelectedFig;
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual bool Execute(bool ReadActionParams = true);

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Undo Action (make the figure again)
	virtual void RedoAct();

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

#endif