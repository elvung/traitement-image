#include "MyImage.h"
#include <set>
#include "MyHistogram.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
MyImage::MyImage(const wxString& fileName)
: wxImage(fileName)
{
}

MyImage::MyImage(wxImage image)
: wxImage(image)
{
}



MyImage::MyImage(int largeur, int hauteur)
: wxImage(largeur, hauteur)
{
}

MyImage::MyImage()
: wxImage()
{
}

void MyImage::Negative(){
unsigned char* data = this->GetData();
    for(int i = 0 ;  i<(this->GetWidth()*this->GetHeight())*3    ;   i++ ){
        data[i] = 255-data[i];
    }

}

void MyImage::Desaturate(){
unsigned char* data = this->GetData();
    for(int i = 0 ;  i<(this->GetWidth()*this->GetHeight())*3;   i=i+3 ){
        //int L = 0.2126 *data[i] + 0.7152 *data[i+1] + 0.0722 *data[i+2];
        int L = 0.3 *data[i] + 0.59 *data[i+1] + 0.11 *data[i+2];
        data[i]=L;
        data[i+1] = L ;
        data[i+2] = L;
    }

}

void MyImage::Threshold(int seuil){
    Desaturate();
    unsigned char* data = this->GetData();
    for(int i = 0 ;  i<(this->GetWidth()*this->GetHeight())*3;   i=i+3 ){


        if(data[i]<seuil){
            data[i]=0;
            data[i+1]=0;
            data[i+2]=0;
        }else{
            data[i]=255;
            data[i+1]=255;
            data[i+2]=255;
        }

    }

}

void MyImage::MirrorHM(){

 unsigned char* data = this->GetData();
   /* for(int i = 0 ;  i<((this->GetWidth()*this->GetHeight())*3)/2  ; i=i+3 ){

        int sauv1 ,sauv2, sauv3;
        sauv1 = data[i];
        sauv2 = data[i+1];
        sauv3 = data[i+2];

        data[i]   = data[((this->GetWidth()*this->GetHeight())*3)-i-2];
        data[i+1] = data[((this->GetWidth()*this->GetHeight())*3)-i-1];
        data[i+2] = data[((this->GetWidth()*this->GetHeight())*3)-i];

        data[((this->GetWidth()*this->GetHeight())*3)-i]   = sauv3;
        data[((this->GetWidth()*this->GetHeight())*3)-i-1] = sauv2;
        data[((this->GetWidth()*this->GetHeight())*3)-i-2] = sauv1;

    }*/

    /*
    HORIZONTAL
    int largeur = this->GetWidth();
    int hauteur = this->GetHeight();
    for(int y = 0 ; y < hauteur/2;y++){

        for(int x=0;x<largeur;x++){

            int i = (y*largeur+x)*3;
            int k = ((hauteur-y-1)*largeur+x)*3;

            int sauv;

            sauv = data[i];
            data[i]= data[k];
            data[k] = sauv;

            sauv = data[i+1];
            data[i+1] = data[k+1];
            data[k+1] = sauv ;

            sauv = data[i+2];
            data[i+2] = data[k+2];
            data[k+2] = sauv ;




            permut(data[i],data[k]);
            permut(data[i+1],data[k+1]);
            permut(data[i+2],data[k+2]);
*/
    int largeur = this->GetWidth();
    int hauteur = this->GetHeight();
    for(int y = 0 ; y < hauteur;y++){

        for(int x=0;x<largeur/2;x++){

            int i = (y*largeur+x)*3;
            int k = (y*largeur+(largeur-x-1))*3;

            int sauv;

            sauv = data[i];
            data[i]= data[k];
            data[k] = sauv;

            sauv = data[i+1];
            data[i+1] = data[k+1];
            data[k+1] = sauv ;

            sauv = data[i+2];
            data[i+2] = data[k+2];
            data[k+2] = sauv ;


        }
    }
}

MyImage MyImage::rotate90(){
    unsigned char* data = this->GetData();
    int largeur = this->GetWidth();
    int hauteur = this->GetHeight();
    unsigned char* resultat = (unsigned char*) malloc (hauteur*largeur*3);
    int i,x,j;

    for(int ligne = 0 ; ligne < hauteur;ligne++){

        for(int colonne=0;colonne<largeur;colonne++){

            i = (ligne*largeur+colonne)*3;
            x = hauteur-1-ligne;
            j = (colonne*hauteur+x)*3;


            resultat[j] = data[i];
            resultat[j+1] = data[i+1];
            resultat[j+2] = data[i+2];



        }
    }
    MyImage res = MyImage(hauteur,largeur);
    res.SetData(resultat);
    return res;

}

void MyImage::Posterize(){
    unsigned char* data = this->GetData();
    for(int i = 0 ;  i<(this->GetWidth()*this->GetHeight())*3; i++ ){


        if(data[i]<127){
            data[i]=0;
        }else{
            data[i]=255;
        }

    }

}

void MyImage::Annuler(){

    MyImage* my = new MyImage(this->GetWidth(),this->GetHeight());
    *my = pileRetour.top();
     pileRetour.pop();


    unsigned char* dataDeLimageActuelle = this->GetData();
    unsigned char* dataDuStack = my->GetData();



    for (int i ; i< this->GetWidth()*this->GetHeight()*3; i++ ){

        dataDeLimageActuelle[i] = 0;
        dataDeLimageActuelle[i] = dataDuStack[i];
    }
}

void MyImage::AddToPileRetour(){
    pileRetour.push(*this);
}

void MyImage::Lumino(int quantite){
    unsigned char* data = this->GetData();
    for(int i = 0 ;  i<(this->GetWidth()*this->GetHeight())*3; i++ ){
         if(data[i]+ quantite >255){
            data[i] = 255;
         }else if(data[i] + quantite<0){
            data[i] = 0 ;
         }else{
         data[i] += quantite;
         }
    }
}

void MyImage::EnhanceContrast(int minValue, int maxValue){


    int d = (255 * minValue)/(minValue-maxValue);
    int f = 255/(maxValue-minValue);

    if(minValue > 0 || maxValue < 255){
        unsigned char* data = this->GetData();
        int transfer;
        int taille = this->GetHeight()*this->GetWidth()*3;
        for (int i = 0; i< taille; i++){
                transfer = (f * data[i]) + d;
                if (transfer < 0){
                    data[i] = 0;
                }else if (transfer > 255){
                    data[i] = 255;
                }else
                data[i] = (f * data[i]) + d;
        }
    }
}
