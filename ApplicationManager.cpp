#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddFigureAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions/SelectFigureAction.h"

// Constructor
ApplicationManager::ApplicationManager()
{
	// Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	SelectedFig = NULL;

	// Create an array of figure pointers and set them to NULL
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case SELECT:
		pAct = new SelectFigureAction(this);
		break;
	case ADD_FIGURE:
		pAct = new AddFigureAction(this); // Create a new Object from AddFigureAction class
		break;

	case DRAW_RECT:
		pAct = new AddRectAction(this);
		pOut->CreateDrawToolBar(); // Return to the Draw Tool Bar after choosing Rectangle icon
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

	case LOAD:
		pAct = new LoadAction(this);
		pOut->CreateDrawToolBar();
		break;

	case EXIT:
		/// create ExitAction here

		break;

	case STATUS: // a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////
// Save all figures to a file
void ApplicationManager::SaveAll(ofstream &OutFile)
{
	OutFile << CFigure::ColorToString(pOut->getCrntDrawColor()) << '\t'
			<< CFigure::ColorToString(pOut->getCrntFillColor()) << '\n'
			<< FigCount << '\n';
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile, i + 1);
}
////////////////////////////////////////////////////////////////////////////////////
// Convert string into Color class
color ApplicationManager::StringToColor(string str)
{
	if (str == "BLACK")
		return BLACK;
	if (str == "YELLOW")
		return YELLOW;
	if (str == "ORANGE")
		return ORANGE;
	if (str == "RED")
		return RED;
	if (str == "GREEN")
		return GREEN;
	if (str == "BLUE")
		return BLUE;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

// Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure *pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	Point CheckPoint;
	CheckPoint.x = x;
	CheckPoint.y = y;

	/// Decided to loop from the end to get the latest shaped in the list
	for (int i = FigCount - 1; i >= 0; i--)
	{
		// if point is in fig return fig and exit
		if (FigList[i]->IsInFigure(CheckPoint))
		{
			return FigList[i];
		}
	}

	// if didn't find point return NULL
	return NULL;
}
void ApplicationManager::SetSelectedFig(CFigure *selcetFig)
{
	SelectedFig = selcetFig;
}
CFigure *ApplicationManager::GetSelectedFig() const
{
	return SelectedFig;
}
void ApplicationManager::UnselectAll(CFigure *CurrntFigure)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != CurrntFigure)
		{
			FigList[i]->SetSelected(false);
		}
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

// Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut); // Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
// Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
// Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
// Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}
