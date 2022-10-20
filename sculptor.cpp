#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{

    nx = _nx;
    ny = _ny;
    nz - _nz;

    v =  malloc(nx * sizeof(Voxel**));
    v[0] = malloc(nx * ny * sizeof(Voxel*));
    v[0][0] = malloc(nx * ny * nz * sizeof(Voxel));

    for(int i = 1; i < nx; i++) {
         v[i] = v[i - 1] + nY;
               }

    for(int i = 0; i < nx; i++) {
         if (i != 0) {
            v[i][0] = v[i - 1][ny - 1] + nz;
               }
    for(int j = 1; j < ny; j++) {
            v[i][j] = v[i][j - 1] + nz;
                   }
               }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k] = Voxel();
            }
        }
    }

}

Sculptor::~Sculptor(int _nx, int _ny, int _nz){
     free(v[0][0]);
     free(v[0]);
     free(v);

}

void Sculptor::setColor(float r, float g, float b, float a){

    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;


}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].setColor(r, g, b, a);
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; j<y1; j++){
            for(int k = z0; k<z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1; i++){
        for(int j = y0; j<y1; j++){
            for(int k = z0; k<z1; k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

}

void Sculptor::writeOFF(const char* filename){

}

