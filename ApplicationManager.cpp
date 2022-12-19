#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddFigureAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\SaveAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case ADD_FIGURE:
			pAct = new AddFigureAction(this);   //Create a new Object from AddFigureAction class
			break;
	
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			pOut->CreateDrawToolBar();      //Return to the Draw Tool Bar after choosing Rectangle icon
			break;
		
		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_HEX:
			pAct = new AddHexAction(this);
			pOut->CreateDrawToolBar();
			break;

		case SAVE:
			pAct = new SaveAction(this);
			pOut->CreateDrawToolBar();
			break;


		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Save all figures to a file
void ApplicationManager::SaveAll(ofstream &OutFile)
{
	OutFile << CFigure::ColorToString(pOut->getCrntDrawColor()) << '\t'
		<< CFigure::ColorToString(pOut->getCrntFillColor()) << '\n' << FigCount << '\n';
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile, i+1);
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
