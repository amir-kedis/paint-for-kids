#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"
#include "..\Figures\CHexagon.h"

class AddHexAction : public Action
{
private:
	Point P1; //Center of Hex
	GfxInfo HexGfxInfo;
	CHexagon* SelectedFig;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Undo Action (make the figure again)
	virtual void RedoAct();
};

#endif
