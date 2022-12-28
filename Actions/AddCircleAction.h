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
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Action of undo (make the figure again)
	virtual void RedoAct();
};

#endif