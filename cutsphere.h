#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class CutSphere:FiguraGeometrica
{
public:
    CutSphere(int x0, int y0, int z0, int raio);
    void draw(Sculptor &t);

private:
    int raio;
};

#endif // CUTSPHERE_H
