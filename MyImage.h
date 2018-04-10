
#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wxprec.h>
#include <stack>



class MyImage : public wxImage{
    public :
        MyImage(const wxString& fileName) ;
        MyImage(wxImage image) ;
        MyImage(int largeur, int hauteur);
        MyImage() ;
        void Negative();
        void Desaturate();
        void Threshold(int seuil);
        void MirrorHM();
        MyImage rotate90();
        void rotate180();
        void Posterize();
        void Annuler();
        void AddToPileRetour();
        void Lumino(int quantite);

    private :
        std::stack<MyImage> pileRetour;
        std::stack<int> pileTest;


        int valeur = 0;
};
#endif // MYIMAGE_HPP_INCLUDED
