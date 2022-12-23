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
#include "Actions\DeleteFigureAction.h"
#include "Actions/SwitchToPlayAction.h"
#include "Actions/SwitchToDrawAction.h"
#include "Actions/ChangeColorAction.h"

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
	Action* pAct = NULL;
	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case SELECT:
		pAct = new SelectFigureAction(this);
		break;

	case DELETE_FIGURE:
		pAct = new DeleteFigureAction(this);
		break;

	case ADD_FIGURE:
		pAct = new AddFigureAction(this); // Create a new Object from AddFigureAction class
		break;

	case DRAW_RECT:
		pAct = new AddRectAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case DRAW_HEX:
		pAct = new AddHexAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case SAVE:
		pAct = new SaveAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case LOAD:
		pAct = new LoadAction(this);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case TO_PLAY:
		pAct = new SwitchToPlayAction(this);
		break;
	case TO_DRAW:
		pAct = new SwitchToDrawAction(this);
		break;

	case CHANGE_DRAWING_COLOR:
		DrawOrFill = 'D';
		UI.InterfaceMode = MODE_COLORS;
		break;

	case CHANGE_FILL_COLOR:
		DrawOrFill = 'F';
		UI.InterfaceMode = MODE_COLORS;
		break;

	case COLOUR_BLACK:
		pAct = new ChangeColorAction(this, DrawOrFill, BLACK);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case COLOUR_BLUE:
		pAct = new ChangeColorAction(this, DrawOrFill, BLUE);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case COLOUR_RED:
		pAct = new ChangeColorAction(this, DrawOrFill, RED);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case COLOUR_GREEN:
		pAct = new ChangeColorAction(this, DrawOrFill, GREEN);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case COLOUR_ORANGE:
		pAct = new ChangeColorAction(this, DrawOrFill, ORANGE);
		UI.InterfaceMode = MODE_DRAW;
		break;

	case COLOUR_YELLOW:
		pAct = new ChangeColorAction(this, DrawOrFill, YELLOW);
		UI.InterfaceMode = MODE_DRAW;
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
void ApplicationManager::SaveAll(ofstream& OutFile)
{
	OutFile << ColorToString(pOut->getCrntDrawColor()) << '\t'
		<< ColorToString(pOut->getCrntFillColor()) << '\n'
		<< FigCount << '\n';
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
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

////////////////////////////////////////////////////////////////////////////////////
// Convert Color class into string
string ApplicationManager::ColorToString(color Color)
{
	if (Color == BLACK)
		return "BLACK";
	if (Color == YELLOW)
		return "YELLOW";
	if (Color == ORANGE)
		return "ORANGE";
	if (Color == RED)
		return "RED";
	if (Color == GREEN)
		return "GREEN";
	if (Color == BLUE)
		return "BLUE";
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

// Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
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
void ApplicationManager::SetSelectedFig(CFigure* selcetFig)
{
	SelectedFig = selcetFig;
}
CFigure* ApplicationManager::GetSelectedFig() const
{
	return SelectedFig;
}
void ApplicationManager::UnselectAll(CFigure* CurrntFigure)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != CurrntFigure)
		{
			FigList[i]->SetSelected(false);
		}
	}
}

void ApplicationManager::DeleteFigure(CFigure* SelectedFigure)
{
	//loop through all figures
	for (int i = 0; i < FigCount; i++)
	{
		//Search for the SelectedFig in FigList array
		if (SelectedFigure == FigList[i])
		{
			//Change the SelectedFig data member to NULL
			SelectedFig = NULL;

			FigList[i] = FigList[--FigCount];
			FigList[FigCount] = NULL;
			return;
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

	//////////////////////////////////////////////
	/// Switch tool bar according to mode
	/// This will also fix drawing over tool bar
	//////////////////////////////////////////////
	switch (UI.InterfaceMode)
	{
	case MODE_DRAW:
		pOut->CreateDrawToolBar();
		break;
	case MODE_SHAPES:
		pOut->CreateShapesToolBar();
		break;
	case MODE_COLORS:
		pOut->CreateColorsToolBar();
		break;
	case MODE_PLAY:
		pOut->CreatePlayToolBar();
		break;
	default:
		break;
	}
}
////////////////////////////////////////////////////////////////////////////////////
// Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
// Return a pointer to the output
Output* ApplicationManager::GetOutput() const
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
