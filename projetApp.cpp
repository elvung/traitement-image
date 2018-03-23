*******************************************************
 * Name:      projetApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2018-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "projetApp.h"
#include "projetMain.h"

IMPLEMENT_APP(projetApp);

bool projetApp::OnInit()
{
    projetFrame* frame = new projetFrame(0L, _("wxWidgets Application Template"));

    frame->Show();

    return true;
}
