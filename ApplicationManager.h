#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

	// Max no of Actions to be recorded
	enum { MaxRecordActionCount = 20 };

	// Max no of Actions to be stored for Undo and Redo
	enum { MaxURActionCount = 5 };
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	char DrawOrFill;

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	/////////////////////////////////////////
	/// Record Action Related Members
	/////////////////////////////////////////
	int RecordActionCount;					// Actual no of Action
	Action* ActionList[MaxRecordActionCount];
	bool IsRecording;
	/////////////////////////////////////////

	////////////////////////////////////////
	//// Undo and Redo Related Members
	////////////////////////////////////////
	int URActionCount;                      //Undo Redo ActionCount
	Action* URActionList[MaxURActionCount];
	int UndoCount;                           //Number of Undo Operations Done Consecutivly

	////////////////////////////////////////
	bool IsSoundOn;			// Sound Flag

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void SaveAll(ofstream& OutFile);
	static color StringToColor(string str);
	static string ColorToString(color Color);
	bool GetRecordingStatus();
	void SetRecordingStatus(bool status);
	bool AddActionToRecording(Action* pAct);
	bool IsRecordActionListEmpty(); // Determines the status of the app so that recording can start or no
	void PlayRecording();
	void AddToURActionList(Action* pAct); //Adds the Action to Undo Redo ActionList
	int GetURActionCount() const;   //returns the num of URACtionCount to check if an undo action can be done or not
	void UndoAction();
	bool RedoAction();
	bool GetSoundStatus();
	void SetSoundStatus(bool);
	int GetUndoCount();
	void SetUndoCount(int c);

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure* selcetFig);
	CFigure* GetSelectedFig() const;
	string GetRandomFig(char ShapeOrColor, int& prev) const;
	void UnselectAll(CFigure* CurrntFigure);
	void DeleteFigure(CFigure* SelectedFigure);
	bool IsFigListEmpty(); // Determines the status of the app so that recording can start or no
	void MoveFigure(CFigure* SelectedFigure, Point Center);
	// Checks if there are still Figures that should be picked
	bool Stop(char ShapeOrColor, string Pick, string Pick2 = "") const;

	// -- Clear Functions
	void ClearUndoRedoList();
	void ClearRecording();
	void ClearFigList();
	void ClearAll();

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif