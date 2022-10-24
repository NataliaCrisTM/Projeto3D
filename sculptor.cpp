#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{

    nx = _nx;
    ny = _ny;
    nz = _nz;

    v =  new Voxel**[nx];
    v[0] = new Voxel*[nx * ny];
    v[0][0] = new Voxel[nx * ny * nz];

    for(int i = 1; i < nx; i++) {
        v[i] = v[i - 1] + ny;
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

Sculptor::~Sculptor(){
    delete[] (v[0][0]);
    delete[] (v[0]);
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a){

    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;


}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r=r;
    v[x][y][z].g=g;
    v[x][y][z].b=b;
    v[x][y][z].a=a;




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
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                auto soma = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
                if (soma <= pow(radius, 2)) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                auto soma = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
                if (soma <= pow(radius, 2)) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                auto soma = pow((i - xcenter) / rx, 2) + pow((j - ycenter) / ry, 2) + pow((k - zcenter) / rz, 2);
                if (soma <= 1) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                auto soma = pow((i - xcenter) / rx, 2) + pow((j - ycenter) / ry, 2) + pow((k - zcenter) / rz, 2);
                if (soma <= 1) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){
    std::ofstream fout(filename);

    fout << std::fixed;
    fout << std::setprecision(2);

    fout << "OFF" << std::endl;

    auto nVoxels = nx * ny * nz;
    fout << 8 * nVoxels << ' ' << 6 * nVoxels << " 0" << std::endl;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                fout << i - 0.5 << ' ' << j + 0.5 << ' ' << k - 0.5 << std::endl;
                fout << i - 0.5 << ' ' << j - 0.5 << ' ' << k - 0.5 << std::endl;
                fout << i + 0.5 << ' ' << j - 0.5 << ' ' << k - 0.5 << std::endl;
                fout << i + 0.5 << ' ' << j + 0.5 << ' ' << k - 0.5 << std::endl;
                fout << i - 0.5 << ' ' << j + 0.5 << ' ' << k + 0.5 << std::endl;
                fout << i - 0.5 << ' ' << j - 0.5 << ' ' << k + 0.5 << std::endl;
                fout << i + 0.5 << ' ' << j - 0.5 << ' ' << k + 0.5 << std::endl;
                fout << i + 0.5 << ' ' << j + 0.5 << ' ' << k + 0.5 << std::endl;
            }
        }
    }
    auto desloc = 0;
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].isOn) {
                    fout << "4 " << desloc << ' ' << desloc + 3 << ' ' << desloc + 2 << ' ' << desloc + 1 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << std::endl;
                    fout << "4 " << desloc + 4 << ' ' << desloc + 5 << ' ' << desloc + 6 << ' ' << desloc + 7 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << std::endl;
                    fout << "4 " << desloc << ' ' << desloc + 1 << ' ' << desloc + 5 << ' ' << desloc + 4 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << std::endl;
                    fout << "4 " << desloc << ' ' << desloc + 4 << ' ' << desloc + 7 << ' ' << desloc + 3 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << std::endl;
                    fout << "4 " << desloc + 3 << ' ' << desloc + 7 << ' ' << desloc + 6 << ' ' << desloc + 2 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << std::endl;
                    fout << "4 " << desloc + 1 << ' ' << desloc + 2 << ' ' << desloc + 6 << ' ' << desloc + 5 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << std::endl;
                }

                desloc += 8;
            }
        }
    }
}

