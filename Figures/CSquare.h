#ifndef CSEQU_H
#define CSEQU_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo, int id);
	CSquare(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile, int ID) const;
	virtual void Load(ifstream& InFile);
	virtual bool IsInFigure(Point CheckPoint) const;
};

#endif