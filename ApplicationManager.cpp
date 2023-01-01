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
#include "Actions\MoveFigureAction.h"
#include "Actions/SwitchToDrawAction.h"
#include "Actions/ChangeColorAction.h"
#include "Actions/StartRecordingAction.h"
#include "Actions/StopRecordingAction.h"
#include "Actions/PlayRecordingAction.h"
#include "Actions/ClearAllAction.h"
#include "Actions/ExitAction.h"
#include "Actions/PickByShapesAction.h"
#include "Actions/PickByColorsAction.h"
#include "Actions//PickByBothAction.h"
#include "Actions\UndoAct.h"
#include "Actions/RedoAct.h"
#include "Actions/SoundAction.h"
#include <Windows.h>
#include <cstdlib>


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

	/////////////////////////////////////////
	/// Init Action Record List Related Members
	/////////////////////////////////////////
	RecordActionCount = 0;

	IsRecording = false;
	// Create an array of Action pointers and set them to NULL
	for (int i = 0; i < MaxRecordActionCount; i++)
	{
		ActionList[i] = NULL;
	}
	/////////////////////////////////////////

	/////////////////////////////////////////
	/// Undo and Redo Related Members
	/////////////////////////////////////////
	URActionCount = 0;
	for (int i = 0; i < MaxURActionCount; i++)
	{
		URActionList[i] = NULL;
	}

	UndoCount = 0;

	/////////////////////////////////////////
	IsSoundOn = true;
	UI.IsSoundOn = true;
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

	case MOVE_FIGURE:
		pAct = new MoveFigureAction(this);
		break;

	case UNDO:
		pAct = new UndoAct(this);
		break;

	case REDO:
		pAct = new RedoAct(this);
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
	case START_RECORDING:
		pAct = new StartRecordingAction(this);
		break;
	case STOP_RECORDING:
		pAct = new StopRecordingAction(this);
		break;
	case PLAY_RECORDING:
		pAct = new PlayRecordingAction(this);
		break;

	case CLEAR_ALL:
		pAct = new ClearAllAction(this);
		break;

	case PICK_BY_SHAPES:
		UI.InterfaceMode = MODE_PLAY;
		pAct = new PickByShapesAction(this);
		break;

	case PICK_BY_COLORS:
		UI.InterfaceMode = MODE_PLAY;
		pAct = new PickByColorsAction(this);
		break;

	case PICK_BY_BOTH:
		UI.InterfaceMode = MODE_PLAY;
		pAct = new PickByBothAction(this);
		break;

	case SOUND:
		pAct = new SoundAction(this);
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case STATUS: // a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		bool ShouldBeDeleted = pAct->Execute(); // execute and and action to lists
		if (ShouldBeDeleted) // delete the action if we are not recording
		{
			delete pAct;	 // You may need to change this line depending to your implementation
			pAct = NULL;
		}
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

string ApplicationManager::GetRandomFig(char ShapeOrColor, int& prev) const
{
	int r;
	// This is needed for getting the color of the same picked shape in case of pickking by shape and color
	if (prev >= 0)
		r = prev;
	else
	{
		srand(time(0)); // to get a new random number whenver I reopen the programm
		// get random number from 0 to Figcount-1
		r = rand() % FigCount;
		prev = r;
	}

	if (ShapeOrColor == 'S')
		return FigList[r]->ClassString();

	return FigList[r]->getFillColor();
}

bool ApplicationManager::Stop(char ShapeOrColor, string Pick, string Pick2) const
{
	if (ShapeOrColor == 'B')
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->ClassString() == Pick && FigList[i]->getFillColor() == Pick2)
				return false;
		}
	}
	else if (ShapeOrColor == 'S')
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->ClassString() == Pick)
				return false;
		}
	}
	else
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->getFillColor() == Pick)
				return false;
		}
	}
	return true;
}

bool ApplicationManager::GetRecordingStatus()
{
	return IsRecording;
}

void ApplicationManager::SetRecordingStatus(bool status)
{
	IsRecording = status;
}
/// <summary>
/// 
/// </summary>
/// <param name="pAct"></param>
/// <returns>Retruns True if added succuessfully to list</returns>
bool ApplicationManager::AddActionToRecording(Action* pAct)
{
	if (RecordActionCount < MaxRecordActionCount)
	{
		ActionList[RecordActionCount++] = pAct;
		return true;
	}
	return false;
}

bool ApplicationManager::IsRecordActionListEmpty()
{
	return (RecordActionCount == 0);
}

void ApplicationManager::PlayRecording()
{
	for (int i = 0; i < RecordActionCount; i++)
	{
		ActionList[i]->Execute(false);
		UpdateInterface();
		Sleep(1000);
	}
}

void ApplicationManager::ClearUndoRedoList()
{
	//MaxURActionCount is used instead of URActionCount because when undoing or redoing something
	//we change the counter so if we clear all some actions won't be cleared
	for (int i = 0; i < MaxURActionCount; i++)
	{
		if (URActionList[i] != NULL)
		{
			if (URActionList[i]->IsActionRecorded())
				URActionList[i] = NULL;
			else
			{
				delete URActionList[i];
				URActionList[i] = NULL;
			}
		}
	}
	URActionCount = 0;
}

void ApplicationManager::ClearRecording()
{
	for (int i = 0; i < RecordActionCount; i++)
	{
		delete ActionList[i];
		ActionList[i] = NULL;
	}
	RecordActionCount = 0;
	IsRecording = false;
}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}

void ApplicationManager::AddToURActionList(Action* pAct)
{
	if (URActionCount < MaxURActionCount)
	{
		URActionList[URActionCount++] = pAct;
	}
	else
	{
		if (!URActionList[0]->IsActionRecorded())
		{
			delete URActionList[0];
		}
		for (int i = 1; i < MaxURActionCount; i++)
		{
			URActionList[i - 1] = URActionList[i];
			if (i == MaxURActionCount - 1)
			{
				URActionList[i] = pAct;
			}
		}
	}
}

int ApplicationManager::GetURActionCount() const
{
	return URActionCount;
}

void ApplicationManager::UndoAction()
{
	//Call the UndoAct function in the action class and decrement the Count by 1
	URActionList[--URActionCount]->UndoAct();
}


bool ApplicationManager::RedoAction()
{
	if (URActionList[URActionCount] == NULL)
	{
		return false;
	}
	else
		URActionList[URActionCount++]->RedoAct();
	return true;
}

bool ApplicationManager::GetSoundStatus()
{
	return IsSoundOn;
}

void ApplicationManager::SetSoundStatus(bool status)
{
	IsSoundOn = status;
}

int ApplicationManager::GetUndoCount()
{
	return UndoCount;
}

void ApplicationManager::SetUndoCount(int c)
{
	if (c >= 0)
		UndoCount = c;
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

			FigList[i] = FigList[--FigCount];     //Make the Pointer of i point at the last figure's address
			FigList[FigCount] = NULL;
			return;
		}
	}
}

bool ApplicationManager::IsFigListEmpty()
{
	return (FigCount == 0);
}

void ApplicationManager::MoveFigure(CFigure* SelectedFigure, Point Center)
{
	//loop through all figures
	for (int i = 0; i < FigCount; i++)
	{
		//Search for the SelectedFig in FigList array
		if (SelectedFigure == FigList[i])
		{
			//Call Move Function to move the figure to the new point
			FigList[i]->Move(Center);

			//Change the SelectedFig data member to NULL
			SelectedFig = NULL;
		}
	}
}

void ApplicationManager::ClearAll()
{
	ClearFigList();

	ClearUndoRedoList();

	ClearRecording();

	UndoCount = 0;          //Reset the counter
	UI.IsFilled = false;    //Make the newly drawen figures unfilled
	UI.DrawColor = BLUE;    //Make the newly drawen figure have the default color (blue)

	//Make the SelectedFig point to NULL
	SelectedFig = NULL;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

// Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
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
	ClearAll();

	delete pIn;
	delete pOut;
}
