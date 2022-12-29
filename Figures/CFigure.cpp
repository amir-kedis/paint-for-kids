#include "CFigure.h"
#include "../ApplicationManager.h"
#include <ctime>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	ID = (long)time(NULL) % 1000000;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure(int id)
{
	ID = id;
	Selected = false;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::ChngFigFillCond(bool IsFilled)
{
	FigGfxInfo.isFilled = IsFilled;
}

GfxInfo CFigure::GetFigInfo() const
{
	return FigGfxInfo;
}

//color CFigure::GetFillColor() const
//{
//	//if (FigGfxInfo.isFilled)
//		return FigGfxInfo.FillClr;
//	//else
//		//return 0;
//}
//
//color CFigure::GetDrawColor() const
//{
//	return FigGfxInfo.DrawClr;
//}

void CFigure::Save(ofstream& OutFile) const
{}

string CFigure::getFillColor() const
{
	if (FigGfxInfo.isFilled)
		return ApplicationManager::ColorToString(FigGfxInfo.FillClr);
	else
		return "Not Filled";
}

bool CFigure::IsThisType(string Shape, string Color, char ShapeOrColor) const
{
	if (ShapeOrColor == 'B')
		return (ClassString() == Shape && getFillColor() == Color);
	if(ShapeOrColor == 'S')
		return (ClassString() == Shape);
	return (getFillColor() == Color);
}

