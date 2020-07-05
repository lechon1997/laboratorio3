#include "Empleado.h"

Empleado::Empleado(int numero, string nombre){
    this->numero = numero;
    this->nombre = nombre;
}

Empleado::~Empleado(){

}

int Empleado::getNumero(){
    return this->numero;
}