
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
        unsigned char* rotate90();
        void Posterize();
        void Annuler();
        void AddToPileRetour();


        void permut(int i , int x);



    private :
        std::stack<unsigned char*> pileRetour;
};
#endif // MYIMAGE_HPP_INCLUDED
