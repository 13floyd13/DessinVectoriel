#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500
#define APP_NAME "M1102 Skeleton 1.0"
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50


#include "myDrawingPanel.h"
#include "myFrame.h"

//------------------------------------------------------------------------
MyDrawingPanel::MyDrawingPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, bind some mouse events and the paint event with the appropriate methods
{
	int w, h ;
	GetParent()->GetClientSize(&w,&h) ;
	SetSize(wxRect(wxPoint(WIDGET_PANEL_WIDTH,0), wxPoint(w, h))) ;
	SetBackgroundColour(wxColour(0xFF,0xFF,0xFF)) ;
	Bind(wxEVT_MOTION, &MyDrawingPanel::OnMouseMove, this);
	Bind(wxEVT_LEFT_DOWN, &MyDrawingPanel::OnMouseLeftDown, this);
    Bind(wxEVT_LEFT_UP, &MyDrawingPanel::OnMouseLeftUp, this);
	Bind(wxEVT_PAINT, &MyDrawingPanel::OnPaint, this) ;
	m_onePoint.x = (w-WIDGET_PANEL_WIDTH)/2 ;
	m_onePoint.y = h/2 ;
	m_mousePoint = m_onePoint ;
    MyFrame* frame = (MyFrame*)GetParent() ;
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseMove(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse is moved
{
	m_mousePoint.x = event.m_x ;
	m_mousePoint.y = event.m_y ;
	Refresh() ;	// send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
	m_onePoint.x = event.m_x ;
	m_onePoint.y = event.m_y ;

//    Rectangle rect(m_onePoint.x, m_onePoint.y, m_onePoint.x-m_mousePoint.x, m_onePoint.y-m_mousePoint.y, "l");
//    OnDrawRect(rect);

    Refresh() ; // send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is up
{
    MyFrame* frame =  (MyFrame*)GetParent() ;
    wxString colorWxString=frame->GetControlPanel()->GetColour().GetAsString(wxC2S_HTML_SYNTAX);
    std::string colorStr= colorWxString.ToStdString();
    wxString shape = frame->GetControlPanel()->GetComboBoxValue();
    if (shape == "Rectangle") {
        m_draw.AddRect(Rectangle(m_onePoint.x, m_onePoint.y, m_mousePoint.x-m_onePoint.x, m_mousePoint.y-m_onePoint.y,"rectangle", colorStr,colorStr));
    } else if (shape == "Cercle") {
        m_draw.AddCercle(Cercle(Point(m_onePoint.x, m_onePoint.y), m_mousePoint.x-m_onePoint.x+m_mousePoint.y-m_onePoint.y,"cercle",colorStr, colorStr));
    }

    Refresh() ; // send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnPaint(wxPaintEvent &event)
//------------------------------------------------------------------------
// called automatically when the panel is shown for the first time or
// when the panel is resized
// You have to call OnPaint with Refresh() when you need to update the panel content
{
	// read the control values
	MyFrame* frame =  (MyFrame*)GetParent() ;
	int radius = frame->GetControlPanel()->GetSliderValue() ;
	bool check = frame->GetControlPanel()->GetCheckBoxValue() ;
    wxColour m_colour = frame->GetControlPanel()->GetColour();
									// Pour stocker la couleur sous forme de string: wxString colorWxString=frame->GetControlPanel()->GetColour().GetAsString(wxC2S_HTML_SYNTAX);
									// on cast en une string std::string colorStr= colorstr.ToStdString()
									//Pour récup la couleur on la cast de nouveau wxColour m_colour= static_cast<const wxString &>(colorStr);
									//dc.SetPen(wxPen(m_colour));
	// then paint
	wxPaintDC dc(this);


	dc.SetPen(wxPen(m_colour));

	OnDrawVector();

//	dc.DrawLine(m_mousePoint, m_onePoint) ;
//	dc.DrawRectangle(wxPoint(m_onePoint.x-radius/2, m_onePoint.y-radius/2), wxSize(radius,radius)) ;
//	dc.DrawCircle(wxPoint(m_mousePoint), radius/2) ;

	if (check)
	{
		wxString coordinates ;
		coordinates.sprintf(wxT("(%d,%d)"), m_mousePoint.x, m_mousePoint.y) ;
		dc.DrawText(coordinates, wxPoint(m_mousePoint.x, m_mousePoint.y+20)) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OpenFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to open (and close) any file
	FILE* f = fopen(fileName, "r") ;
	if (f)
	{
		wxMessageBox(wxT("The file was opened then closed")) ;
		fclose(f) ;
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to create a tiny file
	FILE* f = fopen(fileName, "w") ;
	if (!f)
		wxMessageBox(wxT("Cannot save file"));
	else
	{
		fprintf(f, "S1102 software can create and write a file") ;
		wxMessageBox(wxT("The file was saved")) ;
		fclose(f) ;
	}
}
void MyDrawingPanel::OnDrawRect(Rectangle rectangle){
    wxPaintDC dc(this);
    wxColour c = static_cast<const wxString &>(rectangle.GetColor());
    dc.SetPen(wxPen(c));
    wxPoint p=  (const wxPoint &) rectangle.GetCorner();
    wxSize size=wxSize(rectangle.GetWidth(),rectangle.GetHeight());
    dc.DrawRectangle(p,size);
}
void MyDrawingPanel::OnDrawCercle(Cercle cercle){
    wxPaintDC dc(this);
    wxColour c = static_cast<const wxString &>(cercle.GetColor());
    dc.SetPen(wxPen(c));
    wxPoint p= (const wxPoint &) cercle.GetCentre();
    wxCoord r= (const wxCoord &) cercle.GetRadius();
    dc.DrawCircle(p,r);
}

void MyDrawingPanel::OnDrawVector()
{
    std::vector<Rectangle> tabRect = m_draw.GetRect();
    for (auto it = tabRect.begin(); it != tabRect.end(); it++) {
        OnDrawRect(*it);
    }

    std::vector<Cercle> tabCercle = m_draw.GetCercle();
    for (auto it = tabCercle.begin(); it != tabCercle.end(); it++) {
        OnDrawCercle(*it);
    }
}
