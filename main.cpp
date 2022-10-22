#include <iostream>
#include <sculptor.h>
#include <voxel.h>

using namespace std;

int main() {
    // cria um escultor cuja matriz tem 10x10x10 voxels
    Sculptor trono(10,10,10);
    // para mudar a cor do voxel
    trono.setColor(0,0,1.0,1.0); // azul
                                 // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    trono.putBox(0,9,0,9,0,9);
    // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    trono.cutBox(1,8,1,9,1,9);
    // grava a escultura digital no arquivo "trono.off"
    trono.writeOFF("trono.off");



    Sculptor elipise(11,11,11);
    elipise.setColor(1,0,0,1);
    elipise.putEllipsoid(5, 5, 5, 3, 4, 2);
    elipise.writeOFF("elipise.off");

    Sculptor esfera(19,19,19);
    esfera.setColor(0,1,0,1);
    esfera.putSphere(9,9,9,5);
    esfera.writeOFF("esfera.off");

    Sculptor Sara(51,51,51);
    Sara.setColor(0.9686274509803922, 0.43137254901960786, 0, 0.6);
    Sara.putSphere(25, 25, 25, 25);
    Sara.cutBox(15, 35, 25, 50, 15, 35);
    Sara.writeOFF("sara.off");

    Sculptor cubos(51,51,51);
    Sara.setColor(0.9686274509803922, 0.43137254901960786, 0, 0.2);
    Sara.putBox(0,51,0,51,0,51);
    Sara.cutBox(19,31,25,51,19,31);
    Sara.setColor(0,0,1,1);
    Sara.putBox(19,31,25,51,19,31);
    Sara.writeOFF("cubos.off");
}
