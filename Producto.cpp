#include "Producto.h"

Producto::Producto(string codigo, string descripcion){
    this->codigo=codigo;
    this->descripcion=descripcion;
}

Producto::~Producto(){

}

string Producto::getCodigo(){
    return this->codigo;
}

string Producto::getDescripcion(){
    return this->descripcion;
}