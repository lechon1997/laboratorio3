#include "DtMenu.h"

DtMenu::DtMenu(string codigo, string descripcion, float precio, ICollection* productos){
    this->codigo = codigo;
    this->descripcio = descripcion;
    this->precio = precio;
    this->infoProductos = productos;
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

ICollection* DtMenu::getDatosProductos(){
    return this->getDatosProductos();
}