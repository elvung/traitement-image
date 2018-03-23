
// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/filedlg.h>
#endif
#include "MyImage.h"
#include "MyThresholdDialog.hpp"
#include "MyFrame.h"


class MyApp: public wxApp{

public:
    virtual bool OnInit();
};


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit(){

	MyFrame *frame = new MyFrame( wxT("Hello World"), wxPoint(50, 50), wxSize(450, 340) );
	frame->Show(true);
	frame->Centre(wxBOTH);
	wxInitAllImageHandlers();
	return true;
}

