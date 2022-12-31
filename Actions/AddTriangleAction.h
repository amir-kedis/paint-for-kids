#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"
#include "..\Figures\CTriangle.h"

class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3;   //Triangle Corners
	GfxInfo TriangleGfxInfo;
	CTriangle* SelectedFig;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual bool Execute(bool ReadActionParams = true);

	//Undo the Created Figure (delete it)
	virtual void UndoAct();

	//Redo the Undo Action (make the figure again)
	virtual void RedoAct();
};

#endif