#include <iostream>
#include <fstream>
#include "sculptor.h"
#include "voxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    if(argc!=2){
        cout<<"precisa passar argumento"<<std::endl;
        return 1;
    }

    int nx, ny, nz;
    float r, g, b, a;

    std::ifstream fin;

      fin.open(argv[1]);

      if(!fin.is_open()){
        std::cout << "nao abriu arquivo figura\n";
        exit(EXIT_FAILURE);
      }

      std::string s;
      fin >> s;

      cout<<"li " << s << std::endl;

      if(s.compare("dim")!=0){
          cout<<"A primeira linha deve ser dim"<<std::endl;
          return 1;
      }
      fin >> nx >> ny >> nz;

      Sculptor t(nx, ny, nz);

      while(fin.good()){
          // processa a linha
          fin >> s;

          cout<<"li " << s << std::endl;

          if(!fin.good())
            break;

          if(s.compare("putvoxel")==0){
                int x0, y0, z0;
                fin >> x0 >> y0 >>z0;
                fin >> r >> g >> b >>a;
                PutVoxel(x0,y0,z0,r,g,b,a).draw(t);
              }
          if(s.compare("cutvoxel")==0){
                int x0, y0,z0;
                fin >> x0 >> y0 >>z0;
                CutVoxel(x0,y0,z0).draw(t);
              }
          if(s.compare("putbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    fin >> x0 >> x1 >>y0 >> y1 >> z0 >> z1;
                    fin >> r >> g >> b >>a;
                    PutBox(x0,x1,y0,y1, z0, z1,r,g,b,a).draw(t);
              }
          if(s.compare("cutbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    fin >> x0 >> x1 >>y0 >> y1 >> z0 >> z1;
                    CutBox(x0,x1,y0,y1, z0, z1).draw(t);
              }
          if(s.compare("putsphere")==0){
                    int x0, y0, z0, raio;
                    fin >> x0 >> y0 >>z0 >>raio;
                    fin >> r >> g >> b >>a;
                    PutSphere(x0,y0,z0, raio, r,g,b,a).draw(t);
              }
          if(s.compare("cutsphere")==0){
                    int x0, y0, z0, raio;
                    fin >> x0 >> y0 >>z0 >>raio;
                    CutSphere(x0,y0,z0, raio).draw(t);
              }
          if(s.compare("putellipsoid")==0){
                    int x0, y0, z0, raiox, raioy, raioz;
                    fin >> x0 >> y0 >>z0 >>raiox >>raioy>>raioz;
                    fin >> r >> g >> b >>a;
                    PutEllipsoid(x0,y0,z0, raiox,raioy, raioz, r,g,b,a).draw(t);
              }
          if(s.compare("cutellipsoid")==0){
                    int x0, y0, z0, raiox, raioy, raioz;
                    fin >> x0 >> y0 >>z0 >>raiox >>raioy>>raioz;
                    CutEllipsoid(x0,y0,z0, raiox,raioy, raioz).draw(t);
              }
      }

      t.writeOFF("teste1.off");
}
