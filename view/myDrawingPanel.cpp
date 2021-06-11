#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500
#define APP_NAME "M1102 Skeleton 1.0"
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50


#include <fstream>
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
	Refresh();
	Update() ;	// send an event that calls the OnPaint method

	// display shape in real time
	if (m_pressed) {
        MyFrame* frame =  (MyFrame*)GetParent() ;

        int color=frame->GetControlPanel()->GetPenColour().GetRGB();
        int fillColor=frame->GetControlPanel()->GetBrushColour().GetRGB();

        int thickness = frame->GetControlPanel()->GetSliderValue();

        wxString shape = frame->GetControlPanel()->GetComboBoxValue();
	    if (shape == "Rectangle") {
            OnDrawRect(Rectangle(m_onePoint.x, m_onePoint.y, m_mousePoint.x-m_onePoint.x, m_mousePoint.y-m_onePoint.y,"rectangle", color,fillColor,thickness));
	    } else if (shape == "Cercle") {
	        int radius = (int)sqrt((m_mousePoint.x-m_onePoint.x)*(m_mousePoint.x-m_onePoint.x)+(m_mousePoint.y-m_onePoint.y)*(m_mousePoint.y-m_onePoint.y));
            OnDrawCercle(Cercle(Point(m_onePoint.x, m_onePoint.y), radius,"cercle" , color, fillColor,thickness));
	    } if (shape == "Selection") {
            FormeSelection();
        }
	}
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftDown(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is pressed
{
    m_pressed = true;
	m_onePoint.x = event.m_x ;
	m_onePoint.y = event.m_y ;

    Refresh() ; // send an event that calls the OnPaint method
}

//------------------------------------------------------------------------
void MyDrawingPanel::OnMouseLeftUp(wxMouseEvent &event)
//------------------------------------------------------------------------
// called when the mouse left button is up
{
    m_pressed = false;
    MyFrame* frame =  (MyFrame*)GetParent() ;

    int color=frame->GetControlPanel()->GetPenColour().GetRGB();
    int fillColor=frame->GetControlPanel()->GetBrushColour().GetRGB();
    int thickness = frame->GetControlPanel()->GetSliderValue();

    wxString shape = frame->GetControlPanel()->GetComboBoxValue();
    if (shape == "Rectangle") {
        m_draw.AddForme(new Rectangle(m_onePoint.x, m_onePoint.y, m_mousePoint.x-m_onePoint.x, m_mousePoint.y-m_onePoint.y,"rectangle", color,fillColor,thickness));
    } else if (shape == "Cercle") {
        int radius = (int)sqrt((m_mousePoint.x-m_onePoint.x)*(m_mousePoint.x-m_onePoint.x)+(m_mousePoint.y-m_onePoint.y)*(m_mousePoint.y-m_onePoint.y));
        m_draw.AddForme(new Cercle(Point(m_onePoint.x, m_onePoint.y), radius,"cercle" , color, fillColor,thickness));
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
    wxColour m_colour = frame->GetControlPanel()->GetPenColour();

	// then paint
	wxPaintDC dc(this);


	dc.SetPen(wxPen(m_colour));

	OnDrawVector();


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
	/*// just to open (and close) any file
	std::vector<Forme*> tabForme;
	std::ifstream f(fileName,std::ios::binary);

	//FILE* f = fopen(fileName, "r") ;
	if (f)
	{

		while(f){
		    Forme* forme=Forme::Load(f);

		    tabForme.push_back((forme));

		}

		f.close();
	}*/
}

//------------------------------------------------------------------------
void MyDrawingPanel::SaveFile(wxString fileName)
//------------------------------------------------------------------------
{
	// just to create a tiny file
   /* std::vector<Forme*> tabForme= m_draw.GetForm();

	std::ostream f(fileName,std::ios::binary);
	if (!f)
		wxMessageBox(wxT("Cannot save file"));
	else {
        //fprintf(f, "S1102 software can create and write a file") ;
        for (auto it = tabForme.begin(); it != tabForme.end(); it++) {

            (*it)->Save(f);


            wxMessageBox(wxT("The file was saved"));
            f.close();
        }
    }*/

}
void MyDrawingPanel::OnDrawRect(Rectangle rectangle){
    wxPaintDC dc(this);
    // recup la valeur de l'épaisseur
    MyFrame* frame =  (MyFrame*)GetParent() ;

    wxColour penColor= rectangle.GetColor();
    dc.SetPen(wxPen(penColor,rectangle.GetThickness()));

    wxColour brushColor= rectangle.GetFillColor();
    dc.SetBrush(wxBrush(brushColor));

    wxPoint p=  (const wxPoint &) rectangle.GetCorner();
    wxSize size=wxSize(rectangle.GetWidth(),rectangle.GetHeight());
    dc.DrawRectangle(p,size);
}
void MyDrawingPanel::OnDrawCercle(Cercle cercle){
    wxPaintDC dc(this);
    // recup la valeur de l'épaisseur
    MyFrame* frame =  (MyFrame*)GetParent() ;


    wxColour penColor= cercle.GetColor();
    dc.SetPen(wxPen(penColor,cercle.GetThickness()));

    wxColour brushColor= cercle.GetFillColor();
    dc.SetBrush(wxBrush(brushColor));

    wxPoint p= (const wxPoint &) cercle.GetCentre();
    wxCoord r= (const wxCoord &) cercle.GetRadius();
    dc.DrawCircle(p,r);
}

void MyDrawingPanel::OnDrawVector()
{

    std::vector<Forme*> tabForme = m_draw.GetForm();
    for (auto it = tabForme.begin(); it != tabForme.end(); it++) {
        if ((*it)->GetLabel() == "rectangle") {
            Rectangle *r = dynamic_cast<Rectangle*>(*it);
            OnDrawRect(*r);
        } else if ((*it)->GetLabel() == "cercle") {
            Cercle *c = dynamic_cast<Cercle *>(*it);
            OnDrawCercle(*c);
        }
    }
}

void MyDrawingPanel::FormeSelection()
{
    std::vector<Forme*> tabForme = m_draw.GetForm();
    bool notSelected = true;
    auto it = tabForme.rbegin();
    while (it != tabForme.rend() && notSelected) {
        if ((*it)->GetLabel() == "rectangle") {
            Rectangle *r = dynamic_cast<Rectangle*>(*it);
            if (r->IsInside(m_onePoint.x, m_onePoint.y)) {

                Point corner = r->GetCorner();
                int c_x = corner.GetX() + (m_mousePoint.x - m_onePoint.x);
                int c_y = corner.GetY() + (m_mousePoint.y - m_onePoint.y);
                r->SetCorner(Point(c_x,c_y));

                // changement de onePoint pour garder le calcul linéraire
                m_onePoint.x = m_mousePoint.x;
                m_onePoint.y = m_mousePoint.y;

                notSelected = false;
            }
        } else if ((*it)->GetLabel() == "cercle") {
            Cercle *c = dynamic_cast<Cercle *>(*it);
            if (c->IsInside(m_onePoint.x, m_onePoint.y)) {

                Point centre = c->GetCentre();
                int c_x = centre.GetX() + (m_mousePoint.x - m_onePoint.x);
                int c_y = centre.GetY() + (m_mousePoint.y - m_onePoint.y);
                c->SetCenter(Point(c_x,c_y));

                // changement de onePoint pour garder le calcul linéraire
                m_onePoint.x = m_mousePoint.x;
                m_onePoint.y = m_mousePoint.y;

                notSelected = false;
            }
        }
        it++;
    }
}


