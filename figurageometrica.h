#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class FiguraGeometrica
{
protected:
    int x0, y0, z0;
    float r, g, b, a;


public:
    FiguraGeometrica();



    virtual void draw(Sculptor &t)=0;



};

#endif // FIGURAGEOMETRICA_H
