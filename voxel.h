#ifndef VOXEL_H
#define VOXEL_H

struct Voxel {
  float r,g,b; // Colors
  float a; // Transparency
  bool isOn; // Included or not

  Voxel();

  void setColor(float _r, float _g, float _b, float _a);
};

#endif // VOXEL_H
