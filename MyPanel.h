#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/filedlg.h>
#endif
#include "MyImage.h"
#include "MyThresholdDialog.hpp"
#include <stack>
#include "MyHistogram.hpp"
#include "MyLuminoDialog.h"


class MyPanel: public wxPanel{

public:
    MyPanel( wxWindow *parent ) ;
    void OpenImage(wxString fileName);
    void OnPaint(wxPaintEvent &WXUNUSED(event));
    void MiroirImage();
    void BlurImage();
    void RotationImage();
    void Negative();
    void Desaturate();
    void Threshold(int seuil);
    void Posterize();
    void Annuler();
    void Contrast();
    void AddToPileRetour();
    void Lumino();







    ~MyPanel() ;

private:

    wxBitmap m_bitmap ;	// used to display the image
    MyImage *m_image ;	// used to load and process the image		// used to load and process the image
};
