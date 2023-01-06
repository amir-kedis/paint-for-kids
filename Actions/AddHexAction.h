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
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual bool Execute(bool ReadActionParams = true);

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Undo Action (make the figure again)
	virtual void RedoAct();

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

#endif
