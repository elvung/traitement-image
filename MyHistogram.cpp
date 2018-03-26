#include "MyHistogram.hpp"

MyHistogram::MyHistogram(MyImage *_image):
    m_image(_image){

    MyImage *test = new MyImage();
    *test = m_image->Copy();
    test->Desaturate();

    unsigned char* data = test->GetData();
    int taille = test->GetHeight()*test->GetWidth()*3;

    }
