
#define APPLICATION_WIDTH	600
#define APPLICATION_HEIGHT	500
#define APP_NAME "M1102 Skeleton 1.0"
#define WIDGET_PANEL_WIDTH	150
#define WIDGET_Y0			30
#define WIDGET_Y_STEP		50

#include "myControlPanel.h"
#include "myFrame.h"

enum
{
	ID_QUIT = 1,
	ID_ABOUT,
	ID_LOAD,
	ID_SAVE,
	ID_BUTTON1,
	ID_SLIDER1,
	ID_CHECKBOX1,
	ID_COLORPICKER1,
	ID_COMBOBOX1,
	ID_COLORPICKER2
};

//------------------------------------------------------------------------
MyControlPanel::MyControlPanel(wxWindow *parent) : wxPanel(parent)
//------------------------------------------------------------------------
// In this constructor, create the controls and associate each of them (bind) a method
{
	int w, h, y ;
	GetParent()->GetSize(&w,&h) ;
	SetSize(wxRect(wxPoint(0,0), wxPoint(WIDGET_PANEL_WIDTH, h))) ;
	SetBackgroundColour(*wxLIGHT_GREY) ;

	y= WIDGET_Y0 ;
	m_checkBox = new wxCheckBox(this, ID_CHECKBOX1, "Show (x,y)", wxPoint(10, y), wxSize(100,20)) ;
	Bind(wxEVT_CHECKBOX, &MyControlPanel::OnCheckBox, this, ID_CHECKBOX1) ;

    y+= WIDGET_Y_STEP ;
    wxStaticText* text1 = new wxStaticText(this, wxID_ANY, wxT("Epaisseur : "), wxPoint(10, y)) ;

    y+= 15 ;
    m_slider = new wxSlider(this, ID_SLIDER1, 3, 0, 50, wxPoint(10, y), wxSize(100,20)) ;
    Bind(wxEVT_SCROLL_THUMBTRACK, &MyControlPanel::OnSlider, this, ID_SLIDER1) ;

	// ajout des colorpickers
	y+= WIDGET_Y_STEP ;
    wxStaticText* text2 = new wxStaticText(this, wxID_ANY, wxT("Pen"), wxPoint(10, y)) ;
	m_penColourPicker = new wxColourPickerCtrl(this, ID_COLORPICKER1, wxColour(0,0,0), wxPoint(60, y-3), wxSize(80,30));
	Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnPenColorChange, this, ID_COLORPICKER1);

    y+= WIDGET_Y_STEP ;
    wxStaticText* text3 = new wxStaticText(this, wxID_ANY, wxT("Brush"), wxPoint(10, y)) ;
    m_brushColourPicker = new wxColourPickerCtrl(this, ID_COLORPICKER1, wxColour(255,255,255), wxPoint(60, y-3), wxSize(80,30));
    Bind(wxEVT_COLOURPICKER_CHANGED, &MyControlPanel::OnBrushColorChange, this, ID_COLORPICKER2);

	// ajout du choix de la forme
	m_shapes.Add("Rectangle");
	m_shapes.Add("Cercle");
	m_shapes.Add("Selection");
//	m_shapes.Add("Triangle");
	y+= WIDGET_Y_STEP;
	m_comboBox = new wxComboBox(this, ID_COMBOBOX1, wxT("Rectangle"), wxPoint(10, y), wxDefaultSize, m_shapes, wxCB_READONLY);
	Bind(wxEVT_COMBOBOX, &MyControlPanel::OnShapeChoose, this, ID_COMBOBOX1);
}

//------------------------------------------------------------------------
void MyControlPanel::OnSlider(wxScrollEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

//------------------------------------------------------------------------
void MyControlPanel::OnCheckBox(wxCommandEvent &event)
//------------------------------------------------------------------------
{
	MyFrame* frame = (MyFrame*)GetParent() ;
	frame->RefreshDrawing() ;	// update the drawing panel
}

void MyControlPanel::OnPenColorChange(wxColourPickerEvent &event)
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;
}

void MyControlPanel::OnBrushColorChange(wxColourPickerEvent &event)
{
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;
}

void MyControlPanel::OnShapeChoose(wxCommandEvent &event) {
    MyFrame* frame = (MyFrame*)GetParent() ;
    frame->RefreshDrawing() ;
}