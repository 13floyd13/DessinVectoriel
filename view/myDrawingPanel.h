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
	void OnPaint(wxPaintEvent &event) ;
	void OnDrawRect(Rectangle rect);
	void OnDrawCercle(Cercle cercle);
	wxPoint m_mousePoint ;
	wxPoint m_onePoint ;
};

#endif
