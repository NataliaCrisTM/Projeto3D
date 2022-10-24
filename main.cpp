#include <iostream>
#include <sculptor.h>
#include <voxel.h>

using namespace std;

int main() {

    Sculptor trono(10,10,10);
    trono.setColor(0,0,1.0,1.0);
    trono.cutBox(1,8,1,9,1,9);
    trono.writeOFF("trono.off");

    Sculptor cubos(51,51,51);
    cubos.setColor(0.9686274509803922, 0.43137254901960786, 0, 0.2);
    cubos.putBox(0,51,0,51,0,51);
    cubos.cutBox(19,31,25,51,19,31);
    cubos.setColor(0,0,1,1);
    cubos.putBox(19,31,25,51,19,31);
    cubos.writeOFF("cubos.off");





}
