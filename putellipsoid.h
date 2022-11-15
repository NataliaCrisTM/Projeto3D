#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class PutEllipsoid:FiguraGeometrica
{
public:
    PutEllipsoid(int x0, int y0, int z0,
                 int raiox, int raioy, int raioz,
                 float r, float g, float b, float a);

    void draw(Sculptor &t);

private:
    int raiox, raioy, raioz;
};

#endif // PUTELLIPSOID_H
