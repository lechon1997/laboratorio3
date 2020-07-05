#include "DtInfoP.h"

DtInfoP::DtInfoP(string codigo, int cantidad){
    this->codigo = codigo;
    this->cantidad = cantidad;
}

DtInfoP::~DtInfoP(){

}

string DtInfoP::getCodigo(){
    return this->codigo;
}

int DtInfoP::getCantidad(){
    return this->cantidad;
}