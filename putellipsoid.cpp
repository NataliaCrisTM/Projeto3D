#include "putellipsoid.h"
#include <math.h>

PutEllipsoid::PutEllipsoid(int x0, int y0, int z0,
                           int raiox, int raioy, int raioz,
                           float r, float g, float b, float a)
{
    this->x0=x0;
    this->y0=y0;
    this->z0=z0;
    this->raiox=raiox;
    this->raioy=raioy;
    this->raioz=raioz;

    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;

}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i = 0; i < t.getnx(); i++){
        for(int j = 0; j < t.getny(); j++){
            for(int k = 0; k < t.getnz(); k++){
                auto soma = pow((i - x0) / raiox, 2) + pow((j - y0) / raioy, 2) + pow((k - z0) / raioz, 2);
                if (soma <= 1) {
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}
