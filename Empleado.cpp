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

string Empleado::getNombre(){
    return this->nombre;
}

bool Empleado::getTipo(){
    return this->tipo;
}

void Empleado::setTipo(bool t){
    this->tipo=t;
}