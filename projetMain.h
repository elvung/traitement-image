/***************************************************************
 * Name:      projetMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef PROJETMAIN_H
#define PROJETMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "projetApp.h"

class projetFrame: public wxFrame
{
    public:
        projetFrame(wxFrame *frame, const wxString& title);
        ~projetFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // PROJETMAIN_H
