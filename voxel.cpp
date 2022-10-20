#include "voxel.h"

Voxel::Voxel(){

    r = 0,g = 0,b = 0; // Colors
    a = 0;
    isOn = false;
}

void Voxel::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;

    isOn = true;

}
