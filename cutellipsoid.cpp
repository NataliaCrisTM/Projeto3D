#include "cutellipsoid.h"
#include <math.h>

CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz)
{
    this->x0=x0;
    this->y0=y0;
    this->z0=z0;
    this->raiox=raiox;
    this->raioy=raioy;
    this->raioz=raioz;
}

void CutEllipsoid::draw(Sculptor &t){
    for(int i = 0; i < t.getnx(); i++){
        for(int j = 0; j < t.getny(); j++){
            for(int k = 0; k < t.getnz(); k++){
                auto soma = pow((i - x0) / raiox, 2) + pow((j - y0) / raioy, 2) + pow((k - z0) / raioz, 2);
                if (soma <= 1) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
