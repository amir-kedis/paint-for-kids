#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,		//Drawing mode (startup mode)
	MODE_SHAPES,	//Shapes Mode To choose shapes from 
	MODE_COLORS,	//Colors Mode To change color from
	MODE_PLAY		//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADD_FIGURE,		  //Add Figure item in menu
	ITM_SELECT_ONE,       //Select item in menu
	ITM_DRAWING_COLOR,    //Drawing color item in menu
	ITM_FILL_COLOR,       //Filling color item in menu
	ITM_DELETE_FIGURE,    //Delete Figure item in menu
	ITM_MOVE_FIGURE,      //Move Figure item in menu
	ITM_UNDO,             //Undo operation item in menu
	ITM_REDO,             //Redo the undone operation item in menu
	ITM_CLEAR_ALL,        //Clear All Actions item in menu
	ITM_START_RECORDING,  //Start Recording item in menu
	ITM_STOP_RECORDING,   //Stop Recording item in menu
	ITM_PLAY_RECORDING,   //Play Recording item in menu
	ITM_SAVE,             //Save Graph item in menu
	ITM_LOAD,             //Load Saved Graph item in menu
	ITM_SWITCH,           //Switch to Play Mode item in menu

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ShapesMenuItem //The items of the Shapes menu
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	// 
	ITM_RECT,				//Draw Rectangle item in menu
	ITM_SQUARE,				//Draw Square item in menu
	ITM_CIRCLE,				//Draw Circle item in menu
	ITM_TRI,				//Draw Triangle item in menu
	ITM_HEX,				//Draw Hexagon item in menu

	SHAPES_ITM_COUNT
};

enum ColorsMenuItem //The items of the colors menu
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	// 
	ITM_BLACK,    //Add Black color icon in menu
	ITM_YELLOW,	  //Add Yellow color icon in menu	
	ITM_ORANGE,   //Add Orange color icon in menu
	ITM_RED,      //Add Red color icon in menu
	ITM_GREEN,    //Add Green color icon in menu
	ITM_BLUE,     //Add Blue color icon in menu

	COLORS_ITM_COUNT    //no. of menu items ==> This should be the last line in this enum
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_PICK_BY_SHAPES,
	ITM_PICK_BY_COLORS,
	ITM_PICK_BY_BOTH,
	ITM_DRAW_MODE,
	ITM_PLAY_EXIT,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;     //ToolBar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif