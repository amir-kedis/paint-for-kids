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
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute(bool ReadActionParams = true);

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Undo Action (make the figure again)
	virtual void RedoAct();
};

#endif