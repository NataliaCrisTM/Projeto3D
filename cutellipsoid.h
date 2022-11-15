#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

class CutEllipsoid:FiguraGeometrica
{
public:
    CutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz);
    void draw(Sculptor &t);

private:
    int raiox, raioy, raioz;
};


#endif // CUTELLIPSOID_H
