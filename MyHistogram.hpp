#ifndef MYHISTOGRAM_H
#define MYHISTOGRAM_H
#include "MyImage.h"
#include <array>

class MyHistogram {
private:
    MyImage *m_image;
    std::array <int,255> grey;
    int taille;

public:
    MyHistogram(MyImage *_image);
    void GetBorderValues(int *minValue, int *maxValue);
};


#endif // MYHISTOGRAM_H
