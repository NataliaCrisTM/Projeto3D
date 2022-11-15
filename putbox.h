#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"


class PutBox:FiguraGeometrica
{
public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1,
           float r, float g, float b, float a);

    void draw(Sculptor &t);

private:
    int x1, y1, z1;
};

#endif // PUTBOX_H
