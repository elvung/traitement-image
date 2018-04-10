#include "MyHistogram.hpp"

MyHistogram::MyHistogram(MyImage *_image):
m_image(_image){

    MyImage *test = new MyImage();
    *test = m_image->Copy();
    test->Desaturate();
    grey.fill(0);
    unsigned char* data = test->GetData();
    taille = test->GetHeight()*test->GetWidth()*3;
    for(int i =0; i<taille; i = i+3){
        grey[data[i]]++;
    }



}

void MyHistogram::GetBorderValues(int *minValue, int *maxValue){



    int min = taille;
    int max = 0;
    for(int i =0; i<grey.size(); i++){
        if (grey[i] > max){
            max = grey[i];
            *maxValue = i;
        }if ((grey[i] < min) && (grey[i] > 0)){
            min = grey[i];
            *minValue = i;

        }
    }
    wxString myString;
    myString << *maxValue;
    //wxLogMessage(myString);

}


