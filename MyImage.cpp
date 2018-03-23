#include "MyImage.h"

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
        int L = 0.2126 *data[i] + 0.7152 *data[i+1] + 0.0722 *data[i+2];
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

unsigned char* MyImage::rotate90(){
    unsigned char* data = this->GetData();
    int largeur = this->GetWidth();
    int hauteur = this->GetHeight();
    unsigned char* resultat = (unsigned char*) malloc (hauteur*largeur*3);

    for(int colonne = 0 ; colonne < largeur;colonne++){

        for(int ligne=0;ligne<hauteur;ligne++){

            int i = (colonne*ligne)*3;
            int j = ((largeur-colonne)*ligne)*3;

            resultat[j] = data[i];
            resultat[j+1] = data[i+1];
            resultat[j+2] = data[i+2];



        }
    }
    return resultat;

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
        unsigned char* data = this->GetData();
        data = pileRetour.top();
        pileRetour.pop();
}
void MyImage::AddToPileRetour(){
        unsigned char* data = this->GetData();
        pileRetour.push(data);
}

void MyImage::permut(int i , int x){
    int sauv ;
    sauv = i;
    i = x ;
    x = sauv;
}
