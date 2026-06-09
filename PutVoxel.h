#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"

class PutVoxel : public FiguraGeometrica{
private:
    int x,y,z;
    float r,g,b,a;

public:
    PutVoxel(int x,int y,int z,
             float r,float g,float b,float a);

    void draw(Sculptor &t);
};

#endif