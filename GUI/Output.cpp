#include "Output.h"
#include <cmath>
#define PI 3.14159
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = color(26, 26, 26);		//Messages color
	UI.BkGrndColor = color(255, 239, 227);	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = color(251, 192, 147); // status Bar color
	UI.ToolBarColor = WHITE; // status Bar color
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateToolBarBox() const
{
	// clear ToolBar
	pWind->SetPen(UI.ToolBarColor, 1);  // set pen to white
	pWind->SetBrush(UI.ToolBarColor); // set fill color to white
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight); // draw Rectangle over tool bar
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	CreateToolBarBox();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_ADD_FIGURE] = "images\\MenuItems\\pick-both.jpg";
	MenuItemImages[ITM_SELECT_ONE] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DRAWING_COLOR] = "images\\MenuItems\\color-mode.jpg";
	MenuItemImages[ITM_FILL_COLOR] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[ITM_DELETE_FIGURE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE_FIGURE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEAR_ALL] = "images\\MenuItems\\clear-all.jpg";
	MenuItemImages[ITM_START_RECORDING] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAY_RECORDING] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\game-mode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(color(245, 66, 174), 1); // line under tool bar color and thickness
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	// Clears the toolbar before drawing the ICONS
	CreateToolBarBox();

	// gets icons paths from images folder
	string PlayMenuItemImages[PLAY_ITM_COUNT];
	PlayMenuItemImages[ITM_PICK_BY_SHAPES] = "images\\MenuItems\\pick-shape.jpg";
	PlayMenuItemImages[ITM_PICK_BY_COLORS] = "images\\MenuItems\\pick-color.jpg";
	PlayMenuItemImages[ITM_PICK_BY_BOTH] = "images\\MenuItems\\pick-both.jpg";
	PlayMenuItemImages[ITM_DRAW_MODE] = "images\\MenuItems\\draw-mode.jpg";
	PlayMenuItemImages[ITM_PLAY_EXIT] = "images\\MenuItems\\exit.jpg";

	// DRAW play menu icons one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(245, 66, 174), 1); // line under tool bar color and thickness
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateShapesToolBar() const
{
	///TODO: write code to create Shapes mode menu
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateColorsToolBar() const
{
	UI.InterfaceMode = MODE_COLORS;

	//Clears the toolbar before drawing the Icons
	CreateToolBarBox();    

	//gets icons paths from images folder
	string ColorsMenuItemImages[COLORS_ITM_COUNT];
	ColorsMenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	ColorsMenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	ColorsMenuItemImages[ITM_ORANGE] = "images\\MenuItems\\black.jpg";
	ColorsMenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	ColorsMenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	ColorsMenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";

	for (int i = 0; i < COLORS_ITM_COUNT; i++)
		pWind->DrawImage(ColorsMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	pWind->SetPen(color(245, 66, 174), 1); // line under tool bar color and thickness
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawHexagon(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	const int numberOfVertices = 6;
	const int radius = 80;
	int xCoordinates[numberOfVertices]; //Array of x coordinates of hexagon vertices
	int yCoordinates[numberOfVertices]; //Array of y coordinates of hexagon vertices

	double theta = PI/6.0;
	for (int i = 0; i < numberOfVertices; i++)  //Loop to get all coordinates by resolution
	{
		xCoordinates[i] = round(P1.x + (radius * cos(theta)));
		yCoordinates[i] = round(P1.y + (radius * sin(theta)));
		theta += PI / 3.0;
	}

	pWind->DrawPolygon(xCoordinates, yCoordinates, numberOfVertices, style);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	const int numberOfVertices = 4;
	const int sideLength = 100;
	int xCoordinates[numberOfVertices]; //Array of x coordinates of square vertices
	int yCoordinates[numberOfVertices]; //Array of y coordinates of square vertices

	xCoordinates[0] = P1.x + sideLength / 2;
	yCoordinates[0] = P1.y + sideLength / 2;
	xCoordinates[1] = P1.x + sideLength / 2;
	yCoordinates[1] = P1.y - sideLength / 2;
	xCoordinates[2] = P1.x - sideLength / 2;
	yCoordinates[2] = P1.y - sideLength / 2;
	xCoordinates[3] = P1.x - sideLength / 2;
	yCoordinates[3] = P1.y + sideLength / 2;

	pWind->DrawPolygon(xCoordinates, yCoordinates, numberOfVertices, style);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;


	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int radius = sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)); //Calculate the radius of the circle (the distance between P1 and P2)

	pWind->DrawCircle(P1.x, P1.y, radius, style); //Draw the Circle with P1 as the center of the circle

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

