#include "CFigure.h"
#include <ctime>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	ID = (long)time(NULL);
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

string CFigure::ColorToString(color Color)
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

color CFigure::StringToColor(string str)
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

