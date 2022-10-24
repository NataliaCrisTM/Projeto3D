#include <iostream>
#include <sculptor.h>
#include <voxel.h>

using namespace std;

int main() {    

    Sculptor cubos(51,51,51);
    cubos.setColor(0.9686274509803922, 0.43137254901960786, 0, 0.2);
    cubos.putBox(0,51,0,51,0,51);
    cubos.cutBox(19,31,25,51,19,31);
    cubos.setColor(0,0,1,1);
    cubos.putBox(19,31,25,51,19,31);
    cubos.writeOFF("cubos.off");


    Sculptor trono(10,10,10);
    trono.setColor(0,1,0,1.0);
    trono.putBox(0,9,0,9,0,9);
    trono.cutBox(1,8,1,9,1,9);
    trono.writeOFF("trono.off");

    Sculptor Cubo(10,10,10);
    Cubo.setColor(1,0,0,1);
    Cubo.putBox(0,9,0,9,0,9);
    Cubo.writeOFF("cubo.off");


    Sculptor elipse(25,25,25);
    elipse.setColor(1,1,0,1);
    elipse.putEllipsoid(12,12,12,5,5,5);
    elipse.writeOFF("elipse.off");

    Sculptor esfera(13,13,13);
    esfera.setColor(0,0,0,1);
    esfera.putSphere(6,6,6,4);
    esfera.writeOFF("esfera.off");

}
