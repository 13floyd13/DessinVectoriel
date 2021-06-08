//************************************************************************
//************************************************************************
// Application class
//************************************************************************
//************************************************************************

// For compilers that support precompilation, includes "wx/wx.h".


#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500
#define APP_NAME "M1102 Skeleton 1.0"
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50

#include "myApp.h"

//------------------------------------------------------------------------
bool MyApp::OnInit()
//------------------------------------------------------------------------
{
	MyFrame *frame = new MyFrame(wxT(APP_NAME), wxDefaultPosition, wxSize(APPLICATION_WIDTH,APPLICATION_HEIGHT)) ;
	frame->Show(true) ;
	SetTopWindow(frame) ;
	return true ;
}
