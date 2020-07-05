#include "Comun.h"

Comun::Comun(string codigo, string descripcion, float precio):Producto(codigo,descripcion){
    this->precio=precio;
}

Comun::~Comun(){
}

float Comun::getPrecio(){
    return this->precio;
}

DtProducto* Comun::getDatosProducto(){
    DtProducto* p = new DtProducto(this->getCodigo(),this->getDescripcion(),this->getPrecio());
    return p;
}

DtInfoP* Comun::obtenerInfoP(int cantidad){
    DtInfoP* dtinfop = new DtInfoP(this->getCodigo(),cantidad);
    return dtinfop;
}