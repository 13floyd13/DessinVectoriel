#ifndef __MYAPP__
#define __MYAPP__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include<wx/filedlg.h>
#include <wx/image.h>
#include <wx/file.h>
#include <wx/bitmap.h>

#include "../view/myFrame.h"
#include "../view/myDrawingPanel.h"
#include "../view/myControlPanel.h"


class MyApp: public wxApp
//------------------------------------------------------------------------
{
    virtual bool OnInit() ;
};


#endif
