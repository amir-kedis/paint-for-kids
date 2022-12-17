#include "CHexagon.h"
#include <fstream>

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream &OutFile, int ID) const
{
	OutFile << "HEXAGON\t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< ColorToString(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		OutFile <<  ColorToString(FigGfxInfo.FillClr) << '\n';
	else 
		OutFile << "NO_FILL\n";
}