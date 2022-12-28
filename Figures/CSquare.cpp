#include "CSquare.h"
#include "../ApplicationManager.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = (long)time(NULL) % 1000000;
	Center = P1;
}

CSquare::CSquare(int id) :CFigure(id)
{
	ID = id;
	Selected = false;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

void CSquare::Move(Point NewCenter)
{
	Center = NewCenter;
}

void CSquare::Save(ofstream& OutFile) const
{
	OutFile << "SQUARE \t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled)
		OutFile << ApplicationManager::ColorToString(FigGfxInfo.FillClr) << '\n';
	else
		OutFile << "NO_FILL\n";
}

void CSquare::Load(ifstream& InFile)
{
	string Color;
	InFile >> Center.x >> Center.y >> Color;

	ChngDrawClr(ApplicationManager::StringToColor(Color));

	InFile >> Color;

	if (Color == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
		ChngFillClr(ApplicationManager::StringToColor(Color));
}

string CSquare::ClassString() const
{
	return "Square";
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

void CSquare::PrintInfo(Output* pOut)
{
	string Info = "SQUARE \t";
	Info += "id: " + to_string(ID);
	Info += " center: (" + to_string(Center.x) + ", " + to_string(Center.y) + ") ";
	Info += " " + ApplicationManager::ColorToString(FigGfxInfo.DrawClr) + ' ';


	if (FigGfxInfo.isFilled)
	{
		Info += ApplicationManager::ColorToString(FigGfxInfo.FillClr) + ' ';
	}
	else
	{
		Info += "NO_FILL ";

	}

	pOut->PrintMessage(Info);
}
