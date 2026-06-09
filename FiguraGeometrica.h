#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Sculptor.h"

class FiguraGeometrica{
public:
    virtual void draw(Sculptor &t)=0;
    virtual ~FiguraGeometrica(){}
};

#endif