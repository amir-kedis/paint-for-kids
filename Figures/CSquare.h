#ifndef CSEQU_H
#define CSEQU_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Move(Point NewCenter);
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(ifstream& InFile);
	virtual string ClassString() const;
	virtual bool IsInFigure(Point CheckPoint) const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif