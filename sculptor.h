#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <fstream>
#include <iomanip>
#include <math.h>
#include "voxel.h"

class Sculptor
{
private:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float r, float g, float b, float a);
  int getnx();
  int getny();
  int getnz();
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
