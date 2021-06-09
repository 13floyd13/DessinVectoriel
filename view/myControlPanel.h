#ifndef __MYCONTROLPANEL__
#define __MYCONTROLPANEL__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>
#include <wx/clrpicker.h>

#include "../modele/draw.h"
#include "../modele/cercle.h"
#include "../modele/rectangle.h"

//------------------------------------------------------------------------
class MyControlPanel: public wxPanel
//------------------------------------------------------------------------
{
public:
	MyControlPanel( wxWindow *parent ) ;
	int GetSliderValue() {return m_slider->GetValue() ;} ;
	bool GetCheckBoxValue() {return m_checkBox->GetValue() ;} ;
    wxColour GetColour() {return m_colourPicker->GetColour();};
    wxString GetComboBoxValue() {return m_comboBox->GetValue();}

private:
	void OnButton(wxCommandEvent &event) ;
	void OnSlider(wxScrollEvent &event) ;
	void OnCheckBox(wxCommandEvent &event) ;
    void OnColorChange(wxColourPickerEvent &event);
    void OnShapeChoose(wxCommandEvent &event);
	wxButton* m_button ;
	wxSlider* m_slider ;
	wxCheckBox* m_checkBox ;
    wxColourPickerCtrl* m_colourPicker;
    wxComboBox* m_comboBox;
    wxArrayString m_shapes;
};

#endif
