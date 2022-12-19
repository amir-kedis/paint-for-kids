#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile, int ID) const
{
	OutFile << "SQUARE \t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< ColorToString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		OutFile << ColorToString(FigGfxInfo.FillClr) << '\n';
	else
		OutFile << "NO_FILL\n";
}
bool CSquare::IsInFigure(Point CheckPoint) const
{
	// to check of point is in square:
	// x courdinate of point must be within (Side Length / 2) from the x of the center
	// same applies for y

	bool XIsInShape = (CheckPoint.x >= (Center.x - 50) && CheckPoint.x <= (Center.x + 50));
	bool YIsInShape = (CheckPoint.y >= (Center.y - 50) && CheckPoint.y <= (Center.y + 50));

	return (XIsInShape && YIsInShape);
}
