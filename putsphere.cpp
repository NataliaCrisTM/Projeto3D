#include "putsphere.h"
#include <math.h>

PutSphere::PutSphere(int x0, int y0, int z0, int raio,
                     float r, float g, float b, float a)
{
    this->x0=x0;
    this->y0=y0;
    this->z0=z0;
    this->raio=raio;

    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;

}

void PutSphere::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    for(int i = 0; i < t.getnx(); i++){
        for(int j = 0; j < t.getny(); j++){
            for(int k = 0; k < t.getnz(); k++){
                auto soma = pow(i - x0, 2) + pow(j - y0, 2) + pow(k - z0, 2);
                if (soma <= pow(raio, 2)) {
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}
