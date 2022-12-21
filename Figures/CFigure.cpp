#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo, int id)
{
	ID = id;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure(int id)
{
	ID = id;
}

int CFigure::Get_ID() const
{
	return ID;
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

void CFigure::Save(ofstream& OutFile, int ID) const
{
	OutFile << ColorToString(UI.DrawColor) << '\t'
		<< ColorToString(UI.FillColor) << '\n'
		<< ID << '\n';
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

