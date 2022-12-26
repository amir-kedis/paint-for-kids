#include "CFigure.h"
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

void CFigure::Save(ofstream& OutFile) const
{}

string CFigure::ClassString() const
{
	return "Figure";
}

bool CFigure::IsThisType(CFigure* fig) const
{
	CFigure* test = dynamic_cast <CFigure*> (fig);
	if (test == NULL)
		return false;
	return true;
}

