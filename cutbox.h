#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class CutBox:FiguraGeometrica
{
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void draw(Sculptor &t);
private:
    int x1, y1, z1;
};

#endif // CUTBOX_H
