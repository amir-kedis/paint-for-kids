#ifndef ADD_Circle_ACTION_H
#define ADD_Circle_ACTION_H

#include "Action.h"
#include "..\Figures\CCircle.h"

class AddCircleAction : public Action
{
private:
	Point P1, P2;
	GfxInfo CircleGfxInfo;
	CCircle* SelectedFig;
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual bool Execute(bool ReadActionParams = true);

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Action of undo (make the figure again)
	virtual void RedoAct();

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

#endif