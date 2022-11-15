#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"



class PutVoxel:FiguraGeometrica
{
public:
    PutVoxel(int x0, int y0, int z0, float r,
             float g, float b, float a);

    void draw(Sculptor &t);
};


#endif // PUTVOXEL_H
