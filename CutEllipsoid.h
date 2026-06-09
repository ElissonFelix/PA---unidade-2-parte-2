#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"

class CutEllipsoid : public FiguraGeometrica{
private:
    int xcenter,ycenter,zcenter;
    int rx,ry,rz;

public:
    CutEllipsoid(int xcenter,int ycenter,int zcenter,
                 int rx,int ry,int rz);

    void draw(Sculptor &t);
};

#endif