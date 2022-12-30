#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <string>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure(int id);

	/////////////////////////////////////////////
	//## Select Fuctionality Related Methods
	/////////////////////////////////////////////
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool IsInFigure(Point CheckPoint) const = 0;

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	virtual void Move(Point NewCenter) = 0;         //Move the figure to a new point

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void ChngFigFillCond(bool IsFilled);

	virtual Point GetCenter() const = 0;
	GfxInfo GetFigInfo() const;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual void Save(ofstream& OutFile) const;	//Save the figure parameters to the file
	virtual void Load(ifstream& InFile) = 0;	//Load the figure parameters to the file
	virtual string ClassString() const = 0;
	virtual string getFillColor() const;

	// Checks if this class meets the parameters
	virtual bool IsThisType(string Pick, char ShapeOrColor) const;

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif