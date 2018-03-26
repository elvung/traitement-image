#include "MyPanel.h"


MyPanel::MyPanel(wxWindow *parent)
: wxPanel(parent){
    m_image = nullptr;
    Bind(wxEVT_PAINT, &MyPanel::OnPaint, this) ;
}

MyPanel::~MyPanel(){

}

void MyPanel::OpenImage(wxString filename){
   m_image = new MyImage(filename);
    this->GetParent()->SetClientSize(m_image->GetWidth(),m_image->GetHeight());
    Refresh();
}

void MyPanel::OnPaint(wxPaintEvent &WXUNUSED(event)){
    if (m_image != nullptr){
        m_bitmap = wxBitmap(*m_image,wxBITMAP_SCREEN_DEPTH);

        wxPaintDC dc(this);
        dc.DrawBitmap(m_bitmap,0,0,false);

    }
}

void MyPanel::MiroirImage(){

m_image->MirrorHM();
    Refresh();
}

void MyPanel::BlurImage(){

*m_image = m_image->Blur(20);
Refresh();
}

void MyPanel::RotationImage(){
*m_image = m_image->Rotate90();
Refresh();
}

void MyPanel::Negative(){
m_image->Negative();
Refresh();
}

void MyPanel::Desaturate(){

m_image->Desaturate();
Refresh();
}

void MyPanel::Threshold(int seuil){
MyThresholdDialog *dlg = new MyThresholdDialog(this, -1, wxT("Threshold"), wxDefaultPosition, wxSize(250,140)) ;
dlg->ShowModal() ;
m_image->Threshold(dlg->m_threshold->GetValue());
Refresh();
}

void MyPanel::Posterize(){
m_image->Posterize();
Refresh();
}

void MyPanel::Annuler(){
*m_image = m_image->Annuler();
Refresh();
}
void MyPanel::AddToPileRetour(){
m_image->AddToPileRetour();
}

void MyPanel::Number(){
m_image->NbCouleur();
}
