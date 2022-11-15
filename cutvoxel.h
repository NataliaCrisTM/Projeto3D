#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

class CutVoxel:FiguraGeometrica
{
public:
    CutVoxel(int x0, int y0, int z0);
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
