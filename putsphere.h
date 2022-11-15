#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere:FiguraGeometrica
{
public:
    PutSphere(int x0, int y0, int z0, int raio,
              float r, float g, float b, float a);

    void draw(Sculptor &t);

private:
    int raio;
};

#endif // PUTSPHERE_H
