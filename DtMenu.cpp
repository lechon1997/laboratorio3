#include "DtMenu.h"

DtMenu::DtMenu(string codigo, string descripcion, float precio, ICollection* productos){
    this->codigo = codigo;
    this->descripcio = descripcion;
    this->precio = precio;
    this->cantidadVend = 0;
    this->infoProductos = productos;
    this->dtinfosp = NULL;
}
DtMenu::DtMenu(string codigo, string descripcion, float precio,int cantidadVend, ICollection* productos,IDictionary* dts){
    this->codigo = codigo;
    this->descripcio = descripcion;
    this->precio = precio;
    this->cantidadVend = cantidadVend;
    this->infoProductos = productos;
    this->dtinfosp = dts;
}

DtMenu::~DtMenu(){

}

string DtMenu::getCodigo(){
    return this->codigo;
}

float DtMenu::getPrecio(){
    return this->precio;
}

string DtMenu::getDescripcion(){
    return this->descripcio;
}

int DtMenu::getCantidadVend(){
    return this->cantidadVend;
}

ICollection* DtMenu::getDatosProductos(){
    return this->getDatosProductos();
}

IDictionary* DtMenu::getDtInfosP(){
    return this->dtinfosp;
}