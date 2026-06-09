#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FiguraGeometrica.h"

class PutSphere : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;

    float r,g,b,a;

public:
    PutSphere(int xcenter,int ycenter,
              int zcenter,int radius,
              float r,float g,float b,float a);

    void draw(Sculptor &t);
};

#endif