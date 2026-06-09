#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "FiguraGeometrica.h"

class CutVoxel : public FiguraGeometrica{
private:
    int x,y,z;

public:
    CutVoxel(int x,int y,int z);

    void draw(Sculptor &t);
};

#endif