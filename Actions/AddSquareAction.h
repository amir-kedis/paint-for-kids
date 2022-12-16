#ifndef ADD_SEQUARE_ACTION_H
#define ADD_SEQUARE_ACTION_H

#include "Action.h"

class AddSquareAction: public Action
{
private:
	Point P1; //Square Center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif