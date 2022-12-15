#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"

class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3;   //Triangle Corners
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};

#endif