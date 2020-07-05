#include "Repartidor.h"

Repartidor::Repartidor(int numero, string nombre,Transportes tipo):Empleado(numero,nombre){
    this->miAltaNave = tipo;
}

Repartidor::~Repartidor(){

}

string Repartidor::getNombre(){
    return this->getNombre();
}