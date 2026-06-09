#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;

public:
    CutSphere(int xcenter,int ycenter,
              int zcenter,int radius);

    void draw(Sculptor &t);
};

#endif