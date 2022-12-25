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
	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	//Undo the Created Figure (delete it)
	virtual void UndoAct();
};

#endif