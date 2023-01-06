#ifndef ADD_FIGURE_ACTION_H
#define ADD_FIGURE_ACTION_H

#include "Action.h"

//Add Figure Action class
class AddFigureAction : public Action
{
public:
	AddFigureAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	//Draw Shapes Tool Bar
	virtual bool Execute(bool ReadActionParams = true);

};

#endif