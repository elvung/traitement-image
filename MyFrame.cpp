#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/filedlg.h>
#endif
#include "MyImage.h"
#include "MyThresholdDialog.hpp"
#include "MyFrame.h"


enum	// énumération. Elle gère la numérotation automatiquement
{
	ID_Hello = 1,
	ID_Encours,	// a pour valeur 2
	ID_PlusLarge, // a pour valeur 3
	ID_MoinsLarge, // a pour valeur 4
	ID_Miroir,
	ID_Miroirbis,
	ID_Blur,
	ID_Rotate,
	ID_Nega,
	ID_Desa,
	ID_Thresh,
	ID_Poste,
	ID_Annuler

};



MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size){

    m_panel = new MyPanel(this);

	wxMenu *menuFile = new wxMenu ;
	menuFile->Append(ID_Hello, wxT("Hello...\tCtrl-H"), wxT("hello")) ;
	Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello) ;

	menuFile->Append(wxID_OPEN);
	Bind(wxEVT_MENU, &MyFrame::OnOpenImage, this, wxID_OPEN);

	menuFile->Append(wxID_ABOUT);
	Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);

	menuFile->Append(ID_PlusLarge, wxT("Plus Large...\tCtrl+"));
	Bind(wxEVT_MENU, &MyFrame::OnResize, this, ID_PlusLarge);

	menuFile->Append(ID_MoinsLarge, wxT("Moins Large...\tCtrl-"));
	Bind(wxEVT_MENU, &MyFrame::OnResize, this, ID_MoinsLarge);

	menuFile->Append(wxID_EXIT) ;
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT) ;

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(ID_Encours, wxT("En cours...\tCtrl-E"));
	Bind(wxEVT_MENU, &MyFrame::OnEnCours, this, ID_Encours);

    wxMenu *menuProcess = new wxMenu;
	menuProcess->Append(ID_Miroir, wxT("Miroir..\tCtrl-M"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Miroir);

    menuProcess->Append(ID_Miroirbis, wxT("Miroir reverse...\tCtrl-L"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Miroirbis);

	menuProcess->Append(ID_Blur, wxT("Blur...\tCtrl-B"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Blur);

    menuProcess->Append(ID_Rotate, wxT("Rotation...\tCtrl-R"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Rotate);

    menuProcess->Append(ID_Nega, wxT("Negative...\tCtrl-N"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Nega);

    menuProcess->Append(ID_Desa, wxT("Desaturate...\tCtrl-D"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Desa);

    menuProcess->Append(ID_Thresh, wxT("Threshold...\tCtrl-T"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Thresh);

    menuProcess->Append(ID_Poste, wxT("Posterize...\tCtrl-P"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Poste);

    menuProcess->Append(ID_Annuler, wxT("Annuler...\tCtrl-Z"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Annuler);

	wxMenuBar *menuBar = new wxMenuBar ;
	menuBar->Append( menuFile, wxT("File" )) ;
	menuBar->Append( menuHelp, wxT("Help" ));
    menuBar->Append( menuProcess, wxT("Process" ));

	SetMenuBar(menuBar) ;

	Bind(wxEVT_MOTION, &MyFrame::OnMouse, this);
    CreateStatusBar();
    SetStatusText(wxT("Hello!"));
}

void MyFrame::OnHello(wxCommandEvent& event){
	wxLogMessage(wxT("Hello world from wxWidgets!"));
}

void MyFrame::OnExit(wxCommandEvent& event){
	Close( true );
}

void MyFrame::OnOpenImage(wxCommandEvent& event){
    wxString img = wxFileSelector();
    if (!img.empty()){
        m_panel->OpenImage(img);
    }
}

void MyFrame::OnAbout(wxCommandEvent& event){
    wxLogMessage(wxT("Auteur: Antoine Jayet-Lafarge 2017/2018"));
}

void MyFrame::OnEnCours(wxCommandEvent& event){
    wxLogMessage(wxT("En construction !"));
}

void MyFrame::OnResize(wxCommandEvent& event){
    int w = 0;
    int h = 0;

    GetSize(&w,&h);

    if (event.GetId() == ID_PlusLarge){
        SetSize(w+100,h+100);
    }

    if (event.GetId() == ID_MoinsLarge){
        SetSize(w-100,h-100);
    }
}

void MyFrame::OnMouse(wxMouseEvent& event){
    wxCoord x = event.GetX();
    wxCoord y = event.GetY();
    wxString coord;
    coord.sprintf("x=%d y=%d", x,y);

    SetStatusText(coord);
}
void MyFrame::OnProcessImage(wxCommandEvent& event){
    m_panel->AddToPileRetour();
    switch(event.GetId()){
        case ID_Miroir :
                m_panel->MiroirImage();
            break;
        case ID_Miroirbis :
                //m_panel->MiroirImage(false);
            break;
        case ID_Blur :
                m_panel->BlurImage();
            break;
        case ID_Rotate :
                m_panel->RotationImage();
            break;
        case ID_Nega :
                m_panel->Negative();
            break;
        case ID_Desa :
                m_panel->Desaturate();
            break;
        case ID_Thresh :
                m_panel->Threshold(128);
            break;
        case ID_Poste :
                m_panel->Posterize();
            break;
        case ID_Annuler :
                m_panel->Annuler();

    }
}
