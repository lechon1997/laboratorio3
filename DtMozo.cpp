#include "DtMOZO.h"
#include "ListaDicc.h"

DtMozo::DtMozo(int numero,string nombre):DtEmpleado(numero,nombre){
    this->mezas = new ListDicc;
}

DtMozo::~DtMozo(){

}

void DtMozo::setMesas(IDictionary* mesas1){
 this->mezas=mesas1;   
}

IDictionary* DtMozo::getMesas(){
    return this->mezas;
}