#include "DtEmpleado.h"

DtEmpleado::DtEmpleado(int numero, string nombre){
    this->numero = numero;
    this->nombre = nombre;
}

DtEmpleado::~DtEmpleado(){

}

int DtEmpleado::getNumero(){
    return this->numero;
}

void DtEmpleado::setNombre(string nombre1){
    this->nombre= nombre1;
}

void DtEmpleado::setNumero(int numero1){
    this->numero=numero1;
}


string DtEmpleado::getNombre(){
    return this->nombre;
}