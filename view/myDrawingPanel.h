#ifndef __MYDRAWINGPANEL__
#define __MYDRAWINGPANEL__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#ifndef __RECANGLE_H__
#include "../modele/rectangle.h"
#endif
#include "../modele/cercle.h"
#include "../modele/draw.h"
#include "../modele/point.h"

#include <cmath>

//------------------------------------------------------------------------
class MyDrawingPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyDrawingPanel( wxWindow *parent ) ;
	void OpenFile(wxString fileName) ;
	void SaveFile(wxString fileName) ;

private:
	void OnMouseMove(wxMouseEvent &event) ;
	void OnMouseLeftDown(wxMouseEvent &event) ;
    void OnMouseLeftUp(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event) ;
	void OnDrawRect(Rectangle rect);
	void OnDrawCercle(Cercle cercle);
    void OnDrawVector();
    void FormeSelection();
	wxPoint m_mousePoint ;
	wxPoint m_onePoint ;
	Draw m_draw;
	bool m_pressed;
};

#endif
