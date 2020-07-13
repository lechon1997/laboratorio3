#include "Mozo.h"
#include "ListaDicc.h"

Mozo::Mozo(int numero,string nombre):Empleado(numero,nombre){
    this->mezas = new ListDicc;
}

Mozo::~Mozo(){

}

void Mozo::setMesas(Mesa* m,KeyInt* k){
    this->mezas->add(m,k);
}

DtMozo* Mozo::toDTMozo(){
    DtMozo* dt = new DtMozo(this->getNumero(),this->getNombre());
    dt->setMesas(this->mezas);
   // dt->setNombre(this->getNombre());
   // dt->setNumero(this->getNumero());
    
    return dt;
}


IDictionary* Mozo::getMesas(){
    return this->mezas;
}