#include "Mozo.h"
#include "ListaDicc.h"

Mozo::Mozo(int numero,string nombre):Empleado(numero,nombre){
    this->mezas = new ListDicc;
}

Mozo::~Mozo(){

}

string Mozo::getNombre(){
    return this->getNombre();
}